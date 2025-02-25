#include "firefighter.h"

Firefighter::Firefighter(const QString& name, QObject *parent)
    : QObject(parent), name(name), health(100), experiencePoints(90), lvl(1), inventory(new Inventory(this)), money(100), maxHealth(100), rescued(0) {}

QString Firefighter::getName() const { return name; }
int Firefighter::getHealth() const { return health; }
int Firefighter::getExperiencePoints() const { return experiencePoints; }
int Firefighter::getLevel() const { return lvl; }
int Firefighter::getMoney() const { return money; }


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
        emit experienceChanged(experiencePoints);
        emit levelUp(lvl);
    }
}

void Firefighter::addMoney(int extraMoney) {
    money += extraMoney;
    emit moneyChanged(money);
}

Inventory* Firefighter::getInventory() { return inventory; }

void Firefighter::heal(int heal) {
    if (heal + health >= maxHealth) {
        health = maxHealth;
    } else {
        health += heal;
    }
    emit healthChanged(health);
}

void Firefighter::setName(const QString& newName) { name = newName; }
void Firefighter::setHealth(int newHealth) {
    health = newHealth;
    emit healthChanged(newHealth);
}
void Firefighter::setExperiencePoints(int points) {
    experiencePoints = points;
    emit experienceChanged(experiencePoints);
}
void Firefighter::setLevel(int newLevel) {
    lvl = newLevel;
    emit levelUp(newLevel);
}
void Firefighter::setMoney(int newMoney) {
    money = newMoney;
    emit moneyChanged(newMoney);
}

void Firefighter::addRescued(int newRescued) {
    rescued += newRescued;
}

QDataStream& operator<<(QDataStream& out, const Firefighter& firefighter) {
    out << firefighter.name;
    out << firefighter.health;
    out << firefighter.experiencePoints;
    out << firefighter.lvl;
    out << firefighter.money;
    out << *firefighter.inventory;
    out << firefighter.rescued;
    return out;
}

QDataStream& operator>>(QDataStream& in, Firefighter& firefighter) {
    in >> firefighter.name;
    in >> firefighter.health;
    in >> firefighter.experiencePoints;
    in >> firefighter.lvl;
    in >> firefighter.money;
    in >> *firefighter.inventory;
    in << firefighter.rescued;
    return in;
}
