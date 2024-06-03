#ifndef MISSION_H
#define MISSION_H

#include <QString>
#include <QObject>
#include <functional>

class Mission : public QObject {
    Q_OBJECT
public:
    explicit Mission(QObject *parent = nullptr) : QObject(parent) {}
    virtual QString getDescription() const = 0;
    virtual void start() = 0;

signals:
    void updateMissionStatus(const QString &status);
    void configureButton(int buttonIndex, const QString &text, bool visible, const std::function<void()> &callback);
    void missionCompleted();
};

#endif // MISSION_H
