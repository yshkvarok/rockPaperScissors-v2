#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QApplication>
#include <QTime>
#include <QtGlobal>
#include <QMessageBox>
#include <QLCDNumber>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Ui::MainWindow *lcdNumber;
    void mainGame(QString userChoice);
    QString getCompChoice();
};

#endif // MAINWINDOW_H
