#include "hubwidget.h"
#include <QVBoxLayout>
#include <QSpacerItem>

HubWidget::HubWidget(QWidget *parent) : QWidget(parent) {
    messageLabel = new QLabel(this);
    messageLabel->setAlignment(Qt::AlignCenter);
    messageLabel->setFixedSize(500, 150);
    messageLabel->setStyleSheet("font-size: 24px; font-weight: bold;");

    nextMissionButton = new QPushButton("Zacznij kolejną misję", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
    layout->addWidget(messageLabel, 0, Qt::AlignCenter);
    layout->addWidget(nextMissionButton, 0, Qt::AlignCenter);
    layout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
    setLayout(layout);

    connect(nextMissionButton, &QPushButton::clicked, this, &HubWidget::nextMissionButtonClicked);
}

void HubWidget::showCompletionMessage(const QString &message) {
    messageLabel->setText(message);
}
