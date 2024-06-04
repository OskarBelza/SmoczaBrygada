#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "firefighter.h"
#include "game.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , game(new Game)
    , missionWidget(new MissionWidget(this))
    , hubWidget(new HubWidget(this))
    , hub(new Hub(hubWidget, game->getMainCharacter(), this))

{
    ui->setupUi(this);

    setWindowTitle("Witaj w grze!");
    setFixedSize(600, 400);

    ui->titleLabel->setText("Smocza Brygada");
    ui->titleLabel->setAlignment(Qt::AlignCenter);
    ui->titleLabel->setStyleSheet("font-size: 24px; font-weight: bold;");

    ui->newGameButton->setText("Nowa Gra");
    ui->loadGameButton->setText("Wczytaj Grę");
    ui->exitButton->setText("Wyjście");

    connect(ui->newGameButton, &QPushButton::clicked, this, &MainWindow::onNewGameClicked);
    connect(ui->loadGameButton, &QPushButton::clicked, this, &MainWindow::onLoadGameClicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &MainWindow::onExitClicked);

    missionWidget->hide();
    hubWidget->hide();
    setCentralWidget(ui->centralwidget);

    connectMissionSignals(game->getCurrentMission());
    connectHeroSignals();

    updateHeroStats();

    connect(game, &Game::missionCompleted, this, &MainWindow::showCompletionScreen);
    connect(hub, &Hub::startNextMission, this, &MainWindow::startNextMission);
    connect(hub, &Hub::showHub, this, &MainWindow::returnToHub);
}

MainWindow::~MainWindow() {
    delete ui;
    delete game;
    delete missionWidget;
    delete hubWidget;
    delete hub;
}

void MainWindow::onNewGameClicked() {
    showMissionScreen(game->getCurrentMissionDescription());
    game->startNewGame();
    updateHeroStats();
}

void MainWindow::onLoadGameClicked() {
    game->loadGameFromFile();
    updateHeroStats();
}

void MainWindow::onExitClicked() {
    close();
}

void MainWindow::showMissionScreen(const QString &description) {
    missionWidget->setMissionDescription(description);
    missionWidget->show();
    hubWidget->hide();
    setCentralWidget(missionWidget);
}

void MainWindow::showCompletionScreen() {
    missionWidget->hide();
    hubWidget->showCompletionMessage("Brawo! Ukończyłeś misję i wróciłeś do miasta.");
    hubWidget->show();
    setCentralWidget(hubWidget);
}

void MainWindow::startNextMission() {
    Mission* nextMission = game->getCurrentMission();
    if (nextMission) {
        showMissionScreen(nextMission->getDescription());
        nextMission->start();
        updateHeroStats();
    }
}

void MainWindow::connectMissionSignals(Mission* mission) {
    if (mission) {
        connect(mission, &Mission::updateMissionStatus, missionWidget, &MissionWidget::setMissionDescription);
        connect(mission, &Mission::configureButton, missionWidget, &MissionWidget::configureButton);
        connect(mission, &Mission::missionCompleted, this, &MainWindow::showCompletionScreen);
    }
}

void MainWindow::connectHeroSignals() {
    auto firefighter = game->getMainCharacter();
    connect(firefighter, &Firefighter::healthChanged, missionWidget, &MissionWidget::setHeroHealth);
    connect(firefighter, &Firefighter::healthChanged, hubWidget, &HubWidget::setHeroHealth);
    connect(firefighter->getInventory(), &Inventory::inventoryChanged, this, &MainWindow::updateHeroStats);
}

void MainWindow::updateHeroStats() {
    auto firefighter = game->getMainCharacter();
    missionWidget->setHeroHealth(firefighter->getHealth());
    hubWidget->setHeroHealth(firefighter->getHealth());

    QStringList inventory;
    for (const auto& tool : firefighter->getInventory()->getTools()) {
        inventory << QString("%1 (Qty: %2, Level: %3, Firepower: %4, Consumable: %5)")
                         .arg(tool.getName())
                         .arg(tool.getQuantity())
                         .arg(tool.getLevel())
                         .arg(tool.getFirePower())
                         .arg(tool.isConsumable() ? "Yes" : "No");
    }
    missionWidget->setHeroInventory(inventory);
    hubWidget->setHeroInventory(inventory);
}

void MainWindow::returnToHub() {
    hubWidget->hideConfirmationButtons();
    hubWidget->showCompletionMessage("Brawo! Ukończyłeś misję i wróciłeś do miasta.");
}
