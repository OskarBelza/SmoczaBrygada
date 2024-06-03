#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QVector>
#include "firefighter.h"
#include "tutorialmission.h"

class Game : public QObject {
    Q_OBJECT
public:
    Game();
    void startNewGame();
    void loadGame();
    QString getCurrentMissionDescription() const;
    Mission* getCurrentMission() const;
    Firefighter* getMainCharacter() const;

signals:
    void gameStateChanged(const QString &state);
    void enterHub();
    void missionCompleted();

private:
    Firefighter *firefighter;
    QVector<Mission*> missions;
    int currentMissionIndex;

private slots:
    void onMissionCompleted();
};

#endif // GAME_H
