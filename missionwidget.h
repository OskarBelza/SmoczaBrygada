#ifndef MISSIONWIDGET_H
#define MISSIONWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStringList>
#include <QMessageBox>

class MissionWidget : public QWidget {
    Q_OBJECT
public:
    explicit MissionWidget(QWidget *parent = nullptr);

    void setMissionDescription(const QString &description);
    void setHeroHealth(int health);
    void setHeroInventory(const QStringList &inventory);
    void configureButton(int buttonIndex, const QString &text, bool visible, const std::function<void()> &callback);
    QVBoxLayout* getMainLayout(); // Dodajemy metodę do uzyskiwania głównego layoutu

signals:
    void buttonClicked(int buttonIndex);

private:
    QLabel *missionDescriptionLabel;
    QLabel *heroHealthLabel;
    QPushButton *heroInventoryButton;
    QPushButton *buttons[3];
    QHBoxLayout *buttonLayout;
    QVBoxLayout *mainLayout;
    QStringList inventory;

    void setupLayout();

private slots:
    void showInventory();
};

#endif // MISSIONWIDGET_H
