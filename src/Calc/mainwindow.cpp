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


void MainWindow::on_Button_1_clicked()
{
    ui->textEdit->insertPlainText("1");
}

void MainWindow::on_Button_2_clicked()
{
    ui->textEdit->insertPlainText("2");
}

void MainWindow::on_Button_3_clicked()
{
    ui->textEdit->insertPlainText("3");
}
void MainWindow::on_Button_4_clicked()
{
    ui->textEdit->insertPlainText("4");
}

void MainWindow::on_Button_5_clicked()
{
    ui->textEdit->insertPlainText("5");
}

void MainWindow::on_Button_6_clicked()
{
    ui->textEdit->insertPlainText("6");
}

void MainWindow::on_Button_7_clicked()
{
    ui->textEdit->insertPlainText("7");
}
void MainWindow::on_Button_8_clicked()
{
    ui->textEdit->insertPlainText("8");
}
void MainWindow::on_Button_9_clicked()
{
    ui->textEdit->insertPlainText("9");
}
void MainWindow::on_Button_0_clicked()
{
    ui->textEdit->insertPlainText("0");
}

void MainWindow::on_Button_point_clicked()
{
    ui->textEdit->insertPlainText(".");
}


void MainWindow::on_Button_sin_clicked()
{
    ui->textEdit->insertPlainText("sin(");
}


void MainWindow::on_Button_asin_clicked()
{
    ui->textEdit->insertPlainText("asin(");
}


void MainWindow::on_Button_cos_clicked()
{
    ui->textEdit->insertPlainText("cos(");
}



void MainWindow::on_Button_tan_clicked()
{
    ui->textEdit->insertPlainText("tan(");
}


void MainWindow::on_Button_atan_clicked()
{
    ui->textEdit->insertPlainText("atan(");
}


void MainWindow::on_Button_plus_clicked()
{
    ui->textEdit->insertPlainText("+");
}


void MainWindow::on_Button_mult_clicked()
{
    ui->textEdit->insertPlainText("*");
}


void MainWindow::on_Button_open_bracket_clicked()
{
    ui->textEdit->insertPlainText("(");
}


void MainWindow::on_Button_minus_clicked()
{
    ui->textEdit->insertPlainText("-");
}


void MainWindow::on_Button_del_clicked()
{
    ui->textEdit->insertPlainText("/");
}


void MainWindow::on_Button_closed_bracket_clicked()
{
    ui->textEdit->insertPlainText(")");
}


void MainWindow::on_Button_pow_clicked()
{
    ui->textEdit->insertPlainText("^(");
}


void MainWindow::on_Button_sqrt_clicked()
{
    ui->textEdit->insertPlainText("sqrt(");
}




void MainWindow::on_Button_ln_clicked()
{
    ui->textEdit->insertPlainText("ln(");
}


void MainWindow::on_Button_log_clicked()
{
    ui->textEdit->insertPlainText("log(");
}





void MainWindow::on_Button_acos_clicked()
{
    ui->textEdit->insertPlainText("acos(");
}



void MainWindow::on_Button_clear_clicked()
{
    ui->textEdit->setText("");
}


void MainWindow::on_Button_res_clicked()
{
    char *expression = (char *) ui->textEdit->toPlainText().toStdString().c_str();
    double x = ui->lineEdit->text().toDouble();
    double answer = 0.;
    int error = getAnswer(expression, &answer, x);
    if (error) {
        ui->textEdit->setText("ERROR");
    } else {
        ui->textEdit->setText(QString::number(answer));
    }
    ui->textEdit->moveCursor(QTextCursor::End);

}


void MainWindow::on_Button_persent_clicked()
{
    ui->textEdit->insertPlainText("%");
}


void MainWindow::on_Button_closed_bracket_2_clicked()
{
    ui->textEdit->insertPlainText("x");
}





void MainWindow::on_Button_draw_clicked()
{

    double a = -2; //Начало интервала, где рисуем график по оси Ox
    double b = 2; //Конец интервала, где рисуем график по оси Ox
    double h = 0.01; //Шаг, с которым будем пробегать по оси Ox
    int N = (b - a) / h; //Вычисляем количество точек, которые будем отрисовывать
    QVector<double> x(N), y(N); //Массивы координат точек

    char *expression = (char *) ui->textEdit->toPlainText().toStdString().c_str();

    //Вычисляем наши данные
    int i=0;
    //Пробегаем по всем точкам
    for (double X = a; X <= b; X += h) {
        x[i] = X;
        int error = getAnswer(expression, &(y[i++]), X);
        if (error) {
            ui->textEdit->setText("ERROR");
            return;
        }
    }
    ui->widget->clearGraphs();//Если нужно, но очищаем все графики

    //Добавляем один график в widget
    ui->widget->addGraph();

    //Говорим, что отрисовать нужно график по нашим двум массивам x и y
    ui->widget->graph(0)->setData(x, y);

    //Подписываем оси Ox и Oy
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");

    //Установим область, которая будет показываться на графике
    ui->widget->xAxis->setRange(a, b);//Для оси Ox

    double minY = -5;
    double maxY = 5;
    ui->widget->yAxis->setRange(minY, maxY);//Для оси Oy

    //И перерисуем график на нашем widget
    ui->widget->replot();
}

