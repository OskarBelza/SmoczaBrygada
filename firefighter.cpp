#include "firefighter.h"

Firefighter::Firefighter(const QString& name, QObject *parent)
    : QObject(parent), name(name), health(100), experiencePoints(0), lvl(5), inventory(new Inventory(this)) {}

QString Firefighter::getName() const {
    return name;
}

int Firefighter::getHealth() const {
    return health;
}

int Firefighter::getExperiencePoints() const {
    return experiencePoints;
}

int Firefighter::getLevel() const {
    return lvl;
}

void Firefighter::takeDamage(int damage) {
    health -= damage;
    emit healthChanged(health);
}

void Firefighter::addExperience(int points) {
    experiencePoints += points;
    while (experiencePoints >= 100) {
        experiencePoints -= 100;
        lvl++;
        emit levelUp(lvl); // Emitowanie sygnału przy każdym awansie na nowy poziom
    }
}

Inventory* Firefighter::getInventory() {
    return inventory;
}
