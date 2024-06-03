#ifndef FIREFIGHTER_H
#define FIREFIGHTER_H

#include <QString>
#include <QObject>
#include <QVector>
#include "tools.h"


class Firefighter : public QObject {
    Q_OBJECT
public:
    explicit Firefighter(const QString& name, QObject *parent = nullptr);

    QString getName() const;
    int getHealth() const;
    int getExperiencePoints() const;
    void takeDamage(int damage);
    void addExperience(int points);
    void addTool(const Tools& tool);
    Tools* getTool(const QString& toolName);
    QVector<Tools> getTools() const;

signals:
    void healthChanged(int newHealth);
    void inventoryChanged();

private:
    QString name;
    int health;
    int experiencePoints;
    QVector<Tools> tools; // Adding the tools member
};

#endif // FIREFIGHTER_H
