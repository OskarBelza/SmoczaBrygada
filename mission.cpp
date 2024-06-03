#ifndef MISSION_H
#define MISSION_H

#include <QString>

class Mission {
public:
    virtual ~Mission() = default;

    virtual QString getDescription() const = 0;
    virtual void start() = 0;
};

#endif // MISSION_H
