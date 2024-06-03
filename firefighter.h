#ifndef FIREFIGHTER_H
#define FIREFIGHTER_H

#include <QString>
#include <QObject>
#include "inventory.h"

class Firefighter : public QObject {
    Q_OBJECT
public:
    explicit Firefighter(const QString& name, QObject *parent = nullptr);

    QString getName() const;
    int getHealth() const;
    int getExperiencePoints() const;
    void takeDamage(int damage);
    void addExperience(int points);
    Inventory* getInventory();

signals:
    void healthChanged(int newHealth);

private:
    QString name;
    int health;
    int experiencePoints;
    Inventory* inventory; // Use Inventory* instead of Inventory
};

#endif // FIREFIGHTER_H
