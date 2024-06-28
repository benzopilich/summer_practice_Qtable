#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include "table_classes.cpp"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <QString>


int Index=0;
QStandardItemModel* model;
QStandardItemModel* model2;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->text1->setVisible(false);
    ui->text2->setVisible(false);
    ui->text3->setVisible(false);
    ui->pushButton->setVisible(false);
    //1table
    ui->tableView->setWindowTitle("Months");
    ui->tableView->setMinimumHeight(550);
    ui->tableView->setMinimumWidth(360);
    model=new QStandardItemModel(12,2);
    ui->tableView->setModel(model);
    model->setHeaderData(0, Qt::Horizontal, "Month");
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
    ui->tableView->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);


    //2table
    ui->tableView2->setWindowTitle("Musical Instruments");
    ui->tableView2->setMinimumHeight(550);
    ui->tableView2->setMinimumWidth(700);
    model2=new QStandardItemModel(5,3);
    ui->tableView2->setModel(model2);
    model2->setHeaderData(0, Qt::Horizontal, "Instrument");
    model2->setHeaderData(1,Qt::Horizontal,"Cost($)");
    model2->setHeaderData(2,Qt::Horizontal,"Year");
    vector<Tab2> Instruments;
    Tab2 k2;
    QFile ins("Inp_Ins.txt");
    if(ins.open(QIODevice::ReadOnly))
    {
        QTextStream in(&ins);
        for(int i=0;i<5;i++)
        {
            in>>k2;
            Instruments.push_back(k2);
        }
        ins.close();
    }
    else
    {
        cout<<"Error2";
    }
    for(int i=0;i<5;i++)
    {
        model2->setItem(i,0,new QStandardItem(Instruments[i].Name));
        model2->setItem(i,1,new QStandardItem(QString::number(Instruments[i].Cost)));
        model2->setItem(i,2,new QStandardItem(QString::number(Instruments[i].Year)));
    }
    ui->tableView2->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(Index==1)
    {
        ui->tableView->model()->insertRow(ui->tableView->model()->rowCount());
        QString M=ui->text1->text();
        int D=ui->text2->text().toInt();
        model->setItem(ui->tableView->model()->rowCount()-1,0,new QStandardItem(M));
        model->setItem(ui->tableView->model()->rowCount()-1,1,new QStandardItem(QString::number(D)));
    }
    if(Index==2)
    {
        ui->tableView2->model()->insertRow(ui->tableView2->model()->rowCount());
        QString N=ui->text1->text();
        double C=ui->text2->text().toDouble();;
        int Y=ui->text3->text().toInt();
        model2->setItem(ui->tableView2->model()->rowCount()-1,0,new QStandardItem(N));
        model2->setItem(ui->tableView2->model()->rowCount()-1,1,new QStandardItem(QString::number(C)));
        model2->setItem(ui->tableView2->model()->rowCount()-1,2,new QStandardItem(QString::number(Y)));
    }
    if(Index==3)
    {
        QString q=ui->text1->text();
        bool f=false;
        for(int i=0;i<ui->tableView->model()->rowCount();i++)
        {
            QModelIndex ind=ui->tableView->model()->index(i,0);
            QVariant cellValue=ind.data();
            QString temp=cellValue.toString();
            if(q==temp)
            {
                f=true;
                QString res;
                res=res+"Month: "+temp+" ";
                QModelIndex ind1=ui->tableView->model()->index(i,1);
                QVariant cellValue1=ind1.data();
                QString temp1=cellValue1.toString();
                res=res+"Days: "+temp1;
                ui->label1->setText(res);
                break;
            }
        }
        if(f==false)
        {
            ui->label1->setText("No Information.");
        }
        ui->label1->setFont(QFont("Times New Roman", 15, QFont::Bold));
    }
    if(Index==4)
    {
        QString q=ui->text1->text();
        bool f=false;
        for(int i=0;i<ui->tableView2->model()->rowCount();i++)
        {
            QModelIndex ind=ui->tableView2->model()->index(i,0);
            QVariant cellValue=ind.data();
            QString temp=cellValue.toString();
            if(q==temp)
            {
                f=true;
                QString res;
                res=res+"Name: "+temp+" ";
                QModelIndex ind1=ui->tableView2->model()->index(i,1);
                QVariant cellValue1=ind1.data();
                QString temp1=cellValue1.toString();
                res=res+"Cost($): "+temp1+" ";
                QModelIndex ind2=ui->tableView2->model()->index(i,2);
                QVariant cellValue2=ind2.data();
                QString temp2=cellValue2.toString();
                res=res+"Year: "+temp2;
                ui->label1->setText(res);
                break;
            }
        }
        if(f==false)
        {
            ui->label1->setText("No Information.");
        }
        ui->label1->setFont(QFont("Times New Roman", 15, QFont::Bold));
    }
    if(Index==5)
    {
        vector<Tab1>res;
        for(int i=0;i<ui->tableView->model()->rowCount();i++)
        {
            Tab1 t;
            QModelIndex ind=ui->tableView->model()->index(i,0);
            QVariant cellValue=ind.data();
            QString temp=cellValue.toString();
            t.Month=temp;
            QModelIndex ind1=ui->tableView->model()->index(i,1);
            QVariant cellValue1=ind1.data();
            int temp1=cellValue1.toInt();
            t.Day=temp1;
            res.push_back(t);
        }
        QFile oup("Tabel_1.txt");
        if(oup.open(QIODevice::WriteOnly))
        {
            QTextStream out(&oup);
            for(int i=0;i<ui->tableView->model()->rowCount();i++)
            {
                out<<res[i];
            }
            oup.close();
        }
        else
        {
            cout<<"Error_Out1";
        }
    }
    if(Index==6)
    {
        vector<Tab2>res;
        for(int i=0;i<ui->tableView2->model()->rowCount();i++)
        {
            Tab2 t;
            QModelIndex ind=ui->tableView2->model()->index(i,0);
            QVariant cellValue=ind.data();
            QString temp=cellValue.toString();
            t.Name=temp;
            QModelIndex ind1=ui->tableView2->model()->index(i,1);
            QVariant cellValue1=ind1.data();
            double temp1=cellValue1.toDouble();
            t.Cost=temp1;
            QModelIndex ind2=ui->tableView2->model()->index(i,2);
            QVariant cellValue2=ind2.data();
            int temp2=cellValue2.toInt();
            t.Year=temp2;
            res.push_back(t);
        }
        QFile oup("Tabel_2.txt");
        if(oup.open(QIODevice::WriteOnly))
        {
            QTextStream out(&oup);
            for(int i=0;i<ui->tableView2->model()->rowCount();i++)
            {
                out<<res[i];
            }
            oup.close();
        }
        else
        {
            cout<<"Error_Out2";
        }
    }
    if(Index==7)
    {
        Tab1_help T;
        Tab1 tab1;
        for(int i=0;i<ui->tableView->model()->rowCount();i++)
        {
            QModelIndex ind=ui->tableView->model()->index(i,0);
            QVariant cellValue=ind.data();
            QString temp=cellValue.toString();
            tab1.Month=temp;
            QModelIndex ind1=ui->tableView->model()->index(i,1);
            QVariant cellValue1=ind1.data();
            int temp1=cellValue1.toInt();
            tab1.Day=temp1;
            T.T1.push_back(tab1);
        }
        T.mySort();
        for(int i=0;i<ui->tableView->model()->rowCount();i++)
        {
            model->setItem(i,0,new QStandardItem(T.T1[i].Month));
            model->setItem(i,1,new QStandardItem(QString::number(T.T1[i].Day)));
        }
    }
    if(Index==8)
    {
        Tab2_help T;
        Tab2 tab2;
        for(int i=0;i<ui->tableView2->model()->rowCount();i++)
        {
            QModelIndex ind=ui->tableView2->model()->index(i,0);
            QVariant cellValue=ind.data();
            QString temp=cellValue.toString();
            tab2.Name=temp;
            QModelIndex ind1=ui->tableView2->model()->index(i,1);
            QVariant cellValue1=ind1.data();
            double temp1=cellValue1.toDouble();
            tab2.Cost=temp1;
            QModelIndex ind2=ui->tableView2->model()->index(i,2);
            QVariant cellValue2=ind2.data();
            int temp2=cellValue2.toInt();
            tab2.Year=temp2;
            T.T2.push_back(tab2);
        }
        T.mySort();
        for(int i=0;i<ui->tableView2->model()->rowCount();i++)
        {
            model2->setItem(i,0,new QStandardItem(T.T2[i].Name));
            model2->setItem(i,1,new QStandardItem(QString::number(T.T2[i].Cost)));
            model2->setItem(i,2,new QStandardItem(QString::number(T.T2[i].Year)));
        }
    }
}



void MainWindow::on_comboBox_activated(int index)
{
    if(index==0)
    {
        ui->text1->setVisible(false);
        ui->text2->setVisible(false);
        ui->text3->setVisible(false);
        ui->pushButton->setVisible(false);
        ui->label1->setVisible(false);
    }
    if(index==1)
    {
        Index=index;
        ui->text1->setVisible(true);
        ui->text2->setVisible(true);
        ui->text3->setVisible(false);
        ui->pushButton->setVisible(true);
        ui->label1->setVisible(false);
    }
    if(index==2)
    {
        Index=index;
        ui->text1->setVisible(true);
        ui->text2->setVisible(true);
        ui->text3->setVisible(true);
        ui->pushButton->setVisible(true);
        ui->label1->setVisible(false);
    }
    if(index==3)
    {
        Index=index;
        ui->text1->setVisible(true);
        ui->text2->setVisible(false);
        ui->text3->setVisible(false);
        ui->pushButton->setVisible(true);
        ui->label1->setVisible(true);
    }
    if(index==4)
    {
        Index=index;
        ui->text1->setVisible(true);
        ui->text2->setVisible(false);
        ui->text3->setVisible(false);
        ui->pushButton->setVisible(true);
        ui->label1->setVisible(true);
    }
    if(index==5)
    {
        Index=index;
        ui->text1->setVisible(false);
        ui->text2->setVisible(false);
        ui->text3->setVisible(false);
        ui->pushButton->setVisible(true);
        ui->label1->setVisible(false);
    }
    if(index==6)
    {
        Index=index;
        ui->text1->setVisible(false);
        ui->text2->setVisible(false);
        ui->text3->setVisible(false);
        ui->pushButton->setVisible(true);
        ui->label1->setVisible(false);
    }
    if(index==7)
    {
        Index=index;
        ui->text1->setVisible(false);
        ui->text2->setVisible(false);
        ui->text3->setVisible(false);
        ui->pushButton->setVisible(true);
        ui->label1->setVisible(false);
    }
    if(index==8)
    {
        Index=index;
        ui->text1->setVisible(false);
        ui->text2->setVisible(false);
        ui->text3->setVisible(false);
        ui->pushButton->setVisible(true);
        ui->label1->setVisible(false);
    }
}

