#include "ros/ros.h"
#include "yh_210609_3/yh_srv_3.h"

bool calculation(yh_210609_3::yh_srv_3::Request &req, yh_210609_3::yh_srv_3::Response &res)
{
	if(req.a > req.b)
	{
		res.result = req.a - req.b;
	}
	else
	{
		res.result = req.b - req.a;	
	}	


	ROS_INFO("request : x = %ld, y = %ld", (long int)req.a, (long int)req.b);
	ROS_INFO("sending back response : %ld", (long int)res.result);

	return true;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "yh_server_3");
	ros::NodeHandle nh;

	ros::ServiceServer server = nh.advertiseService("yh_service_3", calculation); //("서비스명", 함수)

	ROS_INFO("ready srv server!!");

	ros::spin();

	return 0;
}
