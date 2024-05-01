#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
using std::placeholders::_1;
using namespace std;
 int y = 0;
 float value;
 int count = 0;
 float n = 1079;
 float arr[1079];
class ReadLaser : public rclcpp::Node
{
  public:
    ReadLaser()
    : Node("scan_data")
    {
      subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
      "/scan", 10, std::bind(&ReadLaser::topic_callback, this, _1));
      
      publisher_ = this->create_publisher<std_msgs::msg::Float32>("value", 10);
      timer_ = this->create_wall_timer(
      500ms, std::bind(&ReadLaser::timer_callback, this));
    }

  private:
    void topic_callback(const sensor_msgs::msg::LaserScan & msg) const
    {
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
      value = min;
  }

      RCLCPP_INFO(this->get_logger(), "I heard: '%f'",min);
    }
        void timer_callback()
    {
      auto message = std_msgs::msg::Float32();
      message.data = value;
      RCLCPP_INFO(this->get_logger(), "Publishing: '%f'", value);
      publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subscription_;
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_;
    size_t count_;
};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ReadLaser>());
  rclcpp::shutdown();
  return 0;
}
