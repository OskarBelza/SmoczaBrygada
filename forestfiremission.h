#ifndef FORESTFIREMISSION_H
#define FORESTFIREMISSION_H

#include "mission.h"
#include "firefighter.h"
#include "dragon.h"
#include <QObject>

class ForestFireMission : public Mission {
    Q_OBJECT
public:
    ForestFireMission(Firefighter* firefighter, QObject *parent = nullptr);

    QString getDescription() const override;
    void start() override;

public slots:
    void handleIntroDialogue();
    void handleWaterSourceSecuring();
    void handleFirefighting();
    void handleMissionOutcome(bool success);

private:
    Firefighter* firefighter;
    Dragon* windDragon;

    void connectButtons(const QString& button0Text, std::function<void()> button0Handler,
                        const QString& button1Text = QString(), std::function<void()> button1Handler = nullptr,
                        const QString& button2Text = QString(), std::function<void()> button2Handler = nullptr);
};

#endif // FORESTFIREMISSION_H
