#include "../include/mainwindow.h"
constexpr unsigned short int minWindowWidth = 600;
constexpr unsigned short int minWindowHeigth = 350;
constexpr unsigned short int volumeDivider = 9801;
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
    goBackButton = new QPushButton("Go Back");
    pauseButton = new QPushButton("...");
    repeatButton = new QPushButton("Repeat");
    volumeSlider = new QSlider(Qt::Horizontal);

    connect(pauseButton, &QPushButton::released, this, &MainWindow::playToPauseButton);
    connect(volumeSlider, &QSlider::valueChanged, this, &MainWindow::changeVolume);

    controlPanelLayout->addWidget(clearButton);
    controlPanelLayout->addWidget(goBackButton);
    controlPanelLayout->addWidget(pauseButton);
    controlPanelLayout->addWidget(repeatButton);
    controlPanelLayout->addWidget(volumeSlider);

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
    if(!state && !fileName.isEmpty()){
        pauseButton->setText("Pause");
        changeVolume();
        player->play();
    }
    else if(!fileName.isEmpty()){
        pauseButton->setText("Resume");
        player->pause();
    }
}
void MainWindow::changeVolume(){
    audioOutput->setVolume(pow(float(volumeSlider->value()),2)/volumeDivider);
}
MainWindow::~MainWindow() = default;