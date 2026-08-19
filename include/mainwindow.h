#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QSlider>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
private slots:
    void handleButton();
    void playToPauseButton();
    void changeVolume();
private:
    QString fileName;

    QVBoxLayout *generalLayout;
    QPushButton *openButton;
    QLabel *nameLabel;

    QMediaPlayer *player;
    QAudioOutput *audioOutput;

    QWidget *centralWidget;
    QPushButton *clearButton;
    QPushButton *repeatButton;
    QPushButton *goBackButton;
    QPushButton *pauseButton;
    QHBoxLayout *controlPanelLayout;

    QSlider *volumeSlider;
};
#endif // MAINWINDOW_H
