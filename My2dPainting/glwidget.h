#ifndef GLWODGET_H
#define GLWODGET_H

#include <QWidget>

class HelpPaint;

class Glwidget : public QWidget
{
    Q_OBJECT

public:
    Glwidget(HelpPaint* hPaint, QWidget *parent = 0);
    ~Glwidget();

public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent *event);

private:
    HelpPaint* m_helpPaint;
    int m_elapsed;
};

#endif // GLWODGET_H
