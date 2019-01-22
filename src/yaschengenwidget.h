// Copyright(C) 2019 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License: https://github.com/ayaromenok/YaSchengenCalc/blob/master/LICENSE

#ifndef YASCGENGENWIDGET_H
#define YASCGENGENWIDGET_H

#include <QObject>
#include <QWidget>

class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;
class QCalendarWidget;
class QGroupBox;
class QDateEdit;

class YaSchengenWidget : public QWidget
{
    Q_OBJECT
public:
    explicit YaSchengenWidget(QWidget *parent = nullptr);
    ~YaSchengenWidget();

signals:

public slots:

private:
    void createTestLayout();
    void createCurStatusUI();
    void createVisitedDatesUI();

    QVBoxLayout         *_lout;
    QCalendarWidget     *_cal;
    QCalendarWidget     *_calNext;

    QGroupBox           *_gbCurStatus;
    QGridLayout         *_loutCurStatus;

    QGroupBox           *_gbVisitedDates;
    QGridLayout         *_loutVisitedDates;
    QVector<QDateEdit*> *_vecVisitedDates;
};

#endif // YASCHENGENWIDGET_H
