// Copyright(C) 2019 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License: https://github.com/ayaromenok/YaSchengenCalc/blob/master/LICENSE

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
    _difDates->append(outDay-inDay+1);
}

qint64
YaSchengenCalc::getInDurationFromDate(const QDate &date)
{
    qInfo() << __PRETTY_FUNCTION__;
    qint64 result = 0;
    qint64 startDate = get180DaysFromDate(date);

    for (int i=0; i<_difDates->length(); i++){
        if (_inDates->at(i) >= startDate){
            qInfo() << "date full in range" << i << _difDates->at(i);
            result += _difDates->at(i);
        } else {
            if (_outDates->at(i) >= startDate){
                qInfo() << "date part in range" << i << (_outDates->at(i) - startDate);
                result += _difDates->at(i) - (startDate - _inDates->at(i) );
            } else {
                qInfo() << "date Not in range" << i << _difDates->at(i);
            }
        }
    }
    qInfo() << "days in schengen" << result << "from date" << date;
    return result;
}

qint64
YaSchengenCalc::getInDurationFromNow()
{
    return getInDurationFromDate(QDate::currentDate());
}

qint64
YaSchengenCalc::getAddDurationFromDate(const QDate &date)
{
    qInfo() << __PRETTY_FUNCTION__;
    qint64 result = (90 - getInDurationFromDate(date));
    qInfo() << "days in schengen" << result << "from date" << date;

    return result;
}

qint64
YaSchengenCalc::getAddDurationFromNow()
{
    return getAddDurationFromDate(QDate::currentDate());
}
qint64
YaSchengenCalc::get180DaysFromDate(const QDate &date)
{
    qInfo() << __PRETTY_FUNCTION__
            << QDate::fromJulianDay(date.toJulianDay()-180);
    return (date.toJulianDay()-180);
}

qint64
YaSchengenCalc::get180DaysFromNow()
{
    qInfo() << __PRETTY_FUNCTION__
            << QDate::fromJulianDay(QDate::currentDate().toJulianDay()-180);
    return (QDate::currentDate().toJulianDay()-180);
}

void
YaSchengenCalc::dumpAllInfo()
{
    qInfo() << __PRETTY_FUNCTION__;

    for (int i=0; i< _difDates->length(); i++)
        qInfo() << QDate::fromJulianDay(_inDates->at(i)).toString()
                << QDate::fromJulianDay(_outDates->at(i)).toString()
                << "\t:" <<_difDates->at(i) << "days";

}

