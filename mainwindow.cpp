#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCurrentDate();
    ui->addWidget->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
    tasks.clear();
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

void MainWindow::on_taskDate1_userDateChanged(const QDate &date)
{

    date1 = date;
}

void MainWindow::on_taskDate2_userDateChanged(const QDate &date)
{
    date2 = date;
}

void MainWindow::on_taskDate3_userDateChanged(const QDate &date)
{
    date3 = date;
}

void MainWindow::on_taskDate4_userDateChanged(const QDate &date)
{
    date4 = date;
}

void MainWindow::on_taskDate5_userDateChanged(const QDate &date)
{
    date5 = date;
}

void MainWindow::on_submitTaskButton_clicked()
{
    tasks.append(ui->taskLine1->text());
    ui->taskLabel4->setText(tasks.last());

    //gather the tasks from the user and put them in a string
//    task1 = ui->taskLine1->text();
//    task2 = ui->taskLine2->text();
//    task3 = ui->taskLine3->text();
//    task4 = ui->taskLine4->text();
//    task5 = ui->taskLine5->text();
    QString taskclear = "";



    //clear the current tasks
//    ui->taskLabel1->setText(taskclear);
//    ui->taskLabel2->setText(taskclear);
//    ui->taskLabel3->setText(taskclear);
//    ui->taskLabel4->setText(taskclear);
//    ui->taskLabel5->setText(taskclear);




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

    this->dueDateChecker();
}

void MainWindow::on_addButton_clicked()
{
    if(!ui->addWidget->isVisible())
    {
        ui->addWidget->show();
    }
    else
    {
        ui->addWidget->hide();
    }
}

void MainWindow::setCurrentDate()
{
    // get system date
    curDate = QDate::currentDate();

    dateString = curDate.toString("ddd MMMM dd yyyy");

    //display system date
    ui->dateLabel->setText(dateString);
    ui->dateLabel2->setText(dateString);
    ui->dateLabel3->setText(dateString);

}

// checks if tasks are due
// sends message box if so
void MainWindow::dueDateChecker()
{
    QString dueTasks = "";

    if(task1 != "" && date1 <= curDate)
        dueTasks += task1 + " is due!\n";

    if(task2 != "" && date2 <= curDate)
        dueTasks += task2 + " is due!\n";

    if(task3 != "" && date3 <= curDate)
        dueTasks += task3 + " is due!\n";

    if(task4 != "" && date4 <= curDate)
        dueTasks += task4 + " is due!\n";

    if(task5 != "" && date5 <= curDate)
        dueTasks += task5 + " is due!\n";

    if(dueTasks != "")
    {
        msgBox.setText(dueTasks);
        msgBox.exec();
    }
}


void MainWindow::on_TEST_clicked()
{
    tasks.removeLast();
    ui->taskLabel5->setText(tasks.last());
}
