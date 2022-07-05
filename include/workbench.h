#ifndef WORKBENCH_H
#define WORKBENCH_H

#include <QWidget>
#include <QWindow>
#include <QVulkanInstance>
#include <QDebug>

class WorkbenchWindow : public QWidget
{
Q_OBJECT
public:
    explicit WorkbenchWindow(QWidget *parent, bool *activated);
private :
    QWidget *upper_widget=nullptr;
    int width;
    int height;
    QSize vk_surface_size;
    bool *activated;
    void resizeEvent(QResizeEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
};

#endif // WORKBENCH_H
