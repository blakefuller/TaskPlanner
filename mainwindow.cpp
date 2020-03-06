#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
