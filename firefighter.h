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
    int getLevel() const; // Nowa metoda zwracająca poziom
    void takeDamage(int damage);
    void addExperience(int points);
    Inventory* getInventory();

signals:
    void healthChanged(int newHealth);
    void levelUp(int newLevel); // Nowy sygnał informujący o awansie na nowy poziom

private:
    QString name;
    int health;
    int experiencePoints;
    int lvl; // Nowe pole przechowujące poziom
    Inventory* inventory; // Użyj Inventory* zamiast Inventory
};

#endif // FIREFIGHTER_H
