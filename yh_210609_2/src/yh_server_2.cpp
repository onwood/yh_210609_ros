#include "ros/ros.h"
#include "yh_210609_2/yh_srv_2.h"

bool calculation(yh_210609_2::yh_srv_2::Request &req, yh_210609_2::yh_srv_2::Response &res)
{
	res.result = req.a + req.b + req.c;

	ROS_INFO("request : x = %ld, y = %ld, z=%ld", (long int)req.a, (long int)req.b, (long int)req.c);
	ROS_INFO("sending back response : %ld", (long int)res.result);

	return true;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "yh_server_2");
	ros::NodeHandle nh;

	ros::ServiceServer server = nh.advertiseService("yh_service_2", calculation); //("서비스명", 함수)

	ROS_INFO("ready srv server!!");

	ros::spin();

	return 0;
}
