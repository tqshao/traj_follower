#include "ros/ros.h"
#include <ros/console.h>
#include "std_msgs/String.h"
#include <sstream>
//#include "traj_gen_chrono/Control.h"

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */


int main(int argc, char **argv)
{

  ros::init(argc, argv, "Reference");
  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle a;
  std::vector<double> x1;
  std::vector<double> y1;
  std::vector<double> x2(2,200);
  std::vector<double> y2(2,0);
//  XmlRpc::XmlRpcValue x1,y1;
  // a.getParam("vehicle/chrono/nloptcontrol_planner/traj/x",x1);
  // a.getParam("vehicle/chrono/nloptcontrol_planner/traj/yVal",y1);

  ros::Rate loop_rate(1);

  double count = 0;
  while (ros::ok())
  {
    x2[0]= 0.0;
    x2[1]= 50;
    y2[0]= 0.0;
    y2[1]= count;
    a.setParam("vehicle/chrono/default/traj/x",x2);
    a.setParam("vehicle/chrono/default/traj/yVal",y2);
    count += 1;
    loop_rate.sleep();
  }


  return 0;
}
