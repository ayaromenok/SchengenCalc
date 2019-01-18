#ifndef YASCHENGENCALC_H
#define YASCHENGENCALC_H

#include <QObject>
#include <QDate>

class QSettings;

class YaSchengenCalc : public QObject
{
    Q_OBJECT
public:
    explicit YaSchengenCalc(QObject *parent = nullptr);
    ~YaSchengenCalc();

signals:

public slots:
    void addDateRange(const QDate &in, const QDate &out);
    int getInDuration();
    int getAddDuration();
    qint64 get180DaysFromDate(const QDate &date);
    qint64 get180DaysFromNow();

    void dumpAllInfo();

private:

    QSettings               *_settings;
    QVector<qint64>         *_inDates;
    QVector<qint64>         *_outDates;
    QVector<qint64>         *_difDates;
};

#endif // YASCHENGENCALC_H
