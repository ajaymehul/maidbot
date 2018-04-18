#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>


int main(int argc, char **argv){ 
  srand(time(NULL)); 
  ros::init(argc, argv, "lidar");
  ros::NodeHandle n;
  ros::Publisher lidar_pub = n.advertise<sensor_msgs::LaserScan>("scan", 50);

  ros::Rate loop_rate(10.0);
  int count = 0;

  sensor_msgs::LaserScan msg;
    
  unsigned int num_readings = 360;
  double laser_frequency = 10;
  double ranges[num_readings];
  double intensities[num_readings];

  while(n.ok()){
    msg.header.frame_id = "lidar";
    msg.angle_min = 0.0;
    msg.angle_max = 6.28;
    msg.angle_increment = 6.28/360.0;
    msg.range_min = 0.0;
    msg.range_max = 6.28;
  
    msg.time_increment= 1.0/360.0;
    msg.ranges.resize(360);
    msg.intensities.resize(360);
    msg.header.stamp= ros::Time::now();
    msg.time_increment = (1.0)/360.0;
    for(int i=0; i<360;i++){
	msg.ranges[i]=(rand()%400)/100.0;
	msg.intensities[i]=(rand()%100);
	}
    
	
    lidar_pub.publish(msg);

    
    ++count;
    loop_rate.sleep();
    
  }


  return 0;
}                                                                                  
