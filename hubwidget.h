#ifndef HUBWIDGET_H
#define HUBWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class HubWidget : public QWidget {
    Q_OBJECT
public:
    explicit HubWidget(QWidget *parent = nullptr);

    void showCompletionMessage(const QString &message);

signals:
    void nextMissionButtonClicked();

private:
    QLabel *messageLabel;
    QPushButton *nextMissionButton;
};

#endif // HUBWIDGET_H
