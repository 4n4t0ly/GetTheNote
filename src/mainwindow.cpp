#include "../include/mainwindow.h"
constexpr unsigned short int minWindowWidth = 600;
constexpr unsigned short int minWindowHeigth = 350;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){
    setMinimumSize(minWindowWidth, minWindowHeigth);
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    generalLayout = new QVBoxLayout(centralWidget);
    controlPanelLayout = new QHBoxLayout();

    openButton = new QPushButton("Open");
    nameLabel = new QLabel(fileName);

    generalLayout->addWidget(openButton);
    generalLayout->addWidget(nameLabel);
    generalLayout->addLayout(controlPanelLayout);
    connect(openButton, &QPushButton::released, this, &MainWindow::handleButton);

    clearButton = new QPushButton("Clear");
    repeatButton = new QPushButton("Play");
    goBackButton = new QPushButton("Go Back");
    pauseButton = new QPushButton("...");

    connect(pauseButton, &QPushButton::released, this, &MainWindow::playToPauseButton);

    controlPanelLayout->addWidget(clearButton);
    controlPanelLayout->addWidget(repeatButton);
    controlPanelLayout->addWidget(goBackButton);
    controlPanelLayout->addWidget(pauseButton);

    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
}
void MainWindow::handleButton(){
    fileName = QFileDialog::getOpenFileName(this,
                                            tr("Open Audio"),
                                            "",
                                            tr("Audio Files (*.mp3)"));
    if(!fileName.isEmpty())
        nameLabel->setText(fileName);
    pauseButton->setText("Play");
    player->setSource(fileName);
}
void MainWindow::playToPauseButton(){
    bool state = player->isPlaying();
    if(!state){
        pauseButton->setText("Pause");
        player->play();
    }
    else{
        pauseButton->setText("Resume");
        player->pause();
    }
}
MainWindow::~MainWindow() = default;