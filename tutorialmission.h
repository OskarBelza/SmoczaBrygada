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
    TutorialMission(Firefighter* firefighter, QObject *parent = nullptr);

    QString getDescription() const override;
    void start() override;

public slots:
    void handleIntroDialogue();
    void handleToolsInfo();
    void handleBattlefieldDescription();
    void handleFight();
    void handleFightEnded(bool);

private:
    Firefighter* firefighter;
    Dragon* dragon;

    void connectButtons(const QString& button0Text, std::function<void()> button0Handler,
                        const QString& button1Text = QString(), std::function<void()> button1Handler = nullptr,
                        const QString& button2Text = QString(), std::function<void()> button2Handler = nullptr);
};

#endif // TUTORIALMISSION_H
