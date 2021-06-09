#include "ros/ros.h"
#include "yh_210609_1/yh_srv_1.h"

bool calculation(yh_210609_1::yh_srv_1::Request &req, yh_210609_1::yh_srv_1::Response &res)
{
	res.result = req.a * req.b;

	ROS_INFO("request : x = %ld, y = %ld", (long int)req.a, (long int)req.b);
	ROS_INFO("sending back response : %ld", (long int)res.result);

	return true;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "yh_server_1");
	ros::NodeHandle nh;

	ros::ServiceServer server = nh.advertiseService("yh_service_1", calculation); //("서비스명", 함수)

	ROS_INFO("ready srv server!!");

	ros::spin();

	return 0;
}
