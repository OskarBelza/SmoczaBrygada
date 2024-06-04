#ifndef CITYMISSION_H
#define CITYMISSION_H

#include "mission.h"
#include "firefighter.h"
#include "dragon.h"
#include "fight.h"
#include <QObject>

class CityMission : public Mission {
    Q_OBJECT
public:
    CityMission(Firefighter* firefighter, QObject *parent = nullptr);

    QString getDescription() const override;
    void start() override;

public slots:
    void handleIntroDialogue();
    void handleSafeRoute();
    void handleRescuePeople();
    void handleFight();
    void handleFightEnded(bool);

private:
    Firefighter* firefighter;
    Dragon* magmaDragon;

    void connectButtons(const QString& button0Text, std::function<void()> button0Handler,
                        const QString& button1Text = QString(), std::function<void()> button1Handler = nullptr,
                        const QString& button2Text = QString(), std::function<void()> button2Handler = nullptr);
};

#endif // CITYMISSION_H
