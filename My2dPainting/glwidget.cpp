#include <QPainter>
#include <QTimer>
#include <QPaintEvent>
#include "glwidget.h"
#include "Helppaint.h"

Glwidget::Glwidget(HelpPaint* hPaint, QWidget *parent)
    : QWidget(parent)
    , m_helpPaint(hPaint)
    , m_elapsed(0)
{
    setFixedSize(200, 200);
}

Glwidget::~Glwidget()
{

}

void Glwidget::animate()
{
    m_elapsed = (m_elapsed + qobject_cast<QTimer*>(sender())->interval()) % 1000;
    update();
}

void Glwidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
//    painter.fillRect(event->rect(), QColor(64, 32, 64));
//    painter.translate(100,100);

//    painter.save();
//    painter.rotate(m_elapsed / 1000.0 * 30);

//    // draw circles
//    painter.setBrush(*circleBrush);
//    painter.setPen(*m_circlePen);
//    for (int i=1; i <= 30; i++) {
//        painter.rotate(30);
//        double factor = m_elapsed / 1000.0 + i;
//        painter.drawEllipse(QPointF(factor*4.7, 0),factor*0.73, factor*0.73);
//    }
//    painter.restore();

//    painter.setPen(*m_textPen);
//    painter.setFont(*m_font);
//    painter.drawText(QRect(-50, -50, 100, 100),Qt::AlignCenter, "Qt");
    m_helpPaint->paint(event, &painter, m_elapsed);
}
