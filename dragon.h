#ifndef DRAGON_H
#define DRAGON_H

#include <QString>

class Dragon {
public:
    Dragon(const QString& name, int firePower);

    QString getName() const;
    int getHealth() const;
    int getFirePower() const;

    void takeDamage(int damage);

private:
    QString name;
    int health;
    int firePower;
};

#endif // DRAGON_H
