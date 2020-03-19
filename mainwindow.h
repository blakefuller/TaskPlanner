#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QMessageBox>
#include <QStringList>
#include <vector>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct HomeworkInfo
{
    QString title;
    QDate date;
};

struct TaskInfo
{
    QString title;
    QDate date;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_hwIcon_clicked();

    void on_dashIcon_clicked();

    void on_taskIcon_clicked();

    void on_addButton_clicked();

    void setCurrentDate();

    void dueDateChecker();

    void on_taskAdd_clicked();

    void on_homeworkAdd_clicked();

    void sortDate(QVector <HomeworkInfo>& homeworkInfo);

    void sortDate(QVector <TaskInfo>& taskInfo);

    void removeLayout(QLayout *layout);

    void addLayout(QLayout *layout, QVector<HomeworkInfo> homeworkInfo);

    void addLayout(QLayout *layout, QVector<TaskInfo> taskInfo);

    void on_dashIcon2_clicked();

    void on_taskIcon3_clicked();

    void on_dashIcon3_clicked();

    void on_hwIcon3_clicked();

private:
    Ui::MainWindow *ui;

    QString dateString;

    QVector <QString> homeworks;
    QVector <QDate> homeworkDates;
    QVector <QString> tasks;
    QVector <QDate> taskDates;
    QDate curDate;

    QVector <HomeworkInfo> homeworkInfo;
    QVector <TaskInfo> taskInfo;

    QMessageBox msgBox;
};
#endif // MAINWINDOW_H
