#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "firefighter.h"
#include "game.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , game(new Game)
    , missionWidget(new MissionWidget(this))
    , hubWidget(new HubWidget(this)) // Inicjalizacja hubWidget
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
    hubWidget->hide(); // Ukrywamy hubWidget
    setCentralWidget(ui->centralwidget);

    connectMissionSignals(game->getCurrentMission());
    connectHeroSignals();

    updateHeroStats();

    connect(game, &Game::missionCompleted, this, &MainWindow::showCompletionScreen);
    connect(hubWidget, &HubWidget::nextMissionButtonClicked, this, &MainWindow::startNextMission);
}

MainWindow::~MainWindow() {
    delete ui;
    delete game;
    delete missionWidget;
    delete hubWidget;
}

void MainWindow::onNewGameClicked() {
    showMissionScreen(game->getCurrentMissionDescription());
    game->startNewGame();
    updateHeroStats();
}

void MainWindow::onLoadGameClicked() {
    game->loadGame();
    updateHeroStats();
}

void MainWindow::onExitClicked() {
    close();
}

void MainWindow::showMissionScreen(const QString &description) {
    missionWidget->setMissionDescription(description);
    missionWidget->show();
    hubWidget->hide(); // Ukrywamy hubWidget
    setCentralWidget(missionWidget);
}

void MainWindow::showCompletionScreen() {
    missionWidget->hide();
    hubWidget->showCompletionMessage("Brawo! Ukończyłeś misję.");
    hubWidget->show(); // Pokazujemy hubWidget
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
    connect(firefighter, &Firefighter::inventoryChanged, this, &MainWindow::updateHeroStats);
}

void MainWindow::updateHeroStats() {
    auto firefighter = game->getMainCharacter();
    missionWidget->setHeroHealth(firefighter->getHealth());

    QStringList inventory;
    for (const auto& tool : firefighter->getTools()) {
        inventory << tool.getName();
    }
    missionWidget->setHeroInventory(inventory);
}
