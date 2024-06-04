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
    , stackedWidget(new QStackedWidget(this))
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

    stackedWidget->addWidget(ui->centralwidget);
    stackedWidget->addWidget(missionWidget);
    stackedWidget->addWidget(hubWidget);

    setCentralWidget(stackedWidget);

    connectMissionSignals(game->getCurrentMission());
    connectHeroSignals();

    updateHeroStats();

    connect(game, &Game::missionCompleted, this, &MainWindow::showCompletionScreen);
    connect(hub, &Hub::startNextMission, this, &MainWindow::startNextMission);
    connect(hub, &Hub::showHub, this, &MainWindow::returnToHub);
    connect(hub, &Hub::saveGame, this, &MainWindow::saveGame);
}

MainWindow::~MainWindow() {
    delete ui;
    delete game;
    delete missionWidget;
    delete hubWidget;
    delete hub;
}

void MainWindow::saveGame() {
    game->saveGame();
    stackedWidget->setCurrentWidget(ui->centralwidget);
}

void MainWindow::onNewGameClicked() {
    game->startNewGame();
    updateHeroStats();
    showMissionScreen(game->getCurrentMissionDescription());
}

void MainWindow::onLoadGameClicked() {
    game->loadGameFromFile();
    updateHeroStats();
    returnToHub();
}

void MainWindow::onExitClicked() {
    close();
}

void MainWindow::showMissionScreen(const QString &description) {
    missionWidget->setMissionDescription(description);
    stackedWidget->setCurrentWidget(missionWidget);
}

void MainWindow::showCompletionScreen() {
    hubWidget->showCompletionMessage("Brawo! Ukończyłeś misję i wróciłeś do miasta.");
    stackedWidget->setCurrentWidget(hubWidget);
}

void MainWindow::startNextMission() {
    Mission* nextMission = game->getCurrentMission();
    if (nextMission) {
        showMissionScreen(nextMission->getDescription());
        connectMissionSignals(nextMission);
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
    connect(firefighter, &Firefighter::experienceChanged, missionWidget, &MissionWidget::setHeroExperience);
    connect(firefighter, &Firefighter::experienceChanged, hubWidget, &HubWidget::setHeroExperience);
    connect(firefighter, &Firefighter::moneyChanged, missionWidget, &MissionWidget::setHeroGold);
    connect(firefighter, &Firefighter::moneyChanged, hubWidget, &HubWidget::setHeroGold);
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

    missionWidget->setHeroGold(firefighter->getMoney());
    hubWidget->setHeroGold(firefighter->getMoney());

    missionWidget->setHeroExperience(firefighter->getExperiencePoints());
    hubWidget->setHeroExperience(firefighter->getExperiencePoints());
}

void MainWindow::returnToHub() {
    hubWidget->hideConfirmationButtons();
    hubWidget->showCompletionMessage("Brawo! Ukończyłeś misję i wróciłeś do miasta.");
    stackedWidget->setCurrentWidget(hubWidget);
}
