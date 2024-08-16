#include "sevensegmentled.h"
#include <QPainter>

const QVector<QVector<bool>> SevenSegmentLED::SEGMENT_MAP = {
    {1,1,1,0,1,1,1}, // 0
    {0,0,1,0,0,1,0}, // 1
    {1,0,1,1,1,0,1}, // 2
    {1,0,1,1,0,1,1}, // 3
    {0,1,1,1,0,1,0}, // 4
    {1,1,0,1,0,1,1}, // 5
    {1,1,0,1,1,1,1}, // 6
    {1,0,1,0,0,1,0}, // 7
    {1,1,1,1,1,1,1}, // 8
    {1,1,1,1,0,1,1}  // 9
};

SevenSegmentLED::SevenSegmentLED(QWidget *parent)
    : QWidget(parent), m_digit(0), m_color(Qt::red)
{
    setMinimumSize(50, 100);
}

void SevenSegmentLED::setDigit(int digit)
{
    if (digit >= 0 && digit <= 9) {
        m_digit = digit;
        update();
    }
}

void SevenSegmentLED::setColor(const QColor &color)
{
    m_color = color;
    update();
}

void SevenSegmentLED::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int width = this->width();
    int height = this->height();
    int segmentWidth = width / 10;
    int segmentLength = height / 2 - segmentWidth;
    int gap = segmentWidth / 2;

    QVector<QPoint> segmentPositions = {
        QPoint(gap, 0),                                 // top
        QPoint(width - segmentWidth, gap),              // top-right
        QPoint(width - segmentWidth, height/2 + gap),   // bottom-right
        QPoint(gap, height - segmentWidth),             // bottom
        QPoint(0, height/2 + gap),                      // bottom-left
        QPoint(0, gap),                                 // top-left
        QPoint(gap, height/2 - segmentWidth/2)          // middle
    };

    QVector<Qt::Orientation> segmentOrientations = {
        Qt::Horizontal, Qt::Vertical, Qt::Vertical,
        Qt::Horizontal, Qt::Vertical, Qt::Vertical,
        Qt::Horizontal
    };

    for (int i = 0; i < 7; ++i) {
        QColor segmentColor = SEGMENT_MAP[m_digit][i] ? m_color : m_color.darker(700);
        painter.setPen(Qt::NoPen);
        painter.setBrush(segmentColor);

        if (segmentOrientations[i] == Qt::Horizontal) {
            painter.drawRoundedRect(QRect(segmentPositions[i], QSize(width - 2*gap, segmentWidth)),
                                    segmentWidth/2, segmentWidth/2);
        } else {
            painter.drawRoundedRect(QRect(segmentPositions[i], QSize(segmentWidth, segmentLength)),
                                    segmentWidth/2, segmentWidth/2);
        }
    }
}
