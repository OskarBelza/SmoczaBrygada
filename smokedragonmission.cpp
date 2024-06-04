#include "smokedragonmission.h"
#include "QDebug"

SmokeDragonMission::SmokeDragonMission(Firefighter* firefighter, QObject *parent)
    : Mission(parent), firefighter(firefighter), rescuedCivilians(0) {
    smokeDragon = new Dragon("Smok Dymny", 20);
}

QString SmokeDragonMission::getDescription() const {
    return "Misja 2: Atak Smoka Dymnego. Twoim zadaniem jest znaleźć i uratować cywilów uwięzionych w budynkach oraz pokonać Smoka Dymnego.";
}

void SmokeDragonMission::start() {
    handleIntroDialogue();
}

void SmokeDragonMission::handleIntroDialogue() {
    qDebug() << "Hello";
    emit updateMissionStatus("Smok Dymny zaatakował miasto! Musisz znaleźć i uratować cywilów uwięzionych w budynkach oraz pokonać smoka. Co chcesz zrobić najpierw?");
    connectButtons("Najpierw znajdę i uratuję cywilów.", [this] { handleRescue(); },
        "Skupię się na walce ze smokiem.", [this] { handleFight(); });
}

void SmokeDragonMission::handleRescue() {
    emit updateMissionStatus("Zaczynasz ratować cywilów. Znajdujesz ich w zrujnowanych budynkach i wyprowadzasz na bezpieczne miejsce.");
    rescuedCivilians = 10;
    firefighter->getInventory()->addTool(Tools("Bomba wodna", 60, 1, 2, "Mocna broń przeciwko smokom", true));
    firefighter->getInventory()->addTool(Tools("Pistolet wodny", 30, 1, 1, "Słabsza broń przeciwko smokom", false));
    connectButtons("Dalej", [this] { handleObjectives(); });
}

void SmokeDragonMission::handleObjectives() {
    emit updateMissionStatus("Uratowałeś cywilów. Teraz musisz zmierzyć się ze Smokiem Dymnym.");
    connectButtons("Rozpocznij walkę", [this] { handleFight(); });
}

void SmokeDragonMission::handleFight() {
    Fight* fight = new Fight(firefighter, smokeDragon, this);

    connect(fight, &Fight::updateFightStatus, this, &SmokeDragonMission::updateMissionStatus);
    connect(fight, &Fight::configureButton, this, &SmokeDragonMission::configureButton);
    connect(fight, &Fight::fightEnded, this, &SmokeDragonMission::handleFightEnded);

    fight->start();
}

void SmokeDragonMission::handleFightEnded(bool won) {
    if (won) {
        emit updateMissionStatus("Pokonałeś Smoka Dymnego!");
        connectButtons("Dalej", [this] { handleMissionOutcome(); });
    } else {
        emit updateMissionStatus("Game Over! Zostałeś pokonany przez Smoka Dymnego.");
        connectButtons("", nullptr, "", nullptr, "", nullptr);
    }
}

void SmokeDragonMission::handleMissionOutcome() {
    emit updateMissionStatus("Misja zakończona sukcesem! Otrzymałeś maski przeciwgazowe jako nagrodę.");
    firefighter->getInventory()->addTool(Tools("Maska przeciwgazowa", 0, 1, 0, "Chroni przed dymem", true));
    emit missionCompleted();
}

void SmokeDragonMission::connectButtons(const QString& button0Text, std::function<void()> button0Handler,
                                        const QString& button1Text, std::function<void()> button1Handler,
                                        const QString& button2Text, std::function<void()> button2Handler) {
    emit configureButton(0, button0Text, !button0Text.isEmpty(), button0Handler);
    emit configureButton(1, button1Text, !button1Text.isEmpty(), button1Handler);
    emit configureButton(2, button2Text, !button2Text.isEmpty(), button2Handler);
}
