#ifndef TOOLS_H
#define TOOLS_H

#include <QString>

class Tools {
public:
    Tools(const QString& name, int firePower);

    QString getName() const;
    int getFirePower() const;

private:
    QString name;
    int firePower;
};

#endif
