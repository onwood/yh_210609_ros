#include "ros/ros.h"
#include "yh_210609_3/yh_srv_3.h"
#include <cstdlib> //atoll 이라는 함수 사용하려고 라이브러리 불러옴 - atoll(받아온 값을 분리해서 넣는 함수)

int main(int argc, char **argv)
{
	ros::init(argc, argv, "yh_client_3");
	if(argc != 3) //입력값이 들어오지 않으면
	{
		ROS_INFO("cmd : rosrun yh_210609_3 yh_client_3 arg0 arg1");
		ROS_INFO("arg0 : double number, arg1: double number");
		return 1;
	}

	ros::NodeHandle nh;
	ros::ServiceClient client = nh.serviceClient<yh_210609_3::yh_srv_3>("yh_service_3");
	
	yh_210609_3::yh_srv_3 srv;
	srv.request.a = atoll(argv[1]);
	srv.request.b = atoll(argv[2]);


	if(client.call(srv)) //서버로 요청을 보냈으면
	{
		ROS_INFO("send srv, srv.Request.a and b : %ld, %ld", (long int)srv.request.a, (long int)srv.request.b);
		ROS_INFO("receive srv, srv.Response.result : %ld", (long int)srv.response.result);
	}
	else //서버로 요청이 안 보내졌으면
	{
		ROS_ERROR("Failed to call service");
		return 1;
	}
	return 0;
}
