#ifndef COMMONWIDGET_H
#define COMMONWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QStringList>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

class CommonWidget : public QWidget {
    Q_OBJECT
public:
    explicit CommonWidget(QWidget *parent = nullptr);

    void setHeroHealth(int health);
    void setHeroInventory(const QStringList &inventory);
    void setHeroGold(int gold);
    void setHeroExperience(int experience);

private slots:
    void showInventory();

private:
    QLabel *heroHealthLabel;
    QLabel *heroGoldLabel;
    QLabel *heroExperienceLabel;
    QPushButton *heroInventoryButton;
    QStringList inventory;
    int gold;
    int experience;
};

#endif // COMMONWIDGET_H
