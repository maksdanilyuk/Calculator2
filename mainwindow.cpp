#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

 double firstNumber;
 bool typingSecondNumber = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(241,361);
    connect(ui->pushButton_0,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_signe,SIGNAL(released()), this, SLOT(unary_operations_pressed()));
    connect(ui->pushButton_percent,SIGNAL(released()), this, SLOT(unary_operations_pressed()));
    connect(ui->pushButton_plus,SIGNAL(released()), this, SLOT(binary_operations_pressed()));
    connect(ui->pushButton_min,SIGNAL(released()), this, SLOT(binary_operations_pressed()));
    connect(ui->pushButton_mul,SIGNAL(released()), this, SLOT(binary_operations_pressed()));
    connect(ui->pushButton_div,SIGNAL(released()), this, SLOT(binary_operations_pressed()));


    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_min->setCheckable(true);
    ui->pushButton_mul->setCheckable(true);
    ui->pushButton_div->setCheckable(true);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    QPushButton *button = (QPushButton*)sender();
    double labelNumber;

    if((ui->pushButton_plus->isChecked() || ui->pushButton_min->isChecked() || ui->pushButton_div->isChecked() || ui->pushButton_mul->isChecked())
            && (!typingSecondNumber) )
    {
        labelNumber = button->text().toDouble();
        typingSecondNumber = true;
        ui->label->setText(QString::number(labelNumber,'g',15));
    }
    else
    {
        if(ui->label->text().contains('.') && button->text() == "0")
        {
            ui->label->setText(ui->label->text() + button->text());
        }
        else
         {
                labelNumber = (ui->label->text() + button->text()).toDouble();
                 ui->label->setText(QString::number(labelNumber,'g',15));
            }
        }

    }




void MainWindow::on_pushButton_point_released()
{
    if(!ui->label->text().contains('.'))
    {
         ui->label->setText(ui->label->text() + ".");
    }

}

void MainWindow::unary_operations_pressed()
{
     QPushButton *button = (QPushButton*)sender();
     double labelNumber;

     if(button->text() == "+/-")
    {

        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * -1;
        ui->label->setText(QString::number(labelNumber,'g',15));
     }

     if(button->text() == "%")
    {

        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * 0.01;
        ui->label->setText(QString::number(labelNumber,'g',15));
     }
}

void MainWindow::on_pushButton_clear_released()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_min->setChecked(false);
    ui->pushButton_mul->setChecked(false);
    ui->pushButton_div->setChecked(false);
    typingSecondNumber = false;

    ui->label->setText("0");
}


void MainWindow::binary_operations_pressed()
{
    QPushButton *button = (QPushButton*)sender();

    firstNumber = ui->label->text().toDouble();

    button->setChecked(true);

}

void MainWindow::on_pushButton_equal_released()
{
    double labelNumber, secondNumber;
    secondNumber = ui->label->text().toDouble();

    if(ui->pushButton_plus->isChecked()){
        labelNumber = firstNumber + secondNumber;
        ui->label->setText(QString::number(labelNumber,'g',15));
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_min->isChecked()){
        labelNumber = firstNumber - secondNumber;
        ui->label->setText(QString::number(labelNumber,'g',15));
        ui->pushButton_min->setChecked(false);
    }
    else if(ui->pushButton_mul->isChecked()){
        labelNumber = firstNumber * secondNumber;
        ui->label->setText(QString::number(labelNumber,'g',15));
        ui->pushButton_mul->setChecked(false);
    }
    else if(ui->pushButton_div->isChecked()){
        labelNumber = firstNumber / secondNumber;
        ui->label->setText(QString::number(labelNumber,'g',15));
        ui->pushButton_div->setChecked(false);
    }

    typingSecondNumber = false;
}
