#include "ros/ros.h"
#include "geometry_msgs/Point.h"
#include "std_msgs/Float32.h"

int main(int argc, char **argv) {

  ros::init(argc, argv, "duz_git_node");
  ros::NodeHandle node_handle;
  ros::Publisher duz_git_pub = node_handle.advertise<geometry_msgs::Point>("cmd_vel", 10);
  geometry_msgs::Point hiz;
  std::cout << "Hiz Degeri Giriniz(m/s): " << '\n';
  std::cin >> hiz.x;
  std_msgs::Float32 mesafe;
  std::cout << "Mesafe Degeri Giriniz(m): " << '\n';
  std::cin >> mesafe.data;
  int zaman = 0;
  int yol = 0;
  ros::Rate pub_rate(1);
  while (yol < mesafe.data) {
    zaman++;
    yol = zaman * hiz.x;
    pub_rate.sleep();
  }
  hiz.x = 0;
  duz_git_pub.publish(hiz);
  std::cout << "Gecen Sure " << zaman << " Saniye" << '\n';
  ROS_INFO("Hedefe varildi!..");
  return 0;
}
