#include "tools.h"

Tools::Tools(const QString& name, int firePower)
    : name(name), firePower(firePower) {}

QString Tools::getName() const {
    return name;
}

int Tools::getFirePower() const {
    return firePower;
}
