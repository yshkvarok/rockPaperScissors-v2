#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // rock

    QString userChoice = "rock";
    mainGame(userChoice);
}

void MainWindow::on_pushButton_2_clicked()
{
    // paper

    QString userChoice = "paper";
    mainGame(userChoice);
}

void MainWindow::on_pushButton_3_clicked()
{
    // scissors

    QString userChoice = "scissors";
    mainGame(userChoice);
}

QString MainWindow::getCompChoice()
{
    QString compChoice;

    QTime time = QTime::currentTime();
    qsrand(time.msec());
    int randNum = qrand() % 3;

    switch (randNum)
    {
        case 0:
        {
            compChoice = "rock";
            break;
        }
        case 1:
        {
            compChoice = "paper";
            break;
        }
        case 2:
        {
            compChoice = "scissors";
            break;
        }
    }

    return compChoice;
}

void MainWindow::mainGame(QString userChoice)
{
    QString compChoice = MainWindow::getCompChoice();

    if (userChoice == "rock")
    {
        if (compChoice == "rock")
        {
            QMessageBox::information(this, "Results", "Tie! Computer also picked rock.");
            ui->lcdNumber_4->display(ui->lcdNumber_4->intValue() + 1);
        }
        else if (compChoice == "paper")
        {
            QMessageBox::information(this, "Results", "You lose. Computer picked paper.");
            ui->lcdNumber_3->display(ui->lcdNumber_3->intValue() + 1);
        }
        if (compChoice == "scissors")
        {
            QMessageBox::information(this, "Results", "You win! Computer picked scissors.");
            ui->lcdNumber_2->display(ui->lcdNumber_2->intValue() + 1);
        }
    }

    else if (userChoice == "paper")
    {
        if (compChoice == "rock")
        {
            QMessageBox::information(this, "Results", "You win! Computer picked rock.");
            ui->lcdNumber_2->display(ui->lcdNumber_2->intValue() + 1);
        }
        else if (compChoice == "paper")
        {
            QMessageBox::information(this, "Results", "Tie! Computer also picked paper.");
            ui->lcdNumber_4->display(ui->lcdNumber_4->intValue() + 1);
        }
        if (compChoice == "scissors")
        {
            QMessageBox::information(this, "Results", "You lose! Computer picked scissors.");
            ui->lcdNumber_3->display(ui->lcdNumber_3->intValue() + 1);
        }
    }

    else if (userChoice == "scissors")
    {
        if (compChoice == "rock")
        {
            QMessageBox::information(this, "Results", "You lose! Computer picked rock.");
            ui->lcdNumber_3->display(ui->lcdNumber_3->intValue() + 1);
        }
        else if (compChoice == "paper")
        {
            QMessageBox::information(this, "Results", "You win! Computer also picked scissors.");
            ui->lcdNumber_2->display(ui->lcdNumber_2->intValue() + 1);
        }
        if (compChoice == "scissors")
        {
            QMessageBox::information(this, "Results", "Tie! Computer also picked scissors.");
            ui->lcdNumber_4->display(ui->lcdNumber_4->intValue() + 1);
        }
    }

    ui->lcdNumber->display(ui->lcdNumber->intValue() + 1);
}
