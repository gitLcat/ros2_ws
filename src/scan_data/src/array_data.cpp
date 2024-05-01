#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
using std::placeholders::_1;
using namespace std;
 int y = 0;
class ReadLaser : public rclcpp::Node
{
  public:
    ReadLaser()
    : Node("scan_data")
    {
      subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
      "/scan", 10, std::bind(&ReadLaser::topic_callback, this, _1));
    }

  private:
    void topic_callback(const sensor_msgs::msg::LaserScan & msg) const
    {
      float n = 1079;
      float arr[1079];
      for(int i = 0; i <= n ; i++){
          arr[i] = msg.ranges[i];
      }
      float max = arr[0];
      float min = arr[0];
        for(int i=0; i<n; i++)
  {
      if(arr[i] > max)
      {
          max = arr[i];
      }
      if(arr[i] < min)
      {
          min = arr[i];
      }
  }


      RCLCPP_INFO(this->get_logger(), "I heard: '%f'",min);
    }
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ReadLaser>());
  rclcpp::shutdown();
  return 0;
}