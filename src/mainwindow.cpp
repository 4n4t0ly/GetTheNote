#include "../include/mainwindow.h"
constexpr int minWindowWidth = 600;
constexpr int minWindowHeigth = 350;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){
    setMinimumSize(minWindowWidth, minWindowHeigth);
    openButton = new QPushButton("Open", this);
    openButton->setGeometry(QRect(QPoint(0, 0), QSize(200, 100)));
    nameLabel = new QLabel(fileName, this);
    nameLabel->setGeometry(QRect(QPoint(200,200),QSize(100,100)));
    connect(openButton, &QPushButton::released, this, &MainWindow::handleButton);
}
void MainWindow::handleButton(){
    fileName = QFileDialog::getOpenFileName(this,
                                            tr("Open Audio"),
                                            "",
                                            tr("Audio Files (*.mp3)"));
    if(!fileName.isEmpty())
        nameLabel->setText(fileName);
}
MainWindow::~MainWindow() = default;