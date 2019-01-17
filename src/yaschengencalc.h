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

private:
    QSettings   *sets;
};

#endif // YASCHENGENCALC_H
