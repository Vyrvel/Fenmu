#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "packagemanager.hpp"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	if (PackageManager::UpdateSyncedDatabases() == 0) {
		std::cout << "Synced database" << std::endl;
	}
}

MainWindow::~MainWindow()
{
    delete ui;
}
