#include "tutorialmission.h"

TutorialMission::TutorialMission(Firefighter* firefighter, QObject *parent)
    : Mission(parent), firefighter(firefighter) {
    dragon = new Dragon("Smok", 30);
}

QString TutorialMission::getDescription() const {
    return "Witaj w misji samouczkowej! Twoim zadaniem jest pokonać smoka.";
}

void TutorialMission::start() {
    handleIntroDialogue();
}

void TutorialMission::handleIntroDialogue() {
    emit updateMissionStatus("Witaj w grze Smocza Brygada! Twoim celem jest pokonać smoka. Aby to zrobić, musisz użyć swojego sprzętu strażackiego. Rozumiesz?");
    connectButtons("Dalej", [this] { handleToolsInfo(); });
}

void TutorialMission::handleToolsInfo() {
    emit updateMissionStatus("Otrzymałeś nowy sprzęt: Bomba wodna i Pistolet wodny.");
    firefighter->getInventory()->addTool(Tools("Bomba wodna", 60, 1, 2, "Mocna broń przeciwko smokom", true));
    firefighter->getInventory()->addTool(Tools("Pistolet wodny", 30, 1, 1, "Słabsza broń przeciwko smokom", false));
    connectButtons("Dalej", [this] { handleBattlefieldDescription(); });
}

void TutorialMission::handleBattlefieldDescription() {
    emit updateMissionStatus("Opis pola walki: Jesteś na polu walki. Smok stoi przed tobą, gotowy do ataku. Co chcesz zrobić?");
    connectButtons("Rozpocznij walkę", [this] { handleFight(); });
}

void TutorialMission::handleFight() {
    Fight* fight = new Fight(firefighter, dragon, this);

    connect(fight, &Fight::updateFightStatus, this, &TutorialMission::updateMissionStatus);
    connect(fight, &Fight::configureButton, this, &TutorialMission::configureButton);
    connect(fight, &Fight::fightEnded, this, &TutorialMission::handleFightEnded);

    fight->start();
}

void TutorialMission::handleFightEnded(bool won) {
    if (won) {
        emit updateMissionStatus("Pokonałeś smoka!");
        emit missionCompleted();
    } else {
        emit updateMissionStatus("Game Over! Zostałeś pokonany przez smoka.");
        connectButtons("", nullptr, "", nullptr, "", nullptr);
    }
}

void TutorialMission::connectButtons(const QString& button0Text, std::function<void()> button0Handler,
                                     const QString& button1Text, std::function<void()> button1Handler,
                                     const QString& button2Text, std::function<void()> button2Handler) {
    emit configureButton(0, button0Text, !button0Text.isEmpty(), button0Handler);
    emit configureButton(1, button1Text, !button1Text.isEmpty(), button1Handler);
    emit configureButton(2, button2Text, !button2Text.isEmpty(), button2Handler);
}
