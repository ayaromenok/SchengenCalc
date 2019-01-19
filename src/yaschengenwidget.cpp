// Copyright(C) 2019 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License: https://github.com/ayaromenok/YaSchengenCalc/blob/master/LICENSE

#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCalendarWidget>

#include "yaschengenwidget.h"

YaSchengenWidget::YaSchengenWidget(QWidget *parent) : QWidget(parent)
{
    qInfo() << __PRETTY_FUNCTION__;
    _lout = new QVBoxLayout(this);
    _cal = new QCalendarWidget(this);
    _calNext = new QCalendarWidget(this);

    _cal->showToday();
    _calNext->showNextMonth();

    _lout->addWidget(_cal);
    _lout->addWidget(_calNext);

    this->setLayout(_lout);
}

YaSchengenWidget::~YaSchengenWidget()
{
    qInfo() << __PRETTY_FUNCTION__;
}

void
YaSchengenWidget::createTestLayout()
{

}
