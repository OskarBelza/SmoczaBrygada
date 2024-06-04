#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "firefighter.h"
#include "game.h"
#include "hub.h"
#include "hubwidget.h"
#include "missionwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onNewGameClicked();
    void onLoadGameClicked();
    void onExitClicked();
    void showMissionScreen(const QString &description);
    void showCompletionScreen();
    void startNextMission();
    void connectMissionSignals(Mission* mission);
    void connectHeroSignals();
    void updateHeroStats();
    void returnToHub();

private:
    Ui::MainWindow *ui;
    Game *game;
    MissionWidget *missionWidget;
    HubWidget *hubWidget;
    Hub *hub;
};

#endif // MAINWINDOW_H
