#include "hub.h"

Hub::Hub(HubWidget *hubWidget, Firefighter *firefighter, QObject *parent)
    : QObject(parent), hubWidget(hubWidget), firefighter(firefighter) {
    connect(hubWidget, &HubWidget::captainButtonClicked, this, &Hub::onCaptainButtonClicked);
    connect(hubWidget, &HubWidget::shopkeeperButtonClicked, this, &Hub::onShopkeeperButtonClicked);
    connect(hubWidget, &HubWidget::archivistButtonClicked, this, &Hub::onArchivistButtonClicked);
    connect(hubWidget, &HubWidget::nextMissionConfirmed, this, &Hub::onNextMissionConfirmed);
    connect(hubWidget, &HubWidget::returnToHub, this, &Hub::onReturnToHub);
}

void Hub::onCaptainButtonClicked() {
    hubWidget->showConfirmationMessage("Czy chcesz wyruszyć na kolejną misję?");
    hubWidget->showConfirmationButtons();
}

void Hub::onShopkeeperButtonClicked() {
    hubWidget->hideMainButtons();
    hubWidget->showCompletionMessage("Witam w sklepie.");
    hubWidget->showReturnButton();
    emit showShopkeeper();
}

void Hub::onArchivistButtonClicked() {
    checkArchivistAccess();
}

void Hub::onNextMissionConfirmed() {
    emit startNextMission();
}

void Hub::onReturnToHub() {
    hubWidget->hideReturnButton();
    hubWidget->hideArchivesButton(); // Ukrywanie przycisku "Pokaż archiwum"
    hubWidget->showMainButtons();
    emit showHub();
}

void Hub::checkArchivistAccess() {
    hubWidget->hideMainButtons();
    if (firefighter->getLevel() < 3) {
        hubWidget->showInsufficientLevelMessage("Za niski poziom, aby uzyskać dostęp do archiwum.");
    } else {
        hubWidget->showArchivistOptions();
    }
}
