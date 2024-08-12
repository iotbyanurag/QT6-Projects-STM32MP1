#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QColor>  // Include QColor for handling colors

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void changeColor();  // Slot to change color

private:
    Ui::Widget *ui;
    QColor currentColor;  // Store the current color of the shape
};

#endif // WIDGET_H
