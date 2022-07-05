#include "mainwindow.h"
//#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    visible = true;
    width = 480;
    height = 320;
    width_grid = width /48;
    height_grid = height /32;

    setFixedSize(width, height);
    new_workbench_btn = new QPushButton("New Workbench", this);
    new_workbench_btn->setGeometry(
        3 * width_grid,
        4 * height_grid,
        width - 6 * width_grid,
        height_grid * 10
    );


    import_workbench_btn = new QPushButton("Import Workbench", this);
    import_workbench_btn->setGeometry(
        3 * width_grid,
        19 * height_grid,
        width - 6 * width_grid,
        height_grid * 10
    );

    new_workbench_btn->setCheckable(true);
    import_workbench_btn->setCheckable(true);
    connect(new_workbench_btn, SIGNAL (clicked(bool)), this, SLOT (onNewWorkbenchBtnClick(bool)));
    connect(import_workbench_btn, SIGNAL (clicked(bool)), this, SLOT (onImportWorkbenchBtnClick(bool)));
}

MainWindow::~MainWindow()
{
    delete new_workbench_btn;
    delete import_workbench_btn;
}

void MainWindow::onNewWorkbenchBtnClick(bool check)
{
    qDebug() << "onNewWorkbenchBtnClicked";

    if(!workbench_activated){
        workbench_activated = true;
        WorkbenchWindow *new_window = new WorkbenchWindow(this, &workbench_activated);
        new_window->show();
        hide();
    }
}

void MainWindow::onImportWorkbenchBtnClick(bool check)
{
    qDebug() << "onImportWorkbenchBtnClicked";
}

