// Copyright(C) 2019 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License: https://github.com/ayaromenok/YaSchengenCalc/blob/master/LICENSE

#include <QDebug>

#include "mainwindow.h"
#include "yaschengencalc.h"
#include "yaschengenwidget.h"

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
{
    qInfo() << __PRETTY_FUNCTION__;
    YaSchengenWidget *sw = new YaSchengenWidget(this);
    this->setCentralWidget(sw);
}

MainWindow::~MainWindow()
{
    qInfo() << __PRETTY_FUNCTION__;
}
