// firefighter.h

#ifndef FIREFIGHTER_H
#define FIREFIGHTER_H

#include <QObject>
#include <QString>
#include "inventory.h"
#include "tool.h"

class Firefighter : public QObject {
    Q_OBJECT
public:
    Firefighter(const QString& name, QObject *parent = nullptr);

    QString getName() const;
    int getHealth() const;
    int getExperiencePoints() const;
    int getLevel() const;
    int getMoney() const;

    void takeDamage(int damage);
    void addExperience(int points);
    void addMoney(int extraMoney);
    Inventory* getInventory();
    void buyTool(Tools &tool);
    void heal(int heal);

signals:
    void healthChanged(int health);
    void experienceChanged(int experiencePoints);
    void levelUp(int lvl);
    void moneyChanged(int money);

private:
    QString name;
    int health;
    int experiencePoints;
    int lvl;
    Inventory *inventory;
    int money;
    int maxHealth;
};

#endif // FIREFIGHTER_H
