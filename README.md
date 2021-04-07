
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT LOGO -->
<br />
<p align="center">

  <h3 align="center">Symbolic-based Path Planning inSimulated Smart Environment</h3>
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

The objective of this work is to implement behaviours based on communicable commandsthrough a mobile based interface deployed in a set up which simulate rooms of an apartment.
The project originally involved the use of the robot [MiRo-E](https://www.miro-e.com/robot), developed by [Consequential Robotics](http://consequentialrobotics.com/). 
Due to the COVID-19 health emergency, we had to work on a simulated model of the MiRo-E robot.  Unfortunately, MiRo does not have a laser-scanner on it, but it uses stereo-vision. Since our project involves the building of the environment map, we could not use the MiRo simulation model  found  that since its stereo-vision  is  not  capable  of  performing  this  operation.  This failure is caused by the overlap between the left-eye-camera and right-eye-camera, which is very small, therefore depth information is limited and insufficient. We decided instead to use theTurtlebot robotto be able to build the map and navigate within it.

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
      $ sudo apt-get install ros-indigo-ar-track-alvar
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
 
## How to run the project
This instructions assumes that you have installed **catkin**, if not it is necessary to follow the instruction at [catkin installation](https://wiki.ros.org/catkin#Installing_catkin). After installation source the environment:
 ```sh
 $ source /opt/ros/kinetic/setup.bash
 ```
1. Clone the repository 
   ```sh
   $ git clone https://github.com/CristinaNRR/SOFAR.git
   ```
2. Run the commands
  ```sh
   $ catkin_make
   $ source devel/setup.bash
   ```
3. You need to make sure that every node has the permission of execution. To do so, enter the folder *scripts* inside the package *beginner\_tutorials* and run the command line:
```sh
$ chmod +x filename.py
```
4. Launch the world in Gazebo, open a new terminal and execute the command below:
```sh
$ roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=home/user/catkin_ws/turtlebot_custom_gazebo_worlds/myworld.world 
```
5. Run the yaml file that contains the map of the world:
```sh
$ roslaunch turtlebot_gazebo amcl_demo.launch map_file:=home/user/catkin_ws/turtlebot_custom_maps/myworld.yaml
```  
6. Bring up the ArTrack node:
```sh
$ roslaunch beginner_tutorial tags.launch
``` 
7. Run all the remaining nodes
```sh
$ roslaunch beginner_tutorial sofar.launch
```

<!-- USAGE EXAMPLES 
## Usage

Use this space to show useful examples of how a project can be used. Additional screenshots, code examples and demos work well in this space. You may also link to more resources.

_For more examples, please refer to the [Documentation](https://example.com)_ -->



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




