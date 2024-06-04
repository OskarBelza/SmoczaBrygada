

// firefighter.cpp

#include "firefighter.h"

Firefighter::Firefighter(const QString& name, QObject *parent)
    : QObject(parent), name(name), health(100), experiencePoints(0), lvl(5), inventory(new Inventory(this)), money(100), maxHealth(100) {}

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

int Firefighter::getMoney() const {
    return money;
}

void Firefighter::takeDamage(int damage) {
    health -= damage;
    emit healthChanged(health);
}

void Firefighter::addExperience(int points) {
    experiencePoints += points;
    emit experienceChanged(experiencePoints);
    while (experiencePoints >= 100) {
        experiencePoints -= 100;
        lvl++;
        emit levelUp(lvl);
    }
}

void Firefighter::addMoney(int extraMoney) {
    money += extraMoney;
    emit moneyChanged(money);
}

Inventory* Firefighter::getInventory() {
    return inventory;
}

void Firefighter::buyTool(Tools &tool) {
    inventory->addTool(tool);
    money -= tool.getPrice();
    emit moneyChanged(money);
}


void Firefighter::heal(int heal) {
    if (heal + health >= maxHealth) {
        health = maxHealth;
    } else {
        health += heal;
    }
    emit healthChanged(health);
}
