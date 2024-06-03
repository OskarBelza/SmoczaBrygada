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
    firefighter->addTool(Tools("Bomba wodna", 60));
    firefighter->addTool(Tools("Pistolet wodny", 30));
    connectButtonsForToolsInfo();
}

void TutorialMission::handleBattlefieldDescription() {
    emit updateMissionStatus("Opis pola walki: Jesteś na polu walki. Smok stoi przed tobą, gotowy do ataku. Co chcesz zrobić?");
    connectButtonsForBattlefieldDescription();
}

void TutorialMission::handleBattle() {
    emit updateMissionStatus("Rozpoczyna się walka! Wybierz broń:");
    connectButtonsForBattle();
}

void TutorialMission::handleWaterBomb() {
    Tools* waterBomb = firefighter->getTool("Bomba wodna");
    if (waterBomb) {
        dragon->takeDamage(waterBomb->getFirePower());
    }
    firefighter->takeDamage(dragon->getFirePower());
    checkBattleOutcome();
}

void TutorialMission::handleWaterGun() {
    Tools* waterGun = firefighter->getTool("Pistolet wodny");
    if (waterGun) {
        dragon->takeDamage(waterGun->getFirePower());
    }
    firefighter->takeDamage(dragon->getFirePower());
    checkBattleOutcome();
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
    emit configureButton(0, "Rozpocznij walkę", true, [this] { handleBattle(); });
    emit configureButton(1, "", false, nullptr);
    emit configureButton(2, "", false, nullptr);
}

void TutorialMission::connectButtonsForBattle() {
    emit configureButton(0, "Użyj bomby wodnej", true, [this] { handleWaterBomb(); });
    emit configureButton(1, "Użyj pistoletu wodnego", true, [this] { handleWaterGun(); });
    emit configureButton(2, "", false, nullptr);
}

void TutorialMission::checkBattleOutcome() {
    if (firefighter->getHealth() <= 0) {
        emit updateMissionStatus("Game Over! Zostałeś pokonany przez smoka.");
        emit configureButton(0, "", false, nullptr);
        emit configureButton(1, "", false, nullptr);
        emit configureButton(2, "", false, nullptr);
    } else if (dragon->getHealth() <= 0) {
        emit updateMissionStatus("Pokonałeś smoka!");
        firefighter->addExperience(100);
        emit missionCompleted();
    } else {
        QString status = QString("Smok nadal żyje! Zdrowie smoka: %1. Wybierz kolejną akcję:").arg(dragon->getHealth());
        emit updateMissionStatus(status);
        connectButtonsForBattle();
    }
}
