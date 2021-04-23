#include "menuwindow.h"
#include "welcome.h"
#include <QApplication>

#include <cstdlib>
#include <iostream>
#include <string>
#include "ros/ros.h"

int main(int argc, char *argv[])
{

    ros::init(argc, argv, "GUI");
    ros::NodeHandle n;


    QApplication a(argc, argv); //object creation
    welcome *wel= new welcome(); //creates the window

    wel->show();  //visualize the window
    ros::AsyncSpinner spinner(0);
    spinner.start();
    ros::Subscriber sub = n.subscribe("/topicPathPlanner_IdNow", 1000, &welcome::StatusNowCallback, wel);


    a.exec(); //execute the code
    ros::waitForShutdown();
    return 0;
}
