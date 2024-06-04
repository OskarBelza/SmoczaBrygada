#ifndef TOOL_H
#define TOOL_H

#include <QString>

class Tools {
public:
    Tools(const QString& name, int firePower, int level = 1, int quantity = 1, const QString& description = "", bool consumable = false, const int price = 100);

    QString getName() const;
    int getFirePower() const;
    int getLevel() const;
    int getQuantity() const;
    QString getDescription() const;
    bool isConsumable() const;
    bool isUsable() const;
    int getPrice() const;

    void setQuantity(int quantity);
    void levelUp();
    bool use();

private:
    QString name;
    int firePower;
    int level;
    int quantity;
    QString description;
    bool consumable;
    int price;

    void updateFirePower();
};

#endif // TOOL_H
