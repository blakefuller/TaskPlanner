#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCurrentDate();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_hwIcon_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_dashIcon_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_taskIcon_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_submitTaskButton_clicked()
{
    //gather the tasks from the user and put them in a string
    QString task1 = ui->taskLine1->text();
    QString task2 = ui->taskLine2->text();
    QString task3 = ui->taskLine3->text();
    QString task4 = ui->taskLine4->text();
    QString task5 = ui->taskLine5->text();
    QString taskclear = "";

    //clear the current tasks
    ui->taskLabel1->setText(taskclear);
    ui->taskLabel2->setText(taskclear);
    ui->taskLabel3->setText(taskclear);
    ui->taskLabel4->setText(taskclear);
    ui->taskLabel5->setText(taskclear);


    //make it so the tasks are always ordered from top to bottom
    if (task1.length() == 0)
    {
        if(task2.length() != 0)
        {
            task1 = task2;
            task2 = task3;
            task3 = task4;
            task4 = task5;
            task5 = taskclear;
        }
        else if(task3.length() != 0)
        {
            task1 = task3;
            task3 = task4;
            task4 = task5;
            task5 = taskclear;
        }
        else if(task4.length() != 0)
            {
            task1 = task4;
            task4 = task5;
            task5 = taskclear;
            }
        else if(task5.length() != 0)
            task1 = task5;
            task5 = taskclear;
    }

    if (task2.length() == 0)
    {
        if(task3.length() != 0)
        {
            task2 = task3;
            task3 = task4;
            task4 = task5;
            task5 = taskclear;
        }
        else if(task4.length() != 0)
            {
            task2 = task4;
            task4 = task5;
            task5 = taskclear;
            }
        else if(task5.length() != 0)
            task2 = task5;
            task5 = taskclear;
    }

    if (task3.length() == 0)
    {
        if(task4.length() != 0)
           {
            task3 = task4;
            task4 = task5;
            task5 = taskclear;
           }
        else if(task5.length() != 0)
            task3 = task5;
            task5 = taskclear;
    }
    if (task4.length() == 0)
    {
     if(task5.length() != 0)
            task4 = task5;
            task5 = taskclear;
    }

//paste the tasks
    ui->taskLabel1->setText(task1);
    ui->taskLabel2->setText(task2);
    ui->taskLabel3->setText(task3);
    ui->taskLabel4->setText(task4);
    ui->taskLabel5->setText(task5);
}

void MainWindow::on_addButton_clicked()
{

}

void MainWindow::setCurrentDate()
{
    QDate date = QDate::currentDate();

    QString dateString = date.toString("ddd MMMM dd yyyy");

    ui->dateLabel->setText(dateString);
    ui->dateLabel2->setText(dateString);
    ui->dateLabel3->setText(dateString);

}
