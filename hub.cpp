#include "hub.h"

Hub::Hub(HubWidget *hubWidget, Firefighter *firefighter, QObject *parent)
    : QObject(parent), hubWidget(hubWidget), firefighter(firefighter), archive(new Archive(this)), shop(new Shop(this)) {
    connect(hubWidget, &HubWidget::buttonClicked, this, &Hub::onButtonClicked);
    connect(hubWidget, &HubWidget::bookButtonClicked, this, &Hub::onBookButtonClicked);
    connect(hubWidget, &HubWidget::shopItemButtonClicked, this, &Hub::onShopItemButtonClicked);

    // Dodajemy przykładowe przedmioty do sklepu
    shop->addItem(Item("Helmet", "Protective helmet", 50.0));
    shop->addItem(Item("Fireproof Jacket", "Protective fireproof jacket", 120.0));
    shop->addItem(Item("Boots", "Protective boots", 80.0));
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
    auto items = shop->getItems();
    if (index >= 0 && index < items.size()) {
        QString content = QString("Description: %1\nPrice: %2").arg(items[index].getDescription()).arg(items[index].getPrice());
        hubWidget->showMessageBox(items[index].getName(), content);
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

void Hub::createShopItemButtons() {
    auto items = shop->getItems();
    hubWidget->clearShopItemButtons();
    for (int i = 0; i < items.size(); ++i) {
        hubWidget->addShopItemButton(items[i].getName(), i);
    }
}
