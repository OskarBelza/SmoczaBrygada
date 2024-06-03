#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"
#include "missionwidget.h"
#include "hubwidget.h" // dodajemy import

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
    void updateHeroStats();
    void showCompletionScreen();
    void startNextMission();

private:
    Ui::MainWindow *ui;
    Game *game;
    MissionWidget *missionWidget;
    HubWidget *hubWidget;

    void showMissionScreen(const QString &description);
    void connectMissionSignals(Mission* mission);
    void connectHeroSignals(); // Deklaracja metody
};

#endif // MAINWINDOW_H