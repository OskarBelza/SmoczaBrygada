#include "schoolevacuationmission.h"

SchoolEvacuationMission::SchoolEvacuationMission(Firefighter* firefighter, QObject *parent)
    : Mission(parent), firefighter(firefighter) {}

QString SchoolEvacuationMission::getDescription() const {
    return "Misja 3: Ewakuacja szkoły - Twoim zadaniem jest ewakuować uczniów i nauczycieli z płonącej szkoły oraz zabezpieczyć ważne materiały edukacyjne.";
}

void SchoolEvacuationMission::start() {
    handleIntroDialogue();
}

void SchoolEvacuationMission::handleIntroDialogue() {
    emit updateMissionStatus("Witaj w misji ewakuacyjnej! Musisz ewakuować uczniów i nauczycieli z płonącej szkoły oraz zabezpieczyć ważne materiały edukacyjne. Co chcesz zrobić najpierw?");
    connectButtons("Najpierw ewakuuję uczniów", [this] { handleEvacuation(); }, "Zabezpieczę materiały edukacyjne", [this] { handleMaterialSecuring(); });
}

void SchoolEvacuationMission::handleDecisionMaking() {
    // Placeholder for decision-making process
}

void SchoolEvacuationMission::handleEvacuation() {
    emit updateMissionStatus("Ewakuujesz uczniów i nauczycieli. Wielu z nich zostaje uratowanych, ale niektóre materiały edukacyjne zostają zniszczone.");
    connectButtons("Dalej", [this] { handleMissionOutcome(true); });
}

void SchoolEvacuationMission::handleMaterialSecuring() {
    emit updateMissionStatus("Zabezpieczasz ważne materiały edukacyjne. Większość z nich jest bezpieczna, ale mniej uczniów zostaje uratowanych.");
    connectButtons("Dalej", [this] { handleMissionOutcome(false); });
}

void SchoolEvacuationMission::handleMissionOutcome(bool success) {
    if (success) {
        emit updateMissionStatus("Misja zakończona sukcesem! Uratowałeś wielu uczniów i nauczycieli.");
    } else {
        emit updateMissionStatus("Misja zakończona częściowym sukcesem. Zachowałeś materiały edukacyjne, ale mniej osób zostało uratowanych.");
    }
    emit updateMissionStatus("Otrzymujesz podstawowy zestaw ratunkowy jako nagrodę.");
    firefighter->getInventory()->addTool(Tools("Podstawowy zestaw ratunkowy", 50, 1, 1, "Podstawowy zestaw do ratowania", true));
    emit missionCompleted();
}

void SchoolEvacuationMission::connectButtons(const QString& button0Text, std::function<void()> button0Handler,
                                             const QString& button1Text, std::function<void()> button1Handler,
                                             const QString& button2Text, std::function<void()> button2Handler) {
    emit configureButton(0, button0Text, !button0Text.isEmpty(), button0Handler);
    emit configureButton(1, button1Text, !button1Text.isEmpty(), button1Handler);
    emit configureButton(2, button2Text, !button2Text.isEmpty(), button2Handler);
}
