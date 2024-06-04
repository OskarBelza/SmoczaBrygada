#include "hub.h"

Hub::Hub(HubWidget *hubWidget, Firefighter *firefighter, QObject *parent)
    : QObject(parent), hubWidget(hubWidget), firefighter(firefighter), archive(new Archive(this)), shop(new Shop(this)) {
    connect(hubWidget, &HubWidget::buttonClicked, this, &Hub::onButtonClicked);
    connect(hubWidget, &HubWidget::bookButtonClicked, this, &Hub::onBookButtonClicked);
    connect(hubWidget, &HubWidget::shopItemButtonClicked, this, &Hub::onShopItemButtonClicked);

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

#include "hub.h"

void Hub::onShopItemButtonClicked(int index) {
    auto items = shop->getTools();
    if (index >= 0 && index < items.size()) {
        int playerMoney = firefighter->getMoney();
        int itemPrice = items[index].getPrice();

        if (playerMoney >= itemPrice) {
            firefighter->setMoney(playerMoney - itemPrice);
            firefighter->getInventory()->addTool(items[index]);
            QString successMessage = QString("Pomyślnie zakupiono: %1").arg(items[index].getName());
            hubWidget->showMessageBox("Zakup udany", successMessage);
        } else {
            hubWidget->showMessageBox("Za mało pieniędzy", "Nie masz wystarczająco dużo pieniędzy, aby kupić ten przedmiot.");
        }
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

