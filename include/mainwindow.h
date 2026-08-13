#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>
#include <QHBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
private slots:
    void handleButton();
private:
    QString fileName;

    QVBoxLayout *generalLayout;
    QPushButton *openButton;
    QLabel *nameLabel;

    QWidget *centralWidget;
    QPushButton *clearButton;
    QPushButton *repeatButton;
    QPushButton *goBackButton;
    QPushButton *pauseButton;
    QHBoxLayout *controlPanelLayout;
};
#endif // MAINWINDOW_H
