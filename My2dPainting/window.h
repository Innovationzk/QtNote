#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QTimer;
class Widget;
class Glwidget;
class HelpPaint;
class QLabel;

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = 0);

signals:

public slots:

private:
    QTimer* m_timer;
    QLabel* m_labelNative;
    QLabel* m_labelGlwidget;
    Widget* m_widget;
    Glwidget* m_glwidget;
    HelpPaint* m_helpPaint;
};

#endif // WINDOW_H
