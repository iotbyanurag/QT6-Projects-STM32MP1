#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_led = new SevenSegmentLED(this);
    m_led->setFixedSize(100, 150);  // Adjust these values as needed
    m_led->setDigit(7);  // Set initial digit to 5
    m_led->setColor(Qt::red);  // Set color to green

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_led);
    setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}
