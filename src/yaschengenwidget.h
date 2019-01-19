// Copyright(C) 2019 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License: https://github.com/ayaromenok/YaSchengenCalc/blob/master/LICENSE

#ifndef YASCGENGENWIDGET_H
#define YASCGENGENWIDGET_H

#include <QObject>
#include <QWidget>

class QHBoxLayout;
class QVBoxLayout;
class QCalendarWidget;
class QDate;

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

    QVBoxLayout         *_lout;
    QCalendarWidget     *_cal;
    QCalendarWidget     *_calNext;
};

#endif // YASCHENGENWIDGET_H
