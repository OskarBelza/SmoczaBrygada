#include "dragon.h"

Dragon::Dragon(const QString& name, int firePower)
    : name(name), health(150), firePower(firePower) {}

QString Dragon::getName() const {
    return name;
}

int Dragon::getHealth() const {
    return health;
}

int Dragon::getFirePower() const {
    return firePower;
}

void Dragon::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}
