#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCurrentDate();
    ui->addWidget->hide();
    homeworks.clear();
    tasks.clear();
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

}

// checks if tasks are due
// sends message box if so
void MainWindow::dueDateChecker()
{
    QString dueTasks = "Tasks Due: \n";
    QString dueHomework = "Homework Due: \n";

    // iterates through every item in taskDates and homeworkDates
    // and compares it to the current date if they are due or not
    for (int i = 0; i < tasks.length(); i++)
    {
        if(taskDates[i] <= curDate)
        {
            dueTasks += tasks[i] + "\n";
        }
    }

    for (int i = 0; i < homeworks.length(); i++)
    {
        if(homeworkDates[i] <= curDate)
        {
            dueHomework += homeworks[i] + "\n";
        }
    }

    if(dueTasks != "Tasks Due: \n")
    {
        msgBox.setText(dueTasks);
        msgBox.exec();
    }

    if(dueHomework != "Homework Due: \n")
    {
        msgBox.setText(dueHomework);
        msgBox.exec();
    }

}

void MainWindow::on_taskAdd_clicked()
{
    if(!ui->taskTitle->text().isEmpty())
    {
        TaskInfo *info = new TaskInfo();
        info->title = ui->taskTitle->text();
        info->date = ui->taskDate->date();
        this->taskInfo.append(*info);

        this->sortDate(taskInfo);

        if(ui->taskLayout->count() < 5)
        {
            this->removeLayout(ui->taskLayout);
            this->addLayout(ui->taskLayout, taskInfo);
        }
        this->removeLayout(ui->taskFullLayout);
        this->addLayout(ui->taskFullLayout, taskInfo);
    }

    this->dueDateChecker();
}

void MainWindow::on_homeworkAdd_clicked()
{
    if(!ui->homeworkTitle->text().isEmpty())
    {
        HomeworkInfo *info = new HomeworkInfo();
        info->title = ui->homeworkTitle->text();
        info->date = ui->homeworkDate->date();
        this->homeworkInfo.append(*info);

        this->sortDate(homeworkInfo);

        if(ui->homeworkLayout->count() < 5)
        {
            this->removeLayout(ui->homeworkLayout);
            this->addLayout(ui->homeworkLayout, homeworkInfo);
        }
        this->removeLayout(ui->hwFullLayout);
        this->addLayout(ui->hwFullLayout, homeworkInfo);

    }

    this->dueDateChecker();
}

void MainWindow::sortDate(QVector<HomeworkInfo> &homeworkInfo)
{
    int size = homeworkInfo.length();
    QDate tempDate;
    QString tempItem;
    bool swapped = false;

    for (int i = 0; i < size-1; i++)
    {
        swapped = false;
        for (int j = 0; j < size-i-1; j++)
        {
            if(homeworkInfo[j].date > homeworkInfo[j+1].date)
            {
                tempDate = homeworkInfo[j].date;
                homeworkInfo[j].date = homeworkInfo[j+1].date;
                homeworkInfo[j+1].date = tempDate;

                tempItem = homeworkInfo[j].title;
                homeworkInfo[j].title = homeworkInfo[j+1].title;
                homeworkInfo[j+1].title = tempItem;
            }
            swapped = true;
        }
        if(swapped == false)
            break;
    }
}

void MainWindow::sortDate(QVector<TaskInfo> &taskInfo)
{
    int size = taskInfo.length();
    QDate tempDate;
    QString tempItem;
    bool swapped = false;

    for (int i = 0; i < size-1; i++)
    {
        swapped = false;
        for (int j = 0; j < size-i-1; j++)
        {
            if(taskInfo[j].date > taskInfo[j+1].date)
            {
                tempDate = taskInfo[j].date;
                taskInfo[j].date = taskInfo[j+1].date;
                taskInfo[j+1].date = tempDate;

                tempItem = taskInfo[j].title;
                taskInfo[j].title = taskInfo[j+1].title;
                taskInfo[j+1].title = tempItem;
            }
            swapped = true;
        }
        if(swapped == false)
            break;
    }
}

void MainWindow::removeLayout(QLayout *layout)
{
    QLayoutItem *child;

    while(layout->count()!=0)
        {
            child = layout->takeAt(0);
            if(child->layout() != 0)
            {
                removeLayout(child->layout());
            }
            else if(child->widget() != 0)
            {
                delete child->widget();
            }

            delete child;
    }
}

void MainWindow::addLayout(QLayout *layout, QVector<HomeworkInfo> homeworkInfo)
{
    int size = homeworkInfo.length();
    QString title;
    QDate date;
    QString display;


    if(size != 0)
    {
        for (int i = 0; i < size; i++)
        {
            title = homeworkInfo[i].title;
            date = homeworkInfo[i].date;
            display = title + "\t" + date.toString("MM/dd/yyyy");
            QLabel *hwDisplay = new QLabel(display);
            hwDisplay->setFixedWidth(300);
            hwDisplay->setScaledContents(true);
            layout->addWidget(hwDisplay);
            layout->setAlignment(Qt::AlignTop);
        }
    }
}

void MainWindow::addLayout(QLayout *layout, QVector<TaskInfo> taskInfo)
{
    int size = taskInfo.length();
    QString title;
    QDate date;
    QString display;


    if(size != 0)
    {
        for (int i = 0; i < size; i++)
        {
            title = taskInfo[i].title;
            date = taskInfo[i].date;
            display = title + "\t" + date.toString("MM/dd/yyyy");
            QLabel *hwDisplay = new QLabel(display);
            hwDisplay->setFixedWidth(300);
            hwDisplay->setScaledContents(true);
            layout->addWidget(hwDisplay);
            layout->setAlignment(Qt::AlignTop);
        }
    }
}

void MainWindow::on_dashIcon2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_taskIcon3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_dashIcon3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_hwIcon3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
