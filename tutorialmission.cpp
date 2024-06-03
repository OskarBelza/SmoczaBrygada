#include "tutorialmission.h"

TutorialMission::TutorialMission(Firefighter* firefighter, Dragon* dragon, QObject *parent)
    : Mission(parent), firefighter(firefighter), dragon(dragon) {}

QString TutorialMission::getDescription() const {
    return "Witaj w misji samouczkowej! Twoim zadaniem jest pokonać smoka.";
}

void TutorialMission::start() {
    handleIntroDialogue();
}

void TutorialMission::handleIntroDialogue() {
    emit updateMissionStatus("Witaj w grze Smocza Brygada! Twoim celem jest pokonać smoka. Aby to zrobić, musisz użyć swojego sprzętu strażackiego. Rozumiesz?");
    connectButtonsForIntro();
}

void TutorialMission::handleToolsInfo() {
    emit updateMissionStatus("Otrzymałeś nowy sprzęt: Bomba wodna i Pistolet wodny.");
    firefighter->getInventory()->addTool(Tools("Bomba wodna", 60, 1, 1, "Mocna broń przeciwko smokom", true));
    firefighter->getInventory()->addTool(Tools("Pistolet wodny", 30, 1, 1, "Słabsza broń przeciwko smokom", false));
    connectButtonsForToolsInfo();
}

void TutorialMission::handleBattlefieldDescription() {
    emit updateMissionStatus("Opis pola walki: Jesteś na polu walki. Smok stoi przed tobą, gotowy do ataku. Co chcesz zrobić?");
    connectButtonsForBattlefieldDescription();
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
        emit configureButton(0, "", false, nullptr);
        emit configureButton(1, "", false, nullptr);
        emit configureButton(2, "", false, nullptr);
    }
}

void TutorialMission::connectButtonsForIntro() {
    emit configureButton(0, "Dalej", true, [this] { handleToolsInfo(); });
    emit configureButton(1, "", false, nullptr);
    emit configureButton(2, "", false, nullptr);
}

void TutorialMission::connectButtonsForToolsInfo() {
    emit configureButton(0, "Dalej", true, [this] { handleBattlefieldDescription(); });
    emit configureButton(1, "", false, nullptr);
    emit configureButton(2, "", false, nullptr);
}

void TutorialMission::connectButtonsForBattlefieldDescription() {
    emit configureButton(0, "Rozpocznij walkę", true, [this] { handleFight(); });
    emit configureButton(1, "", false, nullptr);
    emit configureButton(2, "", false, nullptr);
}
