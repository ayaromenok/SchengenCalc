// Copyright(C) 2019 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License: https://github.com/ayaromenok/YaSchengenCalc/blob/master/LICENSE

#include <QCoreApplication>
#include <QDebug>
#include <QDate>
#include "yaschengencalc.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "YaSchengenCalc/console";

    YaSchengenCalc sc;

//    sc.addDateRange(QDate(2018,1,10), QDate(2017,11,25)); //test: swap
//    sc.addDateRange(QDate(2016,1,10), QDate(2016,5,25)); //test: length

    sc.addDateRange(QDate(2018,6,25), QDate(2018,7,12));
    sc.addDateRange(QDate(2018,9,16), QDate(2018,10,22));
    sc.addDateRange(QDate(2018,11,25), QDate(2019,1,10));
    //sc.getInDurationFromDate(QDate(2019,3,15));
    sc.getAddDurationFromDate(QDate(2019,3,18));
    //sc.getAddDurationFromNow();
    sc.get180DaysFromNow();
    sc.get180DaysFromDate(QDate(2019,1,18));

    sc.dumpAllInfo();
    return a.exec();
}
