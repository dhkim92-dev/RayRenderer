#ifndef WORKBENCH_CPP
#define WORKBENCH_CPP

#include "workbench.h"

#define WORKBENCH_RATIO (9/16.0)

WorkbenchWindow::WorkbenchWindow(QWidget *parent, bool *activated) : upper_widget(parent) , activated(activated)
{
    width = 1366;
    height = 768;
    setMinimumHeight(720);
    setMinimumWidth(1280);
    QSize size = {width, height};
    setBaseSize(size);
}

void WorkbenchWindow::resizeEvent(QResizeEvent *event)
{
    QSize size = this->size();

    size.setHeight(size.width() * WORKBENCH_RATIO);
    resize(size);
    //qDebug() << "window size : " << size.width() << ", " << size.height();
}

void WorkbenchWindow::closeEvent(QCloseEvent *event)
{
    upper_widget->show();
    *activated = false;
}

#endif
