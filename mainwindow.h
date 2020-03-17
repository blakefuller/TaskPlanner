#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QMessageBox>
#include <QStringList>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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

    void on_taskDate1_userDateChanged(const QDate &date);

    void on_taskDate2_userDateChanged(const QDate &date);

    void on_taskDate3_userDateChanged(const QDate &date);

    void on_taskDate4_userDateChanged(const QDate &date);

    void on_taskDate5_userDateChanged(const QDate &date);

    void on_submitTaskButton_clicked();

    void on_addButton_clicked();

    void setCurrentDate();

    void dueDateChecker();

    void on_TEST_clicked();

    void on_taskAdd_clicked();

    void on_homeworkAdd_clicked();

private:
    Ui::MainWindow *ui;
    QString task1;
    QString task2;
    QString task3;
    QString task4;
    QString task5;
    QString dateString;
    QVector <QString> homeworks;
    QVector <QString> tasks;

    QDate curDate;
    QDate date1;
    QDate date2;
    QDate date3;
    QDate date4;
    QDate date5;

    QMessageBox msgBox;
};
#endif // MAINWINDOW_H
