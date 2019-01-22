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
    _vecVisitedDates->clear();
    _vecVisitedDates->squeeze();
}

void
YaSchengenWidget::createTestLayout()
{
    qInfo() << __PRETTY_FUNCTION__;

    _lout = new QVBoxLayout();
    _cal = new QCalendarWidget();
    _cal->showToday();


    _lout->addWidget(_cal);

    createCurStatusUI();
    createVisitedDatesUI();
    this->setLayout(_lout);
}

void
YaSchengenWidget::createCurStatusUI()
{
    qInfo() << __PRETTY_FUNCTION__;

    _gbCurStatus = new QGroupBox("Currents status");
    _loutCurStatus = new QGridLayout(_gbCurStatus);

    _loutCurStatus->setColumnStretch(0,3); //higher is wider column
    _loutCurStatus->setColumnStretch(1,1);
    _loutCurStatus->setColumnStretch(2,1);

    _loutCurStatus->addWidget(new QLabel("Days to visit"),0,0);
    _loutCurStatus->addWidget(new QLabel("43"),0,1);
    _loutCurStatus->addWidget(new QLabel("day(s)"),0,2);

    _loutCurStatus->addWidget(new QLabel("Of 90 Day visit:"),1,0);
    _loutCurStatus->addWidget(new QLabel("47"),1,1);
    _loutCurStatus->addWidget(new QLabel("day(s) used"),1,2);

    _loutCurStatus->addWidget(new QLabel("Of 180 Day period:"),2,0);
    _loutCurStatus->addWidget(new QLabel("121"),2,1);
    _loutCurStatus->addWidget(new QLabel("day(s) used"),2,2);

    //_loutCurStatus->addWidget(new QLabel(""),0,0);

    _lout->addWidget(_gbCurStatus);
}

void
YaSchengenWidget::createVisitedDatesUI()
{
    qInfo() << __PRETTY_FUNCTION__;
    _gbVisitedDates = new QGroupBox("Dates of previous visits");
    _vecVisitedDates = new QVector<QDateEdit*>;
    _vecVisitedDates->append(new QDateEdit(QDate(2018,10,10)));
    _vecVisitedDates->append(new QDateEdit(QDate(2018,11,11)));
    _vecVisitedDates->append(new QDateEdit(QDate(2018,5,15)));
    _vecVisitedDates->append(new QDateEdit(QDate(2018,6,16)));

    _loutVisitedDates = new QGridLayout(_gbVisitedDates);

    _loutVisitedDates->setColumnStretch(0,3); //higher is wider column
    _loutVisitedDates->setColumnStretch(1,3);
    _loutVisitedDates->setColumnStretch(2,2);
    _loutVisitedDates->setColumnStretch(3,1);
    _loutVisitedDates->setColumnStretch(4,1);

    for (int i=0; i<(_vecVisitedDates->length()/2); i++){
        _loutVisitedDates->addWidget(_vecVisitedDates->at(i*2),i,0);
        _loutVisitedDates->addWidget(_vecVisitedDates->at(i*2+1),i,1);
        _loutVisitedDates->addWidget(new QLabel("duration:"), i, 2);
        _loutVisitedDates->addWidget(new QLabel("00"), i, 3);
        _loutVisitedDates->addWidget(new QLabel("days"), i, 4);
    }
    _gbVisitedDates->setLayout(_loutVisitedDates);

    _lout->addWidget(_gbVisitedDates);

}
