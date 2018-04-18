#include <ros/ros.h>
#include <tf/transform_broadcaster.h>



int main(int argc, char** argv){
	ros::init( argc, argv, "bot_tf_broadcaster");
	ros::NodeHandle node;
	ros::Rate rate(10.0);

	double change = 0;

	
	static tf::TransformBroadcaster br;	
	tf::Transform transform;
	while(node.ok()){

		//tf::TransformBroadcaster br;
		//tf::Transform transform;
		transform.setOrigin( tf::Vector3(2.0*sin(change), 2.0*cos(change), 0.0) );
		transform.setRotation ( tf::Quaternion(0, 0, 0, 1));
		change += 0.1;

		br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "map", "bot"));
		rate.sleep();
	}
	return 0;
};
