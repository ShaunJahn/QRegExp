#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "readfile.h"
#include "regexchecker.h"
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->checkButton->setEnabled(false);
    connect (ui->loadButton, SIGNAL(clicked()), this, SLOT(load()));
    connect(ui->checkButton, SIGNAL(clicked()), this, SLOT(check()));
}

void MainWindow::load()
{
    ReadFile rf;
    fileContents = rf.readFile(this);
    ui->checkButton->setEnabled(true);
}

void MainWindow::check()
{
    RegExChecker checker(fileContents);
    QStringList words = checker.check();
    foreach(QString str, words)
        ui->displayErrors->append(str);
    QMessageBox::information(this, "Done", "Checking completed");
}

MainWindow::~MainWindow()
{
    delete ui;
}
