#include "mainwindow.h"
#include "preview.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Preview *p = new Preview;
    setCentralWidget(p);
}

MainWindow::~MainWindow()
{

}
