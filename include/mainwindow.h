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
    void goBackButtonPress();
    void pauseButtonPress();
    void repeatButtonPress();
    void changeVolume();
private:
    QString fileName;
    bool repeat = true,
         playerStatus = false;

    QVBoxLayout *generalLayout;
    QPushButton *openButton;
    QLabel *nameLabel;

    QMediaPlayer *player;
    QAudioOutput *audioOutput;

    QWidget *centralWidget;
    QPushButton *clearButton, *repeatButton,
                *goBackButton, *pauseButton;
    QHBoxLayout *controlPanelLayout;

    QSlider *volumeSlider;
};
#endif // MAINWINDOW_H
