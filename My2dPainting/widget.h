#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class HelpPaint;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(HelpPaint* hPaint,QWidget *parent = 0);
    ~Widget();

public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent *event);

private:
    HelpPaint* m_helpPaint;
    int m_elapsed;
};

#endif // WIDGET_H
