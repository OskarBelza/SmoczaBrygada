#include "tools.h"

Tools::Tools(const QString& name, int firePower, int level, int quantity, const QString& description, bool consumable, bool usable)
    : name(name), firePower(firePower), level(level), quantity(quantity), description(description), consumable(consumable), usable(usable) {}

QString Tools::getName() const {
    return name;
}

int Tools::getFirePower() const {
    return firePower;
}

int Tools::getLevel() const {
    return level;
}

int Tools::getQuantity() const {
    return quantity;
}

QString Tools::getDescription() const {
    return description;
}

bool Tools::isConsumable() const {
    return consumable;
}

bool Tools::isUsable() const {
    return usable;
}

void Tools::setQuantity(int quantity) {
    this->quantity = quantity;
}

void Tools::levelUp() {
    level++;
    updateFirePower();
}

bool Tools::use() {
    if (consumable) {
        if (quantity > 0) {
            quantity--;
            return true;
        } else {
            return false;
        }
    }
    return true;
}

void Tools::updateFirePower() {
    firePower = firePower + (level * 10);  // Example increment strategy, can be adjusted
}
