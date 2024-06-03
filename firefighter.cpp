#include "firefighter.h"

Firefighter::Firefighter(const QString& name, QObject *parent)
    : QObject(parent), name(name), health(100), experiencePoints(0), inventory(new Inventory(this)) {}

QString Firefighter::getName() const {
    return name;
}

int Firefighter::getHealth() const {
    return health;
}

int Firefighter::getExperiencePoints() const {
    return experiencePoints;
}

void Firefighter::takeDamage(int damage) {
    health -= damage;
    emit healthChanged(health);
}

void Firefighter::addExperience(int points) {
    experiencePoints += points;
}

Inventory* Firefighter::getInventory() {
    return inventory;
}
