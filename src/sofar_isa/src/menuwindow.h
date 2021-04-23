#ifndef MENUWINDOW_H
#define MENUWINDOW_H


// #include <QWidget>
#include <QtWidgets/QMainWindow>
#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <sstream>

namespace Ui {
class menuWindow;
}

class menuWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit menuWindow(QWidget *parent = 0);
    void set(int value);
    void StatusCheckCallback (const std_msgs::Int32::ConstPtr& ID_reachedRoom);
    virtual ~menuWindow()= default;   //distructor



private slots:
    void on_room1_clicked();

    void on_room2_clicked();

    void on_room3_clicked();

    void on_exit_clicked();

private:
    Ui::menuWindow *ui;  //object to access all the widgets in the menu window
    int ID_NOW;
    int ID_CHECK;
    ros::Publisher pub;
    ros::NodeHandle n2;
    bool ongoing_check = false;
    int ID_goal;

};

#endif // MENUWINDOW_H
