#ifndef SMOKEDRAGONMISSION_H
#define SMOKEDRAGONMISSION_H

#include "mission.h"
#include "firefighter.h"
#include "dragon.h"
#include "fight.h"
#include <QObject>

class SmokeDragonMission : public Mission {
    Q_OBJECT
public:
    SmokeDragonMission(Firefighter* firefighter, QObject *parent = nullptr);

    QString getDescription() const override;
    void start() override;

public slots:
    void handleIntroDialogue();
    void handleObjectives();
    void handleRescue();
    void handleFight();
    void handleFightEnded(bool);
    void handleMissionOutcome();

private:
    Firefighter* firefighter;
    Dragon* smokeDragon;
    int rescuedCivilians;

    void connectButtons(const QString& button0Text, std::function<void()> button0Handler,
                        const QString& button1Text = QString(), std::function<void()> button1Handler = nullptr,
                        const QString& button2Text = QString(), std::function<void()> button2Handler = nullptr);
};

#endif // SMOKEDRAGONMISSION_H
