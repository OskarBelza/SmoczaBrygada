#include "game.h"

Game::Game() : currentMissionIndex(0) {
    firefighter = new Firefighter("Strażak");

    missions.append(new TutorialMission(firefighter, this));
    missions.append(new SmokeDragonMission(firefighter, this));
    missions.append(new SchoolEvacuationMission(firefighter, this));
    missions.append(new ForestFireMission(firefighter, this));
    missions.append(new RoadAccidentMission(firefighter, this));
    missions.append(new LabAttackMission(firefighter, this));
    missions.append(new CityMission(firefighter, this));
    missions.append(new VolcanoMission(firefighter, this));


    connect(missions.first(), &Mission::missionCompleted, this, &Game::onMissionCompleted);
}

void Game::startNewGame() {
    if (!missions.isEmpty()) {
        missions.first()->start();
    }
}

void Game::loadGame() {
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
