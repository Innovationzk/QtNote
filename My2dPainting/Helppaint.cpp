#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QFont>
#include <QPaintEvent>
#include "Helppaint.h"

HelpPaint::HelpPaint(QObject *parent) : QObject(parent)
{
    QLinearGradient lineargradient(0, 0, 120, 0);
    lineargradient.setColorAt(0, Qt::white);
    lineargradient.setColorAt(1, QColor(0xa6, 0xce, 0x39));

    m_circleBrush = new QBrush(lineargradient);

//    QLinearGradient *lineargradient = new QLinearGradient(0, 0, 120, 0);
//    lineargradient->setColorAt(0, Qt::white);
//    lineargradient->setColorAt(1, QColor(0xa6, 0xce, 0x39));

//    m_circleBrush = new QBrush(*lineargradient);

//    delete lineargradient;

    m_circlePen = new QPen(Qt::black);
    m_circlePen->setWidth(1);
    m_textPen = new QPen(Qt::white);
    m_textPen->setWidth(4);
    m_font = new QFont;
    m_font->setPixelSize(50);
}

void HelpPaint::paint(QPaintEvent *event, QPainter *painter, int m_elapsed)
{
    painter->fillRect(event->rect(), QColor(64, 32, 64));
    painter->translate(100,100);

    painter->save();
    painter->rotate(m_elapsed / 1000.0 * 30);

    // draw circles
    painter->setBrush(*m_circleBrush);
    painter->setPen(*m_circlePen);
    for (int i=1; i <= 30; i++) {
        painter->rotate(30);
        double factor = m_elapsed / 1000.0 + i;
        painter->drawEllipse(QPointF(factor*4.7, 0),factor*0.73, factor*0.73);
    }
    painter->restore();

    painter->setPen(*m_textPen);
    painter->setFont(*m_font);
    painter->drawText(QRect(-50, -50, 100, 100),Qt::AlignCenter, "Qt");
}
