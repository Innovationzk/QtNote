#ifndef HELPPAINT_H
#define HELPPAINT_H

#include <QObject>

class QPaintEvent;
class QPainter;
class QPen;
class QBrush;
class QFont;

class HelpPaint : public QObject
{
    Q_OBJECT
public:
    explicit HelpPaint(QObject *parent = 0);
    void paint(QPaintEvent* event, QPainter* painter, int m_elapsed);

signals:

public slots:

private:
    QPen* m_circlePen;
    QPen* m_textPen;
    QFont* m_font;
    QBrush* m_circleBrush;
};

#endif // HELPPAINT_H
