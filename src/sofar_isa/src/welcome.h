#ifndef WELCOME_H
#define WELCOME_H


#include <QWidget>
#include <QtWidgets/QMainWindow>
#include "menuwindow.h"
#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <sstream>

namespace Ui {
class welcome;
}

class welcome : public QMainWindow
{
    Q_OBJECT

public:
    explicit welcome(QWidget *parent = 0);
    void StatusNowCallback(const std_msgs::Int32::ConstPtr& ID_currentRoom);

    virtual ~welcome() = default;

private slots:
    void on_start_clicked();


private:
    Ui::welcome *ui;
    menuWindow *menuWind;
    ros::Subscriber sub;
    int *ID_NOW;

};

#endif // WELCOME_H
