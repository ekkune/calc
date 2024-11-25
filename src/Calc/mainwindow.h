#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
extern "C" {
#include "../calc.h"

}
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
    void on_Button_1_clicked();
    void on_Button_2_clicked();
    void on_Button_3_clicked();
    void on_Button_4_clicked();
    void on_Button_5_clicked();
    void on_Button_6_clicked();
    void on_Button_7_clicked();
    void on_Button_8_clicked();
    void on_Button_9_clicked();
    void on_Button_0_clicked();


    void on_Button_point_clicked();

    void on_Button_sin_clicked();

    void on_Button_asin_clicked();

    void on_Button_cos_clicked();

    void on_Button_tan_clicked();

    void on_Button_atan_clicked();

    void on_Button_plus_clicked();

    void on_Button_mult_clicked();

    void on_Button_open_bracket_clicked();

    void on_Button_minus_clicked();

    void on_Button_del_clicked();

    void on_Button_closed_bracket_clicked();

    void on_Button_pow_clicked();

    void on_Button_sqrt_clicked();

    void on_Button_ln_clicked();

    void on_Button_log_clicked();

    void on_Button_acos_clicked();

    void on_Button_clear_clicked();

    void on_Button_res_clicked();

    void on_Button_persent_clicked();

    void on_Button_closed_bracket_2_clicked();


    void on_Button_draw_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
