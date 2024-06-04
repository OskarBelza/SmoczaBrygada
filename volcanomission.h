#ifndef VOLCANOMISSION_H
#define VOLCANOMISSION_H

#include "mission.h"
#include "firefighter.h"
#include "dragon.h"
#include "fight.h"
#include <QObject>

class VolcanoMission : public Mission {
    Q_OBJECT
public:
    VolcanoMission(Firefighter* firefighter, QObject *parent = nullptr);

    QString getDescription() const override;
    void start() override;

public slots:
    void handleIntroDialogue();
    void handleLavaTunnelPath();
    void handleSteamChamberPath();
    void handlePuzzle();
    void handleFight();
    void handleFightEnded(bool);

private:
    Firefighter* firefighter;
    Dragon* blazingDragon;

    void connectButtons(const QString& button0Text, std::function<void()> button0Handler,
                        const QString& button1Text = QString(), std::function<void()> button1Handler = nullptr,
                        const QString& button2Text = QString(), std::function<void()> button2Handler = nullptr);
};

#endif // VOLCANOMISSION_H
