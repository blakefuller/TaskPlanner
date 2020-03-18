#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QMessageBox>
#include <QStringList>
#include <vector>
#include <QtAlgorithms>

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

    void on_addButton_clicked();

    void setCurrentDate();

    void dueDateChecker();

    void on_taskAdd_clicked();

    void on_homeworkAdd_clicked();

    void sortDate(QVector <QDate> date, QVector <QString> item);

    void on_sortDates_clicked();

    void removeLayout(QLayout *layout);

    void addLayout(int length, QLayout *layout, QVector<QDate> date, QVector<QString> item);

private:
    Ui::MainWindow *ui;

    QString dateString;

    QVector <QString> homeworks;
    QVector <QDate> homeworkDates;
    QVector <QString> tasks;
    QVector <QDate> taskDates;

    QDate curDate;

    QMessageBox msgBox;
};
#endif // MAINWINDOW_H
