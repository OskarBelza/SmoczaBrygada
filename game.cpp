#include "game.h"
#include <QDebug>

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

void Game::saveGame() const {
    QFile file("savegame.dat");
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream out(&file);
        out << currentMissionIndex;
        out << *firefighter;
        file.close();
    }
}

void Game::loadGameFromFile() {
    QFile file("savegame.dat");
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);
        in >> currentMissionIndex;
        in >> *firefighter;
        file.close();
    }
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
        qDebug() << "Rozpoczynam nową misję: " << currentMissionIndex;
        Mission* nextMission = getCurrentMission();
        if (nextMission) {
            connect(nextMission, &Mission::missionCompleted, this, &Game::onMissionCompleted);
            nextMission->start();
        }
    } else {
        emit enterHub();
    }
}

