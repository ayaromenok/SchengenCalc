// Copyright(C) 2019 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License: https://github.com/ayaromenok/YaSchengenCalc/blob/master/LICENSE

#include <QDebug>
#include <QtWidgets>

#include "yaschengenwidget.h"

YaSchengenWidget::YaSchengenWidget(QWidget *parent) : QWidget(parent)
{
    qInfo() << __PRETTY_FUNCTION__;
    createTestLayout();
}

YaSchengenWidget::~YaSchengenWidget()
{
    qInfo() << __PRETTY_FUNCTION__;
    _vecDates->clear();
    _vecDates->squeeze();
}

void
YaSchengenWidget::createTestLayout()
{
    qInfo() << __PRETTY_FUNCTION__;

    _lout = new QVBoxLayout();
    _cal = new QCalendarWidget();
    _cal->showToday();

    _gbDates = new QGroupBox("Dates");
    _vecDates = new QVector<QDateEdit*>;
    _vecDates->append(new QDateEdit(QDate(2018,10,10)));
    _vecDates->append(new QDateEdit(QDate(2018,11,11)));
    _vecDates->append(new QDateEdit(QDate(2018,5,15)));
    _vecDates->append(new QDateEdit(QDate(2018,6,16)));

    _loutDates = new QGridLayout(_gbDates);

    _loutDates->setColumnStretch(0,3); //higher is wider column
    _loutDates->setColumnStretch(1,3);
    _loutDates->setColumnStretch(2,2);
    _loutDates->setColumnStretch(3,1);
    _loutDates->setColumnStretch(4,1);

    for (int i=0; i<(_vecDates->length()/2); i++){
        _loutDates->addWidget(_vecDates->at(i*2),i,0);
        _loutDates->addWidget(_vecDates->at(i*2+1),i,1);
        _loutDates->addWidget(new QLabel("duration:"), i, 2);
        _loutDates->addWidget(new QLabel("00"), i, 3);
        _loutDates->addWidget(new QLabel("days"), i, 4);
    }
    _gbDates->setLayout(_loutDates);

    _lout->addWidget(_cal);
    _lout->addWidget(_gbDates);

    this->setLayout(_lout);
}
