#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QColorDialog>
#include<QSettings>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i=0;i<9;i++)
            {
                ColorList.append(Qt::black);
            }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_One_clicked()
{
        QColor color=QColorDialog::getColor(ColorList[0],this,"Choose Background color");
            if(color.isValid())
           {
                ColorList[0]=color;
                QString css=QString ("Background-color:%1").arg(color.name());
                ui->One->setStyleSheet(css);
            }
}
void MainWindow::on_Two_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[1],this,"Choose Background color");
          if(color.isValid())
          {
              ColorList[1]=color;
              QString css=QString ("Background-color:%1").arg(color.name());
              ui->Two->setStyleSheet(css);
          }
}


void MainWindow::on_Three_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[1],this,"Choose Background color");
          if(color.isValid())
          {
              ColorList[1]=color;
              QString css=QString ("Background-color:%1").arg(color.name());
              ui->Three->setStyleSheet(css);
          }
}

void MainWindow::on_Four_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[1],this,"Choose Background color");
          if(color.isValid())
          {
              ColorList[1]=color;
              QString css=QString ("Background-color:%1").arg(color.name());
              ui->Four->setStyleSheet(css);
          }
}

void MainWindow::on_Five_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[1],this,"Choose Background color");
          if(color.isValid())
          {
              ColorList[1]=color;
              QString css=QString ("Background-color:%1").arg(color.name());
              ui->Five->setStyleSheet(css);
          }
}

void MainWindow::on_Six_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[1],this,"Choose Background color");
          if(color.isValid())
          {
              ColorList[1]=color;
              QString css=QString ("Background-color:%1").arg(color.name());
              ui->Six->setStyleSheet(css);
          }
}

void MainWindow::on_Seven_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[1],this,"Choose Background color");
          if(color.isValid())
          {
              ColorList[1]=color;
              QString css=QString ("Background-color:%1").arg(color.name());
              ui->Seven->setStyleSheet(css);
          }
}

void MainWindow::on_Eight_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[1],this,"Choose Background color");
          if(color.isValid())
          {
              ColorList[1]=color;
              QString css=QString ("Background-color:%1").arg(color.name());
              ui->Eight->setStyleSheet(css);
          }
}

void MainWindow::on_Nine_clicked()
{
    QColor color=QColorDialog::getColor(ColorList[1],this,"Choose Background color");
          if(color.isValid())
          {
              ColorList[1]=color;
              QString css=QString ("Background-color:%1").arg(color.name());
              ui->Nine->setStyleSheet(css);
          }
}

void MainWindow::on_SaveColour_clicked()
{
    SaveColor("One",ColorList[0]);
    SaveColor("Two",ColorList[1]);
    SaveColor("Three",ColorList[2]);
    SaveColor("Four",ColorList[3]);
    SaveColor("Five",ColorList[4]);
    SaveColor("Six",ColorList[5]);
    SaveColor("Seven",ColorList[6]);
    SaveColor("Eight",ColorList[7]);
    SaveColor("Nine",ColorList[8]);
}

void MainWindow::on_SaveLoad_clicked()
{
    setLoadedColor("One",0,ui->One);
    setLoadedColor("Two",0,ui->Two);
    setLoadedColor("Three",0,ui->Three);
    setLoadedColor("Four",0,ui->Four);
    setLoadedColor("Five",0,ui->Five);
    setLoadedColor("Six",0,ui->Six);
    setLoadedColor("Seven",0,ui->Seven);
    setLoadedColor("Eight",0,ui->Eight);
    setLoadedColor("Nine",0,ui->Nine);

}

void MainWindow::SaveColor(QString key, QColor color)
{
    int red=color.red();
    int green=color.green();
    int blue=color.blue();
    QSettings settings("Blikoon","SettingsDemo");
    settings.beginGroup("ButtonColor");
    settings.setValue(key +"r",red);
    settings.setValue(key +"g",green);
    settings.setValue(key +"b",blue);
    settings.endGroup();
}

QColor MainWindow::LoadColor(QString key)
{
      int red;
      int green;
      int blue;
      QSettings settings("Blikoon","SettingsDemo");
      settings.beginGroup("ButtonColor");
      red=settings.value(key+"r",QVariant(0)).toInt();
      green=settings.value(key+"g",QVariant(0)).toInt();
      blue=settings.value(key+"b",QVariant(0)).toInt();
      settings.endGroup();
      return QColor(red,green,blue);
}

void MainWindow::setLoadedColor(QString key, int index, QPushButton *button)
{
    QColor color=LoadColor(key);
    ColorList[index]=color;
    QString css=QString ("Background-color:%1").arg(color.name());
    button->setStyleSheet(css);
}

