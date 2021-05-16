#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QList>
#include<QColor>
#include<QPushButton>
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
    void on_One_clicked();

    void on_Two_clicked();

    void on_Three_clicked();

    void on_Four_clicked();

    void on_Five_clicked();

    void on_Six_clicked();

    void on_Seven_clicked();

    void on_Eight_clicked();

    void on_Nine_clicked();

    void on_SaveColour_clicked();

    void on_SaveLoad_clicked();

private:
    Ui::MainWindow *ui;
    QList<QColor>ColorList;
    void SaveColor(QString key,QColor color);
    QColor LoadColor(QString key);
    void setLoadedColor(QString key,int index,QPushButton *button);
};
#endif // MAINWINDOW_H
