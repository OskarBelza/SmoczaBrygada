#include "missionwidget.h"

MissionWidget::MissionWidget(QWidget *parent) : QWidget(parent) {
    missionDescriptionLabel = new QLabel(this);
    buttonLayout = new QHBoxLayout();
    mainLayout = new QVBoxLayout(this);
    commonWidget = new CommonWidget(this);

    missionDescriptionLabel->setFixedSize(550, 200);
    missionDescriptionLabel->setAlignment(Qt::AlignCenter);
    missionDescriptionLabel->setStyleSheet("font-size: 18px; font-weight: bold;");
    missionDescriptionLabel->setWordWrap(true);

    for (int i = 0; i < 3; ++i) {
        buttons[i] = new QPushButton(this);
        buttons[i]->setFixedSize(180, 50);
        buttons[i]->hide();
        buttonLayout->addWidget(buttons[i]);
        connect(buttons[i], &QPushButton::clicked, this, [this, i]() { emit buttonClicked(i); });
    }

    setupLayout();
}

void MissionWidget::setMissionDescription(const QString &description) {
    missionDescriptionLabel->setText(description);
}

void MissionWidget::configureButton(int buttonIndex, const QString &text, bool visible, const std::function<void()> &callback) {
    if (buttonIndex < 0 || buttonIndex >= 3) return;

    buttons[buttonIndex]->setText(text);
    buttons[buttonIndex]->setVisible(visible);

    disconnect(buttons[buttonIndex], &QPushButton::clicked, nullptr, nullptr);
    connect(buttons[buttonIndex], &QPushButton::clicked, this, [callback]() { callback(); });
}

QVBoxLayout* MissionWidget::getMainLayout() {
    return mainLayout;
}

void MissionWidget::setupLayout() {
    mainLayout->addWidget(commonWidget);
    mainLayout->addWidget(missionDescriptionLabel, 0, Qt::AlignCenter);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);
}
