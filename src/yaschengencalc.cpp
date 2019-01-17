#include "yaschengencalc.h"
#include <QDebug>
#include <QSettings>

YaSchengenCalc::YaSchengenCalc(QObject *parent) : QObject(parent)
{
    qInfo() << __PRETTY_FUNCTION__;
    sets = new QSettings("Andrey Yaromenok", "Schengen Calculator");
}

YaSchengenCalc::~YaSchengenCalc()
{
    qInfo() << __PRETTY_FUNCTION__;
    delete sets;
}

void
YaSchengenCalc::addDateRange(const QDate &in, const QDate &out)
{
    qInfo() << __PRETTY_FUNCTION__ << in << out;
    sets->setValue(QString::number(in.toJulianDay()),out.toJulianDay());

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

