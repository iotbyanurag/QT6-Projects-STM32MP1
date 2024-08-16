#ifndef SEVENSEGMENTLED_H
#define SEVENSEGMENTLED_H

#include <QWidget>
#include <QColor>

class SevenSegmentLED : public QWidget
{
    Q_OBJECT

public:
    explicit SevenSegmentLED(QWidget *parent = nullptr);

    void setDigit(int digit);
    void setColor(const QColor &color);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int m_digit;
    QColor m_color;
    static const QVector<QVector<bool>> SEGMENT_MAP;
};

#endif // SEVENSEGMENTLED_H
