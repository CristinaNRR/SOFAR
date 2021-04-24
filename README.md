
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT LOGO -->
<br />
<p align="center">

  <h3 align="center">Symbolic-based Path Planning in Simulated Smart Environment</h3>
</p>



<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
<!--    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgements">Acknowledgements</a></li>
  </ol> -->
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

The objective of this work is to simulate in Gazebo a three rooms apartment and use the Turtlebot robot to navigate it, relying on a priori knowledge of the map of the environment.
The project originally involved the use of the robot [MiRo-E](https://www.miro-e.com/robot), developed by [Consequential Robotics](http://consequentialrobotics.com/). 
In agreement with our tutors, due to the COVID-19 health emergency, we decided to work on a simulated model of TurtleBot3 robot.  The MiRo robot is not equipped with based laser-scanner cameras, but it only uses stereo-vision. This way we were able to build in advance a map of the environment and use it to navigate the simulated apartment.

### Built With

The project was built using:
* [Ubuntu 16.04 LTS](https://releases.ubuntu.com/16.04/)
* [ROS Kinetic](http://wiki.ros.org/kinetic)
* [Gazebo 7.3.0](http://gazebosim.org/tutorials?cat=install&tut=install_other_linux&ver=5.0)


<!-- PREREQUISITES -->

## Prerequisites

### Ros
this project is developed using [ROS Kinetic](http://wiki.ros.org/kinetic/Installation/Ubuntu). Follow [instructions](http://wiki.ros.org/kinetic/Installation/Ubuntu) for installation.

### Gazebo
this project is developed using [Gazebo 7.3.0](http://gazebosim.org/tutorials?cat=guided_b&tut=guided_b1). Follow [instructions](http://gazebosim.org/tutorials?cat=guided_b&tut=guided_b1) for installation.

### Turtlebot3 
The *TurtleBot3 Simulation* package requires *turtlebot3* and *turtlebot3_msgs* packages as prerequisite. 

* Install Dependent ROS 1 Packages:
  ```sh
  $ sudo apt-get install ros-kinetic-joy ros-kinetic-teleop-twist-joy \ ros-kinetic-teleop-twist-keyboard ros-kinetic-laser-proc \ ros-kinetic-rgbd-launch ros-kinetic-depthimage-to-laserscan \ ros-kinetic-rosserial-arduino ros-kinetic-rosserial-python \ ros-kinetic-rosserial-server ros-kinetic-rosserial-client \ ros-kinetic-rosserial-msgs ros-kinetic-amcl ros-kinetic-map-server \ ros-kinetic-move-base ros-kinetic-urdf ros-kinetic-xacro \ ros-kinetic-compressed-image-transport ros-kinetic-rqt* \ ros-kinetic-gmapping ros-kinetic-navigation ros-kinetic-interactive-markers
  ```
 *  Install TurtleBot3 Packages
    ```sh
      $ sudo apt-get install ros-kinetic-dynamixel-sdk
      $ sudo apt-get install ros-kinetic-turtlebot3-msgs
      $ sudo apt-get install ros-kinetic-turtlebot3   
    ```
### Ar_track_alvar package
Th [ar_track_alvar package](http://wiki.ros.org/ar_track_alvar) is a ROS wrapper for [Alvar](http://virtual.vtt.fi/virtual/proj2/multimedia/index.html), an open source AR tag tracking library.
* Install the ar\_track\_alvar package:
  ```sh
      $ sudo apt-get install ros-kinetic-ar-track-alvar
      $ sudo apt-get install ros-kinetic-ar-track-alvar-msgs
   ```
### AR tags in Gazebo
It is necessary to generate gazebo models for the AR tags. We use the following [repository](\url{https://github.com/mikaelarguedas/gazebo_models}) to do so.
* Clone the required repository:
  ```sh
     $ git clone https://github.com/mikaelarguedas/gazebo_models.git
   ```
* Generate AR tags:
 ```sh
    $ ./generate_markers_model.py -i IMAGE_DIRECTORY -s 1000 -w 500
 ```
### Qt creator
To run the Graphical User Interface (GUI), it is required a specific setup of the environment. The GUI developed in Qt Creator is connected to the ROS workspace, to easily pass the variable’s parameters from one side to the other.  
Follow the tutorial’s step _How to Install (Developers)_, that can be found at this [link](https://ros-qtc-plugin.readthedocs.io/en/latest/).
At the following [link](https://ros-qtc-plugin.readthedocs.io/en/latest/_source/Improve-ROS-Qt-Creator-Plugin-Developers-ONLY.html) follow the instruction _Installation Procedure for Ubuntu 16.04_ and _Configure system to use the new version of Qt_ as follow:
1. Installation Procedure for Ubuntu 16.04
 ```sh
sudo add-apt-repository ppa:levi-armstrong/qt-libraries-xenial
sudo add-apt-repository ppa:levi-armstrong/ppa
sudo apt-get update && sudo apt-get install qt57creator-plugin-ros libqtermwidget57-0-dev
 ```
 2. Run this command to tell _qtchooser_ where to find this install opening the file _default.conf_ 
  ```sh
sudo gedit /usr/lib/x86_64-linux-gnu/qt-default/qtchooser/default.conf
 ```
 3. Add the following lines in the file:
  ```sh
 /opt/qt57/bin
 /opt/qt57/lib
 ```
 
## How to run the project
This instructions assumes that you have installed **catkin**, if not it is necessary to follow the instruction at [catkin installation](https://wiki.ros.org/catkin#Installing_catkin). After installation source the environment:
 ```sh
 $ source /opt/ros/kinetic/setup.bash
 ```
1. Clone the repository 
   ```sh
   $ git clone https://github.com/CristinaNRR/SOFAR.git
   ```
2. Run the commands. 
  ```sh
   $cd SOFAR
   $ catkin_make
   $ source devel/setup.bash
   ```
3. You need to make sure that every node has the permission of execution. To do so, enter the folder *scripts* inside the package *beginner\_tutorials* and run the command line:
```sh
$ chmod +x filename.py
```
4. Open a new terminal, launch the world in Gazebo, open a new terminal and execute the command below. **N.B. remember to change the user and give the correct path**
```sh
$ roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/<user>/SOFAR/turtlebot_custom_gazebo_worlds/myworld.world 
```
5. Open a new terminal, run the yaml file that contains the map of the world:
```sh
$ roslaunch turtlebot_gazebo amcl_demo.launch map_file:=/home/<user>/SOFAR/turtlebot_custom_maps/myworld.yaml
```  
6. Open a new terminal, bring up the ArTrack node:
```sh
$ roslaunch beginner_tutorial tags.launch
``` 
7. Open a new terminal, open the GUI:
```sh
$ rosrun sofar_isa sofar_isa_node
``` 
9.  Open a new terminal and run all the remaining nodes
```sh
$ roslaunch beginner_tutorial sofar.launch
```

<!-- USAGE EXAMPLES 
## Usage

Use this space to show useful examples of how a project can be used. Additional screenshots, code examples and demos work well in this space. You may also link to more resources.

_For more examples, please refer to the [Documentation](https://example.com)_ -->

##Usage example
A video showing how our architecture works in real time can be found at the following [link]()


<!-- ROADMAP 
## Roadmap

See the [open issues](https://github.com/othneildrew/Best-README-Template/issues) for a list of proposed features (and known issues). -->



<!-- CONTRIBUTING 
## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request -->



<!-- LICENSE 
## License -->




<!-- CONTACT -->
## Contact

* Isabella-Sole Bisio  - S4113265@studenti.unige.it
* Cristina Naso Rappis - S4378585@studenti.unige.it
* Serena Roncagliolo . S4233330@studenti.unige.it


Project Link: [https://github.com/CristinaNRR/SOFAR.git](https://github.com/CristinaNRR/SOFAR.git)



<!-- ACKNOWLEDGEMENTS 
## Acknowledgements
* [GitHub Emoji Cheat Sheet](https://www.webpagefx.com/tools/emoji-cheat-sheet)
* [Img Shields](https://shields.io)
* [Choose an Open Source License](https://choosealicense.com)
* [GitHub Pages](https://pages.github.com)
* [Animate.css](https://daneden.github.io/animate.css)
* [Loaders.css](https://connoratherton.com/loaders)
* [Slick Carousel](https://kenwheeler.github.io/slick)
* [Smooth Scroll](https://github.com/cferdinandi/smooth-scroll)
* [Sticky Kit](http://leafo.net/sticky-kit)
* [JVectorMap](http://jvectormap.com)
* [Font Awesome](https://fontawesome.com)-->




