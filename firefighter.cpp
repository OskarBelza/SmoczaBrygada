#include "firefighter.h"

Firefighter::Firefighter(const QString& name, QObject *parent)
    : QObject(parent), name(name), health(100), experiencePoints(0) {}

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
    if (health < 0) health = 0;
    emit healthChanged(health); // Emit sygnału po zmianie zdrowia
}

void Firefighter::addExperience(int points) {
    experiencePoints += points;
}

void Firefighter::addTool(const Tools& tool) {
    tools.append(tool);
    emit inventoryChanged(); // Emit sygnału po dodaniu nowego narzędzia
}

Tools* Firefighter::getTool(const QString& toolName) {
    for (auto& tool : tools) {
        if (tool.getName() == toolName) {
            return &tool;
        }
    }
    return nullptr;
}

QVector<Tools> Firefighter::getTools() const {
    return tools;
}
