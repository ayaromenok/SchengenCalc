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

    sc.addDateRange(QDate(2018,9,16), QDate(2018,10,22));
    sc.addDateRange(QDate(2018,11,25), QDate(2019,1,10));
    sc.getInDuration();
    sc.getAddDuration();

    sc.dumpAllInfo();

    return a.exec();
}
