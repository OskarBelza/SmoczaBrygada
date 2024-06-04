#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QVector>
#include <QFile>
#include "firefighter.h"
#include "tutorialmission.h"
#include "smokedragonmission.h"
#include "schoolevacuationmission.h"
#include "forestfiremission.h"
#include "roadaccidentmission.h"
#include "labattackmission.h"
#include "citymission.h"
#include "volcanomission.h"

class Game : public QObject {
    Q_OBJECT
public:
    Game();
    void startNewGame();
    void saveGame() const;
    void loadGameFromFile();
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
