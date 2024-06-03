#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"
#include "hubwidget.h"
#include "missionwidget.h"
#include "hub.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onNewGameClicked();
    void onLoadGameClicked();
    void onExitClicked();
    void showMissionScreen(const QString &description);
    void showCompletionScreen();
    void startNextMission();
    void returnToHub();

private:
    void connectMissionSignals(Mission *mission);
    void connectHeroSignals();
    void updateHeroStats();

    Ui::MainWindow *ui;
    Game *game;
    MissionWidget *missionWidget;
    HubWidget *hubWidget;
    Hub *hub;
};

#endif // MAINWINDOW_H
