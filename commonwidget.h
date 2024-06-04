#ifndef COMMONWIDGET_H
#define COMMONWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QStringList>
#include <QMessageBox>
#include <QHBoxLayout>

class CommonWidget : public QWidget {
    Q_OBJECT
public:
    explicit CommonWidget(QWidget *parent = nullptr);

    void setHeroHealth(int health);
    void setHeroInventory(const QStringList &inventory);

private slots:
    void showInventory();

private:
    QLabel *heroHealthLabel;
    QPushButton *heroInventoryButton;
    QStringList inventory;
};

#endif // COMMONWIDGET_H
