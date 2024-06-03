#include "hubwidget.h"
#include <QVBoxLayout>
#include <QSpacerItem>

HubWidget::HubWidget(QWidget *parent) : QWidget(parent) {
    messageLabel = new QLabel(this);
    messageLabel->setAlignment(Qt::AlignCenter);
    messageLabel->setFixedSize(500, 150);
    messageLabel->setWordWrap(true);
    messageLabel->setStyleSheet("font-size: 24px; font-weight: bold;");

    captainButton = new QPushButton("Kapitan Straży", this);
    shopkeeperButton = new QPushButton("Sklepikarz", this);
    archivistButton = new QPushButton("Archiwista", this);
    nextMissionButton = new QPushButton("Rozpocznij kolejną misję", this);
    returnButton = new QPushButton("Wróć", this);
    showArchivesButton = new QPushButton("Pokaż archiwum", this);

    captainButton->setFixedSize(200, 50);
    shopkeeperButton->setFixedSize(200, 50);
    archivistButton->setFixedSize(200, 50);
    nextMissionButton->setFixedSize(200, 50);
    returnButton->setFixedSize(200, 50);
    showArchivesButton->setFixedSize(200, 50);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
    layout->addWidget(messageLabel, 0, Qt::AlignCenter);
    layout->addWidget(captainButton, 0, Qt::AlignCenter);
    layout->addWidget(shopkeeperButton, 0, Qt::AlignCenter);
    layout->addWidget(archivistButton, 0, Qt::AlignCenter);
    layout->addWidget(nextMissionButton, 0, Qt::AlignCenter);
    layout->addWidget(returnButton, 0, Qt::AlignCenter);
    layout->addWidget(showArchivesButton, 0, Qt::AlignCenter);
    layout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
    setLayout(layout);

    nextMissionButton->hide();
    returnButton->hide();
    showArchivesButton->hide();

    connect(captainButton, &QPushButton::clicked, this, &HubWidget::captainButtonClicked);
    connect(shopkeeperButton, &QPushButton::clicked, this, &HubWidget::shopkeeperButtonClicked);
    connect(archivistButton, &QPushButton::clicked, this, &HubWidget::archivistButtonClicked);
    connect(nextMissionButton, &QPushButton::clicked, this, &HubWidget::nextMissionConfirmed);
    connect(returnButton, &QPushButton::clicked, this, &HubWidget::returnToHub);
    connect(showArchivesButton, &QPushButton::clicked, this, &HubWidget::showArchives);
}

void HubWidget::showCompletionMessage(const QString &message) {
    messageLabel->setText(message);
}

void HubWidget::showConfirmationMessage(const QString &message) {
    messageLabel->setText(message);
}

void HubWidget::showInsufficientLevelMessage(const QString &message) {
    messageLabel->setText(message);
    returnButton->show();
    showArchivesButton->hide();
    nextMissionButton->hide();
}

void HubWidget::showArchivistOptions() {
    messageLabel->setText("Witam w archiwum");
    returnButton->show();
    showArchivesButton->show();
    nextMissionButton->hide();
}

void HubWidget::showConfirmationButtons() {
    nextMissionButton->show();
    returnButton->show();
    hideMainButtons();
}

void HubWidget::hideConfirmationButtons() {
    nextMissionButton->hide();
    returnButton->hide();
    showMainButtons();
}

void HubWidget::showReturnButton() {
    returnButton->show();
}

void HubWidget::hideReturnButton() {
    returnButton->hide();
}

void HubWidget::hideMainButtons() {
    captainButton->hide();
    shopkeeperButton->hide();
    archivistButton->hide();
}

void HubWidget::showMainButtons() {
    captainButton->show();
    shopkeeperButton->show();
    archivistButton->show();
}

void HubWidget::hideArchivesButton() {
    showArchivesButton->hide();
}
