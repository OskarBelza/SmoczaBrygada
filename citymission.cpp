#include "citymission.h"

CityMission::CityMission(Firefighter* firefighter, QObject *parent)
    : Mission(parent), firefighter(firefighter) {
    magmaDragon = new Dragon("Smok Magmowy", 70);
}

QString CityMission::getDescription() const {
    return "Misja 7: Zniszczone centrum miasta - Twoim zadaniem jest przemieszczać się przez ulice pokryte lawą, uratować mieszkańców i walczyć ze smokiem magmowym.";
}

void CityMission::start() {
    handleIntroDialogue();
}

void CityMission::handleIntroDialogue() {
    emit updateMissionStatus("Centrum miasta jest zniszczone i ulice są pokryte lawą! Musisz przemieszczać się przez ulice, uratować uwięzionych mieszkańców i walczyć ze smokiem magmowym. Co chcesz zrobić najpierw?");
    connectButtons("Najpierw wybiorę bezpieczniejszą trasę", [this] { handleSafeRoute(); }, "Najpierw skupię się na ratowaniu ludzi", [this] { handleRescuePeople(); });
}

void CityMission::handleSafeRoute() {
    emit updateMissionStatus("Wybierasz bezpieczniejszą trasę, co ułatwi poruszanie się, ale zajmie więcej czasu.");
    connectButtons("Dalej", [this] { handleFight(); });
}

void CityMission::handleRescuePeople() {
    emit updateMissionStatus("Skupiasz się na ratowaniu ludzi, co zwiększa ryzyko, ale więcej osób zostanie uratowanych.");
    connectButtons("Dalej", [this] { handleFight(); });
}

void CityMission::handleFight() {
    Fight* fight = new Fight(firefighter, magmaDragon, this);

    connect(fight, &Fight::updateFightStatus, this, &CityMission::updateMissionStatus);
    connect(fight, &Fight::configureButton, this, &CityMission::configureButton);
    connect(fight, &Fight::fightEnded, this, &CityMission::handleFightEnded);

    fight->start();
}

void CityMission::handleFightEnded(bool won) {
    if (won) {
        emit updateMissionStatus("Pokonałeś smoka magmowego i uratowałeś mieszkańców!");
        emit updateMissionStatus("Otrzymujesz specjalne buty odporne na lawę jako nagrodę.");
        firefighter->getInventory()->addTool(Tools("Buty odporne na lawę", 100, 1, 5, "Buty zapewniające ochronę przed lawą", true));
        emit missionCompleted();
    } else {
        emit updateMissionStatus("Game Over! Zostałeś pokonany przez smoka magmowego.");
        connectButtons("", nullptr, "", nullptr, "", nullptr);
    }
}

void CityMission::connectButtons(const QString& button0Text, std::function<void()> button0Handler,
                                 const QString& button1Text, std::function<void()> button1Handler,
                                 const QString& button2Text, std::function<void()> button2Handler) {
    emit configureButton(0, button0Text, !button0Text.isEmpty(), button0Handler);
    emit configureButton(1, button1Text, !button1Text.isEmpty(), button1Handler);
    emit configureButton(2, button2Text, !button2Text.isEmpty(), button2Handler);
}
