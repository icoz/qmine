#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setObjectName("MainWindow");
    setStatusBar(new QStatusBar(this));
    setCentralWidget(new Scene(this));
    resize(800,600);
    centralWidget()->setFocus();
}

MainWindow::~MainWindow()
{
}
