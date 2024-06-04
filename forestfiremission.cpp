#include "forestfiremission.h"

ForestFireMission::ForestFireMission(Firefighter* firefighter, QObject *parent)
    : Mission(parent), firefighter(firefighter) {
    windDragon = new Dragon("Smok Wietrzny", 40);
}

QString ForestFireMission::getDescription() const {
    return "Misja 4: Pożar w lesie - Twoim zadaniem jest ugasić pożary w różnych częściach lasu oraz zabezpieczyć lokalne źródło wody przed zanieczyszczeniem.";
}

void ForestFireMission::start() {
    handleIntroDialogue();
}

void ForestFireMission::handleIntroDialogue() {
    emit updateMissionStatus("Witaj w misji: Pożar w lesie! Musisz ugasić pożary w różnych częściach lasu oraz zabezpieczyć lokalne źródło wody przed zanieczyszczeniem. Co chcesz zrobić najpierw?");
    connectButtons("Najpierw zabezpieczę źródło wody", [this] { handleWaterSourceSecuring(); }, "Zajmę się pożarami w lesie", [this] { handleFirefighting(); });
}

void ForestFireMission::handleWaterSourceSecuring() {
    emit updateMissionStatus("Zabezpieczasz lokalne źródło wody przed zanieczyszczeniem. Woda pozostaje czysta, ale pożary w lesie się rozprzestrzeniają.");
    connectButtons("Dalej", [this] { handleMissionOutcome(false); });
}

void ForestFireMission::handleFirefighting() {
    emit updateMissionStatus("Zajmujesz się pożarami w lesie, ograniczając zniszczenia. Jednak źródło wody zostaje zanieczyszczone.");
    connectButtons("Dalej", [this] { handleMissionOutcome(true); });
}

void ForestFireMission::handleMissionOutcome(bool success) {
    if (success) {
        emit updateMissionStatus("Misja zakończona sukcesem! Ograniczyłeś zniszczenia w lesie.");
    } else {
        emit updateMissionStatus("Misja zakończona częściowym sukcesem. Zachowałeś czyste źródło wody, ale las doznał większych zniszczeń.");
    }
    emit updateMissionStatus("Otrzymujesz Bomby wodne jako nagrodę.");
    firefighter->getInventory()->addTool(Tools("Bomba wodna", 60, 1, 2, "Mocna broń przeciwko pożarom", true));
    emit missionCompleted();
}

void ForestFireMission::connectButtons(const QString& button0Text, std::function<void()> button0Handler,
                                       const QString& button1Text, std::function<void()> button1Handler,
                                       const QString& button2Text, std::function<void()> button2Handler) {
    emit configureButton(0, button0Text, !button0Text.isEmpty(), button0Handler);
    emit configureButton(1, button1Text, !button1Text.isEmpty(), button1Handler);
    emit configureButton(2, button2Text, !button2Text.isEmpty(), button2Handler);
}
