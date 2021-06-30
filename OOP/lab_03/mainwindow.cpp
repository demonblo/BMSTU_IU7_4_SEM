#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , facade_viewer(new FacadeViewer)
    , index_model(0)
    , index_camera(0)
{
    ui->setupUi(this);
    pixmap = QPixmap(ui->drawLabel->width(), ui->drawLabel->height());
    pixmap.fill();
    ui->drawLabel->setPixmapPointer(pixmap);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_addCamera_clicked()
{
    std::string cam_name = std::string("camera_") + std::to_string(++index_camera);
    char *chrstr = new char[cam_name.length() + 1];
    strcpy(chrstr, cam_name.c_str());
    try
    {
        std::shared_ptr<Command> command(new AddCameraAction(chrstr));
        facade_viewer->executeCommand(command);
        ui->comboBoxCamera->addItem(cam_name.c_str());
        if (ui->comboBoxCamera->count() == 1)
        {
            std::shared_ptr<Command> command(new SetCameraAction(chrstr));
            facade_viewer->executeCommand(command);
            if (ui->comboBoxModel->count() > 0)
                render();
        }
    }
    catch (ExceptionApps& error)
    {
        cout << "Error: " << error.what() << endl;
    }
    catch (std::exception& error)
    {
        cout << error.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown Error" << endl;
    }
}

void MainWindow::on_pushButton_addModel_clicked()
{
    QString file = QFileDialog::getOpenFileName(this,
                                                QString::fromUtf8("Открыть файл"),
                                                QDir::currentPath(),
                                                "text files (*.txt)");
    if (file.isEmpty())
        return;

    std::string model_name = std::string("model_") + std::to_string(++index_model);
    std::string file_name = file.toLocal8Bit().constData();
    char *chrstr = new char[model_name.length() + 1];
    strcpy(chrstr, model_name.c_str());
    char *chrstr1 = new char[file_name.length() + 1];
    strcpy(chrstr1, file_name.c_str());
    try
    {
        std::shared_ptr<Command> command(new AddModelAction(chrstr, chrstr1));
        facade_viewer->executeCommand(command);
        render();
        ui->comboBoxModel->addItem(model_name.c_str());

    }
    catch (ExceptionApps& error)
    {
        cout << "Error: " << error.what() << endl;
    }
    catch (std::exception& error)
    {
        cout << error.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown Error" << endl;
    }
}

void MainWindow::render()
{
//    if (ui->comboBoxCamera->count() == 0)
//    {
//        QMessageBox::information(nullptr, "Attention", "Choose camera to render");
//        return;
//    }
    development_environment = readConfigFile();
    try
    {
        time_t t_time = time(NULL);
        if (development_environment == "Qt")
        {
            QPainter painter(&pixmap);
            pixmap.fill();
            auto drawer = new QtDrawer(&painter);
            std::shared_ptr<AbstractGraphFactory> factory = std::make_shared<QtGraphFactory>();
            if(!factory)
                throw ErrorAllocMemmory(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
            drawer->setFactory(factory);
            std::shared_ptr<Command> command(new RenderAction(std::shared_ptr<BaseDrawer>(drawer)));
            facade_viewer->executeCommand(command);
            ui->drawLabel->update();
        }
        else
            throw ErrorConfigFile(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time), "No this development environment");
    }
    catch (ExceptionApps& error)
    {
        cout << "Error: " << error.what() << endl;
    }
    catch (std::exception& error)
    {
        cout << error.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown Error" << endl;
    }
}

void MainWindow::on_pushButton_setCamera_clicked()
{
    std::string cam_name = ui->comboBoxCamera->currentText().toStdString();
    char *chrstr = new char[cam_name.length() + 1];
    strcpy(chrstr, cam_name.c_str());
    try
    {
        std::shared_ptr<Command> command(new SetCameraAction(chrstr));
        facade_viewer->executeCommand(command);

        if (ui->comboBoxCamera->count() > 0)
            render();
    }
    catch (ExceptionApps& error)
    {
        cout << "Error: " << error.what() << endl;
    }
    catch (std::exception& error)
    {
        cout << error.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown Error" << endl;
    }
}

void MainWindow::on_pushButton_moveModel_clicked()
{
    if (ui->comboBoxModel->count() == 0)
    {
        return;
    }
    std::string obj_name = ui->comboBoxModel->currentText().toStdString();
    char *chrstr = new char[obj_name.length() + 1];
    strcpy(chrstr, obj_name.c_str());
    double x = ui->doubleSpinBoxDx->value();
    double y = ui->doubleSpinBoxDy->value();
    double z = ui->doubleSpinBoxDz->value();

    try
    {
        Point moving(x, y, z);
        Point rotateing(0, 0, 0);
        Point scale(1, 1, 1);
        std::shared_ptr<Command> command(new TransformModelAction(chrstr, moving, scale, rotateing));
        facade_viewer->executeCommand(command);
    }
    catch (ExceptionApps& error)
    {
        cout << "Error: " << error.what() << endl;
    }
    catch (std::exception& error)
    {
        cout << error.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown Error" << endl;
    }
    render();
}

void MainWindow::on_pushButton_scaleModel_clicked()
{
    if (ui->comboBoxModel->count() == 0)
    {
        return;
    }
    std::string obj_name = ui->comboBoxModel->currentText().toStdString();
    char *chrstr = new char[obj_name.length() + 1];
    strcpy(chrstr, obj_name.c_str());
    double x = ui->doubleSpinBoxKx->value();
    double y = ui->doubleSpinBoxKy->value();
    double z = ui->doubleSpinBoxKz->value();

    try
    {
        Point moving(0, 0, 0);
        Point rotateing(0, 0, 0);
        Point scale(x, y, z);
        std::shared_ptr<Command> command(new TransformModelAction(chrstr, moving, scale, rotateing));
        facade_viewer->executeCommand(command);
    }
    catch (ExceptionApps& error)
    {
        cout << "Error: " << error.what() << endl;
    }
    catch (std::exception& error)
    {
        cout << error.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown Error" << endl;
    }
    render();
}

void MainWindow::on_pushButton_rotateModel_clicked()
{
    if (ui->comboBoxModel->count() == 0)
    {
        return;
    }
    std::string obj_name = ui->comboBoxModel->currentText().toStdString();
    char *chrstr = new char[obj_name.length() + 1];
    strcpy(chrstr, obj_name.c_str());
    double x = ui->doubleSpinBoxOx->value();
    double y = ui->doubleSpinBoxOy->value();
    double z = ui->doubleSpinBoxOz->value();

    try
    {
        Point moving(0, 0, 0);
        Point rotateing(x, y, z);
        Point scale(1, 1, 1);
        std::shared_ptr<Command> command(new TransformModelAction(chrstr, moving, scale, rotateing));
        facade_viewer->executeCommand(command);
    }
    catch (ExceptionApps& error)
    {
        cout << "Error: " << error.what() << endl;
    }
    catch (std::exception& error)
    {
        cout << error.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown Error" << endl;
    }
    render();
}

std::string MainWindow::readConfigFile()
{
    return "Qt";
}

void MainWindow::on_pushButton_moveCamera_clicked()
{
    if (ui->comboBoxModel->count() == 0)
    {
        return;
    }
    std::string cam_name = ui->comboBoxCamera->currentText().toStdString();
    char *chrstr = new char[cam_name.length() + 1];
    strcpy(chrstr, cam_name.c_str());
    double x = ui->doubleSpinBoxDx_c->value();
    double y = ui->doubleSpinBoxDy_c->value();
    double z = ui->doubleSpinBoxDz_c->value();

    try
    {
        Point moving(x, y, z);
        Point rotateing(0, 0, 0);
        std::shared_ptr<Command> command(new TransformCameraAction(chrstr, moving, rotateing));
        facade_viewer->executeCommand(command);
    }
    catch (ExceptionApps& error)
    {
        cout << "Error: " << error.what() << endl;
    }
    catch (std::exception& error)
    {
        cout << error.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown Error" << endl;
    }
    render();
}

void MainWindow::on_pushButton_rotateCamera_clicked()
{
    if (ui->comboBoxModel->count() == 0)
    {
        return;
    }
    std::string cam_name = ui->comboBoxCamera->currentText().toStdString();
    char *chrstr = new char[cam_name.length() + 1];
    strcpy(chrstr, cam_name.c_str());
    double angle_x = ui->doubleSpinBoxOx_c->value();
    double angle_y = ui->doubleSpinBoxOy_c->value();
    double angle_z = ui->doubleSpinBoxOz_c->value();

    try
    {
        Point moving(0, 0, 0);
        Point rotateing(angle_x, angle_y, angle_z);
        std::shared_ptr<Command> command(new TransformCameraAction(chrstr, moving, rotateing));
        facade_viewer->executeCommand(command);
    }
    catch (ExceptionApps& error)
    {
        cout << "Error: " << error.what() << endl;
    }
    catch (std::exception& error)
    {
        cout << error.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown Error" << endl;
    }
    render();
}

void MainWindow::on_pushButton_removeCamera_clicked()
{
    if (ui->comboBoxCamera->count() == 0) {
        return;
    }
    try
    {
        std::string cam_name = ui->comboBoxCamera->currentText().toStdString();
        char *chrstr = new char[cam_name.length() + 1];
        strcpy(chrstr, cam_name.c_str());
        std::shared_ptr<Command> command(new RemoveCameraAction(chrstr));
        facade_viewer->executeCommand(command);
        ui->comboBoxCamera->removeItem(ui->comboBoxCamera->currentIndex());
        if (ui->comboBoxCamera->count() == 0)
        {
            QMessageBox::information(nullptr, "Attention", "Choose camera to render");
            pixmap.fill();
            ui->drawLabel->setPixmapPointer(pixmap);
            return;
        }
        render();
    }
    catch (ExceptionApps& error)
    {
        cout << "Error: " << error.what() << endl;
    }
    catch (std::exception& error)
    {
        cout << error.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown Error" << endl;
    }
}

void MainWindow::on_pushButton_removeModel_clicked()
{
    if (ui->comboBoxCamera->count() == 0) {
        return;
    }
    try
    {
        std::string model_name = ui->comboBoxModel->currentText().toStdString();
        char *chrstr = new char[model_name.length() + 1];
        strcpy(chrstr, model_name.c_str());
        std::shared_ptr<Command> command(new RemoveModelAction(chrstr));
        facade_viewer->executeCommand(command);
        ui->comboBoxModel->removeItem(ui->comboBoxModel->currentIndex());
        if (ui->comboBoxCamera->count() == 0)
        {
            QMessageBox::information(nullptr, "Attention", "Choose camera to render");
            pixmap.fill();
            ui->drawLabel->setPixmapPointer(pixmap);
            return;
        }
        if (ui->comboBoxModel->count() == 0)
        {
            pixmap.fill();
            ui->drawLabel->setPixmapPointer(pixmap);
            return;
        }
        render();
    }
    catch (ExceptionApps& error)
    {
        cout << "Error: " << error.what() << endl;
    }
    catch (std::exception& error)
    {
        cout << error.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown Error" << endl;
    }
}
