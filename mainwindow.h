#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digit_pressed();
    void on_pushButton_point_released();
    void unary_operations_pressed();
    void on_pushButton_clear_released();
    void binary_operations_pressed();

    void on_pushButton_equal_released();
};

#endif // MAINWINDOW_H
