#ifndef SCHOOL_EVACUATION_MISSION_H
#define SCHOOL_EVACUATION_MISSION_H

#include "mission.h"
#include "firefighter.h"
#include <QObject>

class SchoolEvacuationMission : public Mission {
    Q_OBJECT
public:
    SchoolEvacuationMission(Firefighter* firefighter, QObject *parent = nullptr);

    QString getDescription() const override;
    void start() override;

public slots:
    void handleIntroDialogue();
    void handleDecisionMaking();
    void handleEvacuation();
    void handleMaterialSecuring();
    void handleMissionOutcome(bool success);

private:
    Firefighter* firefighter;

    void connectButtons(const QString& button0Text, std::function<void()> button0Handler,
                        const QString& button1Text = QString(), std::function<void()> button1Handler = nullptr,
                        const QString& button2Text = QString(), std::function<void()> button2Handler = nullptr);
};

#endif // SCHOOL_EVACUATION_MISSION_H
