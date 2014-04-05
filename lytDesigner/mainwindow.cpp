#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    window = new LayerWindow();
    this->setCentralWidget(window);
}

MainWindow::~MainWindow()
{

}
