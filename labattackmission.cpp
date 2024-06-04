#include "labattackmission.h"

LabAttackMission::LabAttackMission(Firefighter* firefighter, QObject *parent)
    : Mission(parent), firefighter(firefighter) {
    electricDragon = new Dragon("Smok Elektryczny", 50);
}

QString LabAttackMission::getDescription() const {
    return "Misja 6: Atak na laboratorium badawcze - Twoim zadaniem jest ewakuować naukowców, uratować dokumenty badawcze i walczyć ze smokami elektrycznymi.";
}

void LabAttackMission::start() {
    handleIntroDialogue();
}

void LabAttackMission::handleIntroDialogue() {
    emit updateMissionStatus("Laboratorium badawcze jest atakowane przez Smoki Elektryczne! Musisz ewakuować naukowców, zabezpieczyć ważne dokumenty i walczyć ze smokami. Co chcesz zrobić najpierw?");
    connectButtons("Najpierw ratować ludzi", [this] { handleRescueScientists(); }, "Najpierw zabezpieczyć dokumenty", [this] { handleSecureDocuments(); });
}

void LabAttackMission::handleRescueScientists() {
    emit updateMissionStatus("Ratujesz naukowców, ale dokumenty mogą zostać zniszczone.");
    connectButtons("Dalej", [this] { handleFight(); });
}

void LabAttackMission::handleSecureDocuments() {
    emit updateMissionStatus("Zabezpieczasz dokumenty, ale naukowcy mogą być w większym niebezpieczeństwie.");
    connectButtons("Dalej", [this] { handleFight(); });
}

void LabAttackMission::handleFight() {
    Fight* fight = new Fight(firefighter, electricDragon, this);

    connect(fight, &Fight::updateFightStatus, this, &LabAttackMission::updateMissionStatus);
    connect(fight, &Fight::configureButton, this, &LabAttackMission::configureButton);
    connect(fight, &Fight::fightEnded, this, &LabAttackMission::handleFightEnded);

    fight->start();
}

void LabAttackMission::handleFightEnded(bool won) {
    if (won) {
        emit updateMissionStatus("Pokonałeś smoka elektrycznego i uratowałeś laboratorium!");
        emit updateMissionStatus("Otrzymujesz gaśnice elektryczne jako nagrodę.");
        firefighter->getInventory()->addTool(Tools("Gaśnica elektryczna", 80, 1, 3, "Specjalistyczna gaśnica do walki z pożarami elektrycznymi", true));
        emit missionCompleted();
    } else {
        emit updateMissionStatus("Game Over! Zostałeś pokonany przez smoka elektrycznego.");
        connectButtons("", nullptr, "", nullptr, "", nullptr);
    }
}

void LabAttackMission::connectButtons(const QString& button0Text, std::function<void()> button0Handler,
                                      const QString& button1Text, std::function<void()> button1Handler,
                                      const QString& button2Text, std::function<void()> button2Handler) {
    emit configureButton(0, button0Text, !button0Text.isEmpty(), button0Handler);
    emit configureButton(1, button1Text, !button1Text.isEmpty(), button1Handler);
    emit configureButton(2, button2Text, !button2Text.isEmpty(), button2Handler);
}
