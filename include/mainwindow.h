#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDebug>
#include "workbench.h"

class MainWindow : public QMainWindow
{
 Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton *new_workbench_btn;
    QPushButton *import_workbench_btn;
    int width;
    int height;
    int width_grid;
    int height_grid;
    int gpu_id = 0;
    bool visible;
    bool workbench_activated = false;
private:
    void loadWorkbenchWindow();
private slots:
    void onNewWorkbenchBtnClick(bool check);
    void onImportWorkbenchBtnClick(bool check);
};
#endif // MAINWINDOW_H
