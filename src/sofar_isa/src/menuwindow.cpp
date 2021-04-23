#include "menuwindow.h"
#include "ui_menuwindow.h"
#include <QtWidgets/QMessageBox>


menuWindow::menuWindow(QWidget *parent):
  //ros::NodeHandle n) :
    QMainWindow(parent),
    ui(new Ui::menuWindow)  //initialize the object
{

    ui->setupUi(this); //open the window
    pub = n2.advertise<std_msgs::Int32>("topicPathPlanner_IdGoal", 1000);
    ID_CHECK=0;
}


void menuWindow::set(int value)
{
    ID_NOW = value;
    if (ID_NOW!=ID_goal && ongoing_check){

         ROS_INFO("Going to room: [%d]", ID_goal);

    }

    else if (ID_NOW == ID_goal && ongoing_check)
    {
        ongoing_check = false;
        ROS_INFO("Reached room: [%d]", ID_goal);
        ui->label->setText("Reached");

    }

}



void menuWindow::StatusCheckCallback (const std_msgs::Int32::ConstPtr& ID_reachedRoom)  //Int16 ??
{

 ROS_INFO("The reached room is: [%d]", ID_reachedRoom->data);
 ID_CHECK = ID_reachedRoom->data;

}




void menuWindow::on_room1_clicked()
{


    std_msgs::Int32 message;


    if (ID_NOW == 1)
    {
        QMessageBox::warning(this, "WARNING", "You are already in the desired room, \n please select another option");
    }

     else
     {

        if (!ongoing_check) {
          ID_goal = 1;
          ui->label->setText("Going To Room: 1");
          message.data= ID_goal;
          pub.publish(message);
          ongoing_check = true;
      }
        else
        {
          QMessageBox::warning(this, "WARNING", "Please wait for the robot to finish its ongoing task");
        }

     }

}


void menuWindow::on_room2_clicked()
{


    std_msgs::Int32 message;


    if (ID_NOW == 2)
    {
        QMessageBox::warning(this, "WARNING", "You are already in the desired room, \n please select another option");
    }

     else
     {

        if (!ongoing_check) {
          ID_goal = 2;
          ui->label->setText("Going To Room: 2");
          message.data= ID_goal;
          pub.publish(message);
          ongoing_check = true;
      }
        else
        {
          QMessageBox::warning(this, "WARNING", "Please wait for the robot to finish its ongoing task");
        }


     }

}



void menuWindow::on_room3_clicked()
{



    std_msgs::Int32 message;


    if (ID_NOW == 0)
    {
        QMessageBox::warning(this, "WARNING", "You are already in the desired room, \n please select another option");
    }

     else
     {
       if (!ongoing_check) {
         ID_goal = 0;
         ui->label->setText("Going To Room: 3");
         message.data= ID_goal;
         pub.publish(message);
         ongoing_check = true;
     }
       else
       {
         QMessageBox::warning(this, "WARNING", "Please wait for the robot to finish its ongoing task");
       }

     }

}

void menuWindow::on_exit_clicked()
{
  this->close();
}
