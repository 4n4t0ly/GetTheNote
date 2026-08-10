#include "../include/mainwindow.h"
constexpr int minWindowWidth = 600;
constexpr int maxWindowHeigth = 350;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(minWindowWidth, maxWindowHeigth);
    openButton = new QPushButton("Open", this);
    openButton->setGeometry(QRect(QPoint(0, 0), QSize(200, 100)));
    connect(openButton, &QPushButton::released, this, &MainWindow::handleButton);
}
void MainWindow::handleButton(){
    QString fileName = QFileDialog::getOpenFileName(this,
                                            tr("Open Audio"), "", tr("Audio Files (*.mp3)"));
}
MainWindow::~MainWindow() = default;