# maidbot

## Getting Started

### Version
* ROS Indigo


### Setting Up
Go to your ROS workspace by opening a terminal and typing:
```
cd catkin_ws
source devel/setup.bash
```
Go to your src folder and clone this repo:
```
cd src
git clone https::/github.com/ajaymehul/maidbot_tf.git
```
Build the package using catkin_make from root workspace directory:
```
cd ~/catkin_ws
catkin_make
```

### Launch
Use roslaunch to launch the nodes and rviz:
```
roslaunch maidbot start_demo.launch
```


