#include "../include/mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    openButton = new QPushButton("Open", this);
    openButton->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));
    connect(openButton, &QPushButton::released, this, &MainWindow::handleButton);
}
void MainWindow::handleButton(){
    openButton->setText("Add track");
    openButton->resize(100,100);
}
MainWindow::~MainWindow() = default;
