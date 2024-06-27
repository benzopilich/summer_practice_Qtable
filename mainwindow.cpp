#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include "table_classes.cpp"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    ui->tableView->setWindowTitle("MyTable");
    ui->tableView->setMinimumHeight(550);
    ui->tableView->setMinimumWidth(360);
    QStandardItemModel* model=new QStandardItemModel(12,2);
    ui->tableView->setModel(model);
    model->setHeaderData(0, Qt::Horizontal, "Months");
    model->setHeaderData(1,Qt::Horizontal,"Days");
    vector<Tab1> Months;
    Tab1 k;
    QFile mon("Inp_Mon.txt");
    if(mon.open(QIODevice::ReadOnly))
    {
        QTextStream in(&mon);
        for(int i=0;i<12;i++)
        {
            in>>k;
            Months.push_back(k);
        }
        mon.close();
    }
    else
    {
        cout<<"Error";
    }
    for(int i=0;i<12;i++)
    {
        model->setItem(i,0,new QStandardItem(Months[i].Month));
        model->setItem(i,1,new QStandardItem(QString::number(Months[i].Day)));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

