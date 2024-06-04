#include "commonwidget.h"

CommonWidget::CommonWidget(QWidget *parent) : QWidget(parent) {
    heroHealthLabel = new QLabel(this);
    heroInventoryButton = new QPushButton("Show Inventory", this);

    heroHealthLabel->setFixedSize(450, 50);
    heroHealthLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    heroHealthLabel->setStyleSheet("font-size: 16px; color: red; font-weight: bold;");

    heroInventoryButton->setFixedSize(100, 40);

    connect(heroInventoryButton, &QPushButton::clicked, this, &CommonWidget::showInventory);

    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(heroHealthLabel);
    topLayout->addWidget(heroInventoryButton);

    setLayout(topLayout);
}

void CommonWidget::setHeroHealth(int health) {
    heroHealthLabel->setText("Health: " + QString::number(health));
}

void CommonWidget::setHeroInventory(const QStringList &inventory) {
    this->inventory = inventory;
}

void CommonWidget::showInventory() {
    QMessageBox::information(this, "Inventory", "Items: " + inventory.join(", "));
}
