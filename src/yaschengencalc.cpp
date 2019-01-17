#include "yaschengencalc.h"
#include <QDebug>
#include <QSettings>

YaSchengenCalc::YaSchengenCalc(QObject *parent) : QObject(parent)
{
//    qInfo() << __PRETTY_FUNCTION__;
    _settings = new QSettings("Andrey Yaromenok", "Schengen Calculator");
    _inDates = new QVector<qint64>;
    _outDates = new QVector<qint64>;
    _difDates = new QVector<qint64>;
}

YaSchengenCalc::~YaSchengenCalc()
{
//    qInfo() << __PRETTY_FUNCTION__;
    delete _settings;
    delete _inDates;
    delete _outDates;
    delete _difDates;
}

void
YaSchengenCalc::addDateRange(const QDate &in, const QDate &out)
{
//    qInfo() << __PRETTY_FUNCTION__ << in << out;
    qint64 inDay = in.toJulianDay();
    qint64 outDay = out.toJulianDay();

    if (outDay < inDay){
        qInfo() << "in & out dates sapped";
        qint64 tmp = inDay;
        inDay = outDay;
        outDay = tmp;
    }

    if ((outDay-inDay)>90){
        qWarning() << "wrong dates - duration more than 90 days"
                   << QDate::fromJulianDay(inDay)
                   << QDate::fromJulianDay(outDay)
                   << (outDay-inDay)
                   << "\nskip this dates";
        return;
    }

    _settings->setValue(QString::number(inDay),outDay);

    _inDates->append(inDay);
    _outDates->append(outDay);
    _difDates->append(outDay-inDay);
}

int
YaSchengenCalc::getInDuration()
{
    qInfo() << __PRETTY_FUNCTION__;
    return 0;
}


int
YaSchengenCalc::getAddDuration()
{
    qInfo() << __PRETTY_FUNCTION__;
    return 0;
}

void
YaSchengenCalc::dumpAllInfo()
{
    qInfo() << __PRETTY_FUNCTION__;

    qInfo() << _inDates->toList();
    qInfo() << _outDates->toList();
    qInfo() << _difDates->toList();
}

