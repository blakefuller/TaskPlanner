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
        QString title = ui->taskTitle->text();
        QDate date = ui->taskDate->date();
        tasks.append(title);
        taskDates.append(date);

        if(ui->taskLayout->count() < 5)
        {
            QString label = title + "\t" + date.toString("MM/dd/yyyy");
            QLabel *task = new QLabel(label);
            task->setFixedWidth(300);
            task->setScaledContents(true);
            ui->taskLayout->addWidget(task);
            ui->taskLayout->setAlignment(Qt::AlignTop);
        }

        QString display = title + "\t" + ui->taskDate->text();
        QLabel *taskDisplay = new QLabel(display);
        taskDisplay->setFixedWidth(300);
        taskDisplay->setScaledContents(true);
        ui->taskFullLayout->addWidget(taskDisplay);
        ui->taskFullLayout->setAlignment(Qt::AlignTop);
    }

    this->dueDateChecker();
}

void MainWindow::on_homeworkAdd_clicked()
{
    if(!ui->homeworkTitle->text().isEmpty())
    {
        QString title = ui->homeworkTitle->text();
        QDate date = ui->homeworkDate->date();
        homeworks.append(title);
        homeworkDates.append(date);

        if(ui->homeworkLayout->count() < 5)
        {
            QString label = title + "\t" + date.toString("MM/dd/yyyy");
            QLabel *homework = new QLabel(label);
            homework->setFixedWidth(300);
            homework->setScaledContents(true);
            ui->homeworkLayout->addWidget(homework);
            ui->homeworkLayout->setAlignment(Qt::AlignTop);
        }

        QString display = title + "\t" + ui->homeworkDate->text();
        QLabel *hwDisplay = new QLabel(display);
        hwDisplay->setFixedWidth(300);
        hwDisplay->setScaledContents(true);
        ui->hwFullLayout->addWidget(hwDisplay);
        ui->hwFullLayout->setAlignment(Qt::AlignTop);


    }

    this->dueDateChecker();
}

void MainWindow::sortDate(QVector<QDate> date, QVector<QString> item)
{
    int size = date.length();
    QDate tempDate;
    QString tempItem;
    bool swapped = false;

    for (int i = 0; i < size; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i; j++)
        {
            tempDate = date[j];
            date[j] = date[j+1];
            date[j+1] = tempDate;

            tempItem = item[j];
            item[j] = item[j+1];
            item[j+1] = tempItem;

            swapped = true;
        }
    }
}

void MainWindow::on_sortDates_clicked()
{
//    this->sortDate(taskDates, tasks);
//    this->sortDate(homeworkDates, homeworks);

    std::sort(homeworkDates.begin(), homeworkDates.end());

    this->removeLayout(ui->taskLayout);
    this->removeLayout(ui->homeworkLayout);
    this->removeLayout(ui->taskFullLayout);
    this->removeLayout(ui->hwFullLayout);

    this->addLayout(5, ui->taskLayout, taskDates, tasks);
    this->addLayout(5, ui->homeworkLayout, homeworkDates, homeworks);
    this->addLayout(tasks.length(), ui->taskFullLayout, taskDates, tasks);
    this->addLayout(homeworks.length(), ui->hwFullLayout, homeworkDates, homeworks);
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

void MainWindow::addLayout(int length, QLayout *layout, QVector<QDate> dates, QVector<QString> items)
{
    int size = dates.length();
    QString title;
    QDate date;
    QString display;


    if(size != 0)
    {
        if(layout->count() < length)
        {
            for (int i = 0; i < size; i++)
            {
                title = items[i];
                date = dates[i];
                display = title + "\t" + date.toString("MM/dd/yyyy");
                QLabel *hwDisplay = new QLabel(display);
                hwDisplay->setFixedWidth(300);
                hwDisplay->setScaledContents(true);
                layout->addWidget(hwDisplay);
                layout->setAlignment(Qt::AlignTop);
            }
        }
    }
}
