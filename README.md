
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

### Installation

1. Get a free API Key at [https://example.com](https://example.com)
2. Clone the repo
   ```sh
   git clone https://github.com/your_username_/Project-Name.git
   ```
3. Install NPM packages
   ```sh
   npm install
   ```
4. Enter your API in `config.js`
   ```JS
   const API_KEY = 'ENTER YOUR API';
   ```



<!-- USAGE EXAMPLES -->
## Usage

Use this space to show useful examples of how a project can be used. Additional screenshots, code examples and demos work well in this space. You may also link to more resources.

_For more examples, please refer to the [Documentation](https://example.com)_ 



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



<!-- LICENSE -->
## License




<!-- CONTACT -->
## Contact

Your Name - [@your_twitter](https://twitter.com/your_username) - email@example.com

Project Link: [https://github.com/your_username/repo_name](https://github.com/your_username/repo_name)



<!-- ACKNOWLEDGEMENTS -->
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
* [Font Awesome](https://fontawesome.com)



