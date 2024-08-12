#include "widget.h"
#include "ui_widget.h"
#include <QPalette>  // Include QPalette for changing colors

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , currentColor(Qt::black)  // Initialize with black color
{
    ui->setupUi(this);

    // Set initial color of the QLabel to black
    QPalette palette = ui->colorLabel->palette();
    palette.setColor(QPalette::Window, currentColor);
    ui->colorLabel->setAutoFillBackground(true);
    ui->colorLabel->setPalette(palette);

    // Set initial size of the QLabel to form a square or circle
    ui->colorLabel->setFixedSize(100, 100);

    // Connect button signal to the slot
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::changeColor);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeColor()
{
    // Toggle between black and red color
    if (currentColor == Qt::black)
        currentColor = Qt::red;
    else
        currentColor = Qt::black;

    // Update the QLabel color
    QPalette palette = ui->colorLabel->palette();
    palette.setColor(QPalette::Window, currentColor);
    ui->colorLabel->setPalette(palette);
}
