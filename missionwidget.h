#ifndef MISSIONWIDGET_H
#define MISSIONWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStringList>
#include <QMessageBox>
#include "commonwidget.h"

class MissionWidget : public QWidget {
    Q_OBJECT
public:
    explicit MissionWidget(QWidget *parent = nullptr);

    void setMissionDescription(const QString &description);
    void configureButton(int buttonIndex, const QString &text, bool visible, const std::function<void()> &callback);
    QVBoxLayout* getMainLayout(); // Dodajemy metodę do uzyskiwania głównego layoutu

    void setHeroHealth(int health) { commonWidget->setHeroHealth(health); }
    void setHeroInventory(const QStringList &inventory) { commonWidget->setHeroInventory(inventory); }
    void setHeroGold(int gold) { commonWidget->setHeroGold(gold); }
    void setHeroExperience(int experience) { commonWidget->setHeroExperience(experience); }

signals:
    void buttonClicked(int buttonIndex);

private:
    QLabel *missionDescriptionLabel;
    QPushButton *buttons[3];
    QHBoxLayout *buttonLayout;
    QVBoxLayout *mainLayout;
    CommonWidget *commonWidget;

    void setupLayout();
};

#endif // MISSIONWIDGET_H
