#include "tool.h"

Tools::Tools(const QString& name, int firePower, int level, int quantity, const QString& description, bool consumable, const int price)
    : name(name), firePower(firePower), level(level), quantity(quantity), description(description), consumable(consumable), price(price) {}

QString Tools::getName() const { return name; }
int Tools::getFirePower() const { return firePower; }
int Tools::getLevel() const { return level; }
int Tools::getQuantity() const { return quantity; }
QString Tools::getDescription() const { return description; }
bool Tools::isConsumable() const { return consumable; }
bool Tools::isUsable() const { return quantity > 0; }
int Tools::getPrice() const { return price; }

void Tools::setQuantity(int quantity) { this->quantity = quantity; }
void Tools::levelUp() { level++; updateFirePower(); }

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
    firePower = firePower + (level * 10);
}

QDataStream& operator<<(QDataStream& out, const Tools& tool) {
    out << tool.name << tool.firePower << tool.level << tool.quantity << tool.description << tool.consumable << tool.price;
    return out;
}

QDataStream& operator>>(QDataStream& in, Tools& tool) {
    in >> tool.name >> tool.firePower >> tool.level >> tool.quantity >> tool.description >> tool.consumable >> tool.price;
    return in;
}
