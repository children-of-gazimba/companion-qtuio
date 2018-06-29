#include "main_window.h"

#include <QHostAddress>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    widget_ = new MainWidget(this);
    setCentralWidget(widget_);
}

MainWindow::~MainWindow()
{

}
