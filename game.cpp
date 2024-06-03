#include "game.h"

Game::Game() : currentMissionIndex(0) {
    firefighter = new Firefighter("Strażak");
    dragon = new Dragon("Smok", 30);

    // Dodajemy misje do listy misji
    missions.append(new TutorialMission(firefighter, dragon, this));
    // Tutaj można dodać kolejne misje w przyszłości

    connect(missions.first(), &Mission::missionCompleted, this, &Game::onMissionCompleted);
}

void Game::startNewGame() {
    if (!missions.isEmpty()) {
        missions.first()->start();
    }
}

void Game::loadGame() {
    // Placeholder for loading game
    emit gameStateChanged("Gra załadowana");
}

QString Game::getCurrentMissionDescription() const {
    if (currentMissionIndex < missions.size()) {
        return missions[currentMissionIndex]->getDescription();
    }
    return QString();
}

Mission* Game::getCurrentMission() const {
    if (currentMissionIndex < missions.size()) {
        return missions[currentMissionIndex];
    }
    return nullptr;
}

Firefighter* Game::getMainCharacter() const {
    return firefighter;
}

void Game::onMissionCompleted() {
    currentMissionIndex++;
    if (currentMissionIndex < missions.size()) {
        emit missionCompleted();
    } else {
        emit enterHub();
    }
}
