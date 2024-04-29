#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;
 int y = 0;
class MinimalSubscriber : public rclcpp::Node
{
  public:
    MinimalSubscriber()
    : Node("minimal_subscriber")
    {
      subscription_ = this->create_subscription<std_msgs::msg::Float32>(
      "/raw_sensor_data", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
    }

  private:
    void topic_callback(const std_msgs::msg::Float32 & msg) const
    {
      if (y==0){
      RCLCPP_INFO(this->get_logger(), "1:'%f'", msg.data);
      y++;
      } else if(y==1){
      RCLCPP_INFO(this->get_logger(), "2:'%f'", msg.data);
      y++;
      }else if(y==2){
      RCLCPP_INFO(this->get_logger(), "3:'%f'", msg.data);
      y++;
      }else if(y==3){
      RCLCPP_INFO(this->get_logger(), "4:'%f'", msg.data);
      y++;
      }else if(y==4){
      RCLCPP_INFO(this->get_logger(), "5:'%f'", msg.data);
      y++;
      }else if(y==5){
      RCLCPP_INFO(this->get_logger(), "6:'%f'", msg.data);
      y++;
      }else if(y==6){
      RCLCPP_INFO(this->get_logger(), "7:'%f'", msg.data);
      y++;
      }else if(y==7){
      RCLCPP_INFO(this->get_logger(), "8:'%f'", msg.data);
      y++;
      }else if(y==8){
      RCLCPP_INFO(this->get_logger(), "9:'%f'", msg.data);
      y++;
      }else if(y==9){
      RCLCPP_INFO(this->get_logger(), "10:'%f'", msg.data);
      y++;
      }else if(y==10){
      RCLCPP_INFO(this->get_logger(), "11:'%f'", msg.data);
      y++;
      }else if(y==11){
      RCLCPP_INFO(this->get_logger(), "12:'%f'", msg.data);
      y++;
      }else if(y==12){
      RCLCPP_INFO(this->get_logger(), "13:'%f'", msg.data);
      y=0;
      }

    }
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
