#include "welcome.h"
#include "ui_welcome.h"
#include <QPixmap>

welcome::welcome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::welcome)
{
    ui->setupUi(this);
    QPixmap pix("/home/cristina/sofar_ws/src/sofar_isa/src/gui_pic/map.png");
    ui->picture->setPixmap(pix.scaled(300, 300, Qt::KeepAspectRatio ));


}


void welcome::StatusNowCallback (const std_msgs::Int32::ConstPtr& ID_currentRoom)
{



  ROS_INFO("I am in room: [%d]", ID_currentRoom->data);
  int a = ID_currentRoom->data;
 if (menuWind != nullptr)
    {
      menuWind->set(a);

    }

}


void welcome::on_start_clicked()
{

 hide();
 menuWind = new menuWindow(this);
 menuWind->show();


}
