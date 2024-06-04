#include "volcanomission.h"

VolcanoMission::VolcanoMission(Firefighter* firefighter, QObject *parent)
    : Mission(parent), firefighter(firefighter) {
    blazingDragon = new Dragon("Smok Żarzący", 100);
}

QString VolcanoMission::getDescription() const {
    return "Misja 8: Tajemnice wulkanu - Twoim zadaniem jest przeniknąć do wnętrza wulkanu, rozwiązać zagadki i pokonać Smoka Żarzącego.";
}

void VolcanoMission::start() {
    handleIntroDialogue();
}

void VolcanoMission::handleIntroDialogue() {
    emit updateMissionStatus("Znajdujesz się u stóp wulkanu, gdzie czeka na ciebie Smok Żarzący. Musisz dostać się do wnętrza wulkanu, rozwiązać zagadki i pokonać smoka. Jaką trasę wybierzesz?");
    connectButtons("Ścieżka przez tunel lawowy", [this] { handleLavaTunnelPath(); }, "Ścieżka przez komorę parową", [this] { handleSteamChamberPath(); });
}

void VolcanoMission::handleLavaTunnelPath() {
    emit updateMissionStatus("Wybierasz krótszą, ale bardziej niebezpieczną trasę przez tunel lawowy.");
    connectButtons("Dalej", [this] { handlePuzzle(); });
}

void VolcanoMission::handleSteamChamberPath() {
    emit updateMissionStatus("Wybierasz dłuższą, ale bezpieczniejszą trasę przez komorę parową.");
    connectButtons("Dalej", [this] { handlePuzzle(); });
}

void VolcanoMission::handlePuzzle() {
    emit updateMissionStatus("Napotykasz na zagadki, które musisz rozwiązać, aby dostać się do głębszych części wulkanu.");
    connectButtons("Rozwiąż zagadkę", [this] { handleFight(); });
}

void VolcanoMission::handleFight() {
    Fight* fight = new Fight(firefighter, blazingDragon, this);

    connect(fight, &Fight::updateFightStatus, this, &VolcanoMission::updateMissionStatus);
    connect(fight, &Fight::configureButton, this, &VolcanoMission::configureButton);
    connect(fight, &Fight::fightEnded, this, &VolcanoMission::handleFightEnded);

    fight->start();
}

void VolcanoMission::handleFightEnded(bool won) {
    if (won) {
        emit updateMissionStatus("Pokonałeś Smoka Żarzącego i odkryłeś tajemnice wulkanu!");
        emit updateMissionStatus("Otrzymujesz Klucz do tajemniczej komnaty Władcy Żaru jako nagrodę.");
        firefighter->getInventory()->addTool(Tools("Klucz do komnaty Władcy Żaru", 0, 0, 0, "Otwiera tajemniczą komnatę Władcy Żaru", false));
        emit missionCompleted();
    } else {
        emit updateMissionStatus("Game Over! Zostałeś pokonany przez Smoka Żarzącego.");
        connectButtons("", nullptr, "", nullptr, "", nullptr);
    }
}

void VolcanoMission::connectButtons(const QString& button0Text, std::function<void()> button0Handler,
                                    const QString& button1Text, std::function<void()> button1Handler,
                                    const QString& button2Text, std::function<void()> button2Handler) {
    emit configureButton(0, button0Text, !button0Text.isEmpty(), button0Handler);
    emit configureButton(1, button1Text, !button1Text.isEmpty(), button1Handler);
    emit configureButton(2, button2Text, !button2Text.isEmpty(), button2Handler);
}
