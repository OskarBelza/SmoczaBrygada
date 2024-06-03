#ifndef TUTORIALMISSION_H
#define TUTORIALMISSION_H

#include "mission.h"
#include "firefighter.h"
#include "dragon.h"
#include "fight.h"
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
    void handleFight(); // Nowa metoda
    void handleFightEnded(bool);

private:
    Firefighter* firefighter;
    Dragon* dragon;

    void connectButtonsForIntro();
    void connectButtonsForToolsInfo();
    void connectButtonsForBattlefieldDescription();
};

#endif // TUTORIALMISSION_H
