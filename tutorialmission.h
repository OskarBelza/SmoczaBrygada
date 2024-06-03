#ifndef TUTORIALMISSION_H
#define TUTORIALMISSION_H

#include "mission.h"
#include "firefighter.h"
#include "dragon.h"
#include <QObject>

class TutorialMission : public Mission {
    Q_OBJECT
public:
    TutorialMission(Firefighter* firefighter, Dragon* dragon, QObject *parent = nullptr);

    QString getDescription() const override;
    void start() override;

public slots:
    void handleIntroDialogue();
    void handleToolsInfo();
    void handleBattlefieldDescription();
    void handleBattle();
    void handleWaterBomb();
    void handleWaterGun();

private:
    Firefighter* firefighter;
    Dragon* dragon;

    void connectButtonsForIntro();
    void connectButtonsForToolsInfo();
    void connectButtonsForBattlefieldDescription();
    void connectButtonsForBattle();
    void checkBattleOutcome();
};

#endif // TUTORIALMISSION_H
