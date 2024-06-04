#include "roadaccidentmission.h"

RoadAccidentMission::RoadAccidentMission(Firefighter* firefighter, QObject *parent)
    : Mission(parent), firefighter(firefighter) {}

QString RoadAccidentMission::getDescription() const {
    return "Misja 5: Wypadek drogowy - Twoim zadaniem jest ugasić pożar samochodów oraz uratować uwięzionych pasażerów.";
}

void RoadAccidentMission::start() {
    handleIntroDialogue();
}

void RoadAccidentMission::handleIntroDialogue() {
    emit updateMissionStatus("Witaj w misji: Wypadek drogowy! Musisz ugasić pożar samochodów oraz uratować uwięzionych pasażerów. Co chcesz zrobić najpierw?");
    connectButtons("Najpierw ugaszę pożar samochodów", [this] { handleExtinguishFire(); }, "Najpierw uratuję pasażerów", [this] { handleRescuePassengers(); });
}

void RoadAccidentMission::handleExtinguishFire() {
    emit updateMissionStatus("Ugaszasz pożar samochodów, co ułatwia ewakuację, ale pasażerowie doznają więcej obrażeń.");
    connectButtons("Dalej", [this] { handleMissionOutcome(true); });
}

void RoadAccidentMission::handleRescuePassengers() {
    emit updateMissionStatus("Ratujesz uwięzionych pasażerów, zapewniając im szybszą pomoc, ale pożar trudniej ugasić.");
    connectButtons("Dalej", [this] { handleMissionOutcome(false); });
}

void RoadAccidentMission::handleMissionOutcome(bool success) {
    if (success) {
        emit updateMissionStatus("Misja zakończona sukcesem! Uratowałeś pasażerów i ugasiłeś pożar.");
    } else {
        emit updateMissionStatus("Misja zakończona częściowym sukcesem. Pasażerowie są bezpieczni, ale pożar był trudny do opanowania.");
    }
    emit updateMissionStatus("Otrzymujesz nowe narzędzie do rozcinania wraków samochodów jako nagrodę.");
    firefighter->getInventory()->addTool(Tools("Narzędzie do rozcinania", 70, 1, 3, "Nowe narzędzie do rozcinania wraków samochodów", true));
    emit missionCompleted();
}

void RoadAccidentMission::connectButtons(const QString& button0Text, std::function<void()> button0Handler,
                                         const QString& button1Text, std::function<void()> button1Handler,
                                         const QString& button2Text, std::function<void()> button2Handler) {
    emit configureButton(0, button0Text, !button0Text.isEmpty(), button0Handler);
    emit configureButton(1, button1Text, !button1Text.isEmpty(), button1Handler);
    emit configureButton(2, button2Text, !button2Text.isEmpty(), button2Handler);
}
