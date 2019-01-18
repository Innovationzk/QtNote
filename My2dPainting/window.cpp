#include <QTimer>
#include <QGridLayout>
#include <QLabel>
#include "window.h"
#include "widget.h"
#include "glwidget.h"
#include "Helppaint.h"

Window::Window(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("My2dPainting");

    m_helpPaint = new HelpPaint(this);
    m_widget = new Widget(m_helpPaint, this);
    m_glwidget = new Glwidget(m_helpPaint, this);
    m_labelNative = new QLabel(this);
    m_labelNative->setText("Native");
    m_labelGlwidget = new QLabel(this);
    m_labelGlwidget->setText("Glwidget");

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(m_widget, 0, 0);
    gridLayout->addWidget(m_glwidget, 0, 1);
    gridLayout->addWidget(m_labelNative, 1, 0, Qt::AlignCenter);
    gridLayout->addWidget(m_labelGlwidget, 1, 1, Qt::AlignCenter);

    setLayout(gridLayout);

    m_timer = new QTimer(this);
    m_timer->setInterval(10);
    m_timer->start();
    connect(m_timer, SIGNAL(timeout()), m_widget, SLOT(animate()));
    connect(m_timer, SIGNAL(timeout()), m_glwidget, SLOT(animate()));
}
