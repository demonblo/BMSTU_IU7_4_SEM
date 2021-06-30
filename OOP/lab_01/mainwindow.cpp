#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task_manager.h"
#include "error_codes.h"
#include "operations.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    request wrequest;
    wrequest.type = INIT;
    task_manager(wrequest);
}

MainWindow::~MainWindow()
{
    delete ui;
}

errors draw_action(Ui::MainWindow* ui)
{
    draw dr;

    dr.gV = ui->graphicsView;
    dr.h = ui->graphicsView->height();
    dr.w = ui->graphicsView->width();

    request wrequest;
    wrequest.type = DRAW;
    wrequest.dr = dr;

    errors err = (errors) task_manager(wrequest);
    return err;
}

errors transform_and_show(request req, Ui::MainWindow* ui)
{
    errors err = (errors) task_manager(req);
    if (err)
        return err;
    else
        err = draw_action(ui);

    return err;
}

// Load figure
void MainWindow::on_actionOpen_triggered()
{
    request wrequest;
    wrequest.type = LOAD_FILE;
    wrequest.load_f.filename = "/Users/vasilii/OOP/lab_01_hub/bmstu_OOP/lab1/cube.txt";

    errors err = transform_and_show(wrequest, ui);
    if (err)
        error_message(err);
}

// Transformation
void MainWindow::on_button_Move_clicked()
{
    request wrequest;
    wrequest.type = MOVE;

    wrequest.mo.dx = ui->lineEdit_MoveX->text().toInt();
    wrequest.mo.dy = ui->lineEdit_MoveY->text().toInt();
    wrequest.mo.dz = ui->lineEdit_MoveZ->text().toInt();

    errors err = transform_and_show(wrequest, ui);
    if (err)
        error_message(err);
}

void MainWindow::on_button_Scale_clicked()
{
    request wrequest;
    wrequest.type = SCALE;

    wrequest.sc.kx = ui->lineEdit_ScaleX->text().toDouble();
    wrequest.sc.ky = ui->lineEdit_ScaleY->text().toDouble();
    wrequest.sc.kz = ui->lineEdit_ScaleZ->text().toDouble();

    errors err = transform_and_show(wrequest, ui);
    if (err)
        error_message(err);
}

void MainWindow::on_button_Turn_clicked()
{
    request wrequest;
    wrequest.type = TURN;

    wrequest.tu.ox = ui->lineEdit_TurnX->text().toDouble();
    wrequest.tu.oy = ui->lineEdit_TurnY->text().toDouble();
    wrequest.tu.oz = ui->lineEdit_TurnZ->text().toDouble();

    errors err = transform_and_show(wrequest, ui);
    if (err)
        error_message(err);
}


void MainWindow::on_MainWindow_destroyed()
{
    request wrequest;
    wrequest.type = QUIT;

    errors err = transform_and_show(wrequest, ui);
    if (err)
        error_message(err);
}
