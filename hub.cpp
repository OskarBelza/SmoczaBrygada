#include "hub.h"

Hub::Hub(HubWidget *hubWidget, Firefighter *firefighter, QObject *parent)
    : QObject(parent), hubWidget(hubWidget), firefighter(firefighter), archive(new Archive(this)), shop(new Shop(this)) {
    connect(hubWidget, &HubWidget::buttonClicked, this, &Hub::onButtonClicked);
    connect(hubWidget, &HubWidget::bookButtonClicked, this, &Hub::onBookButtonClicked);
    connect(hubWidget, &HubWidget::shopItemButtonClicked, this, &Hub::onShopItemButtonClicked);
    //connect(hubWidget, &HubWidget::shopItemRightClicked, this, &Hub::onShopItemRightClicked);

    shop->addTool(Tools("Bomba wodna", 60, 1, 2, "Mocna broń przeciwko smokom", true, 100));
    shop->addTool(Tools("Bomba wodna", 60, 1, 2, "Mocna broń przeciwko smokom", true, 100));
    shop->addTool(Tools("Bomba wodna", 60, 1, 2, "Mocna broń przeciwko smokom", true, 100));
}

void Hub::onButtonClicked(const QString &buttonName) {
    if (buttonName == "captainButton") {
        hubWidget->showConfirmationMessage("Czy chcesz wyruszyć na kolejną misję?");
        hubWidget->showConfirmationButtons();
    } else if (buttonName == "shopkeeperButton") {
        hubWidget->setButtonVisibility("captainButton", false);
        hubWidget->setButtonVisibility("shopkeeperButton", false);
        hubWidget->setButtonVisibility("archivistButton", false);
        hubWidget->showCompletionMessage("Witam w sklepie.");
        hubWidget->setButtonVisibility("returnButton", true);
        createShopItemButtons();
        emit showShopkeeper();
    } else if (buttonName == "archivistButton") {
        checkArchivistAccess();
    } else if (buttonName == "nextMissionButton") {
        emit startNextMission();
    } else if (buttonName == "returnButton") {
        hubWidget->setButtonVisibility("returnButton", false);
        hubWidget->setButtonVisibility("showArchivesButton", false);
        hubWidget->setButtonVisibility("captainButton", true);
        hubWidget->setButtonVisibility("shopkeeperButton", true);
        hubWidget->setButtonVisibility("archivistButton", true);
        hubWidget->clearBookButtons();
        hubWidget->clearShopItemButtons();
        emit showHub();
    } else if (buttonName == "showArchivesButton") {
        auto books = archive->getBooks();
        hubWidget->clearBookButtons();
        for (int i = 0; i < books.size(); ++i) {
            hubWidget->addBookButton(books[i].getTitle(), i);
        }
        hubWidget->setButtonVisibility("showArchivesButton", false);
        hubWidget->setButtonVisibility("returnButton", true);
    }
}

void Hub::onBookButtonClicked(int index) {
    auto books = archive->getBooks();
    if (index >= 0 && index < books.size()) {
        hubWidget->showMessageBox(books[index].getTitle(), books[index].getContent());
    }
}

void Hub::onShopItemButtonClicked(int index) {
    auto items = shop->getTools();
    if (index >= 0 && index < items.size()) {
        QString content = QString("Description: %1\nPrice: %2").arg(items[index].getDescription()).arg(items[index].getPrice());
        hubWidget->showMessageBox(items[index].getName(), content);
    }
}

void Hub::createShopItemButtons() {
    auto items = shop->getTools();
    qDebug() << "Creating shop item buttons. Number of items:" << items.size();
    hubWidget->clearShopItemButtons();
    for (int i = 0; i < items.size(); ++i) {
        qDebug() << "Adding shop item button:" << items[i].getName();
        hubWidget->addShopItemButton(items[i].getName(), i);
    }
}

// void Hub::onShopItemRightClicked(int index) {
//     if (!firefighter || !hubWidget || !shop) {
//         qDebug() << "Null pointer detected!";
//         return;
//     }

//     auto &items = shop->getTools();
//     if (index >= 0 && index < items.size()) {
//         Tools &item = items[index];  // Use reference to the item
//         qDebug() << "Right-clicked item:" << item.getName();
//         int price = item.getPrice();
//         if (firefighter->getMoney() >= price) {
//             firefighter->getInventory()->addTool(item);
//             hubWidget->showMessageBox("Zakup udany", QString("Zakupiłeś %1 za %2 złota.").arg(item.getName()).arg(price));
//         } else {
//             hubWidget->showMessageBox("Brak złota", "Nie masz wystarczającej ilości złota, aby kupić ten przedmiot.");
//         }
//     } else {
//         qDebug() << "Invalid index:" << index;
//     }
// }

void Hub::checkArchivistAccess() {
    hubWidget->setButtonVisibility("captainButton", false);
    hubWidget->setButtonVisibility("shopkeeperButton", false);
    hubWidget->setButtonVisibility("archivistButton", false);
    if (firefighter->getLevel() < 3) {
        hubWidget->showInsufficientLevelMessage("Za niski poziom, aby uzyskać dostęp do archiwum.");
    } else {
        hubWidget->showArchivistOptions();
    }
}

