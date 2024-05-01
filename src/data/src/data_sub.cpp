#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;
 int y = 0;
 int degreesX = 0;
int degreesY = 0;
float map(float x, float in_min, float in_max, float out_min, float out_max);

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
      RCLCPP_INFO(this->get_logger(), "Gyro X: %fdeg/s", msg.data);
      y++;
      } else if(y==1){
      RCLCPP_INFO(this->get_logger(), "Gyro Y: %f deg/s", msg.data);
      y++;
      }else if(y==2){
      RCLCPP_INFO(this->get_logger(), "Gyro Z: %f deg/s", msg.data);
      y++;
      }else if(y==3){
      RCLCPP_INFO(this->get_logger(), "Accel X: %f G's", msg.data);
      float x =msg.data;
      if(x > 0.1){

    x = 100*x;

    degreesX = map(x, 0, 97, 0, 90);
    RCLCPP_INFO(this->get_logger(), "Tilting up: %d degrees", degreesX);
    }

  if(x < -0.1){

    x = 100*x;

    degreesX = map(x, 0, -100, 0, 90);

    RCLCPP_INFO(this->get_logger(), "Tilting down: %d degrees", degreesX);

    }
      y++;
      }else if(y==4){
        float x =msg.data;
      RCLCPP_INFO(this->get_logger(), "Accel Y: %f G's", msg.data);
        if(x > 0.1){

    x = 100*x;

    degreesY = map(x, 0, 97, 0, 90);

  

    RCLCPP_INFO(this->get_logger(), "Tilting left: %d degrees", degreesY);



    }

  if(x < -0.1){

    x = 100*x;

    degreesY = map(x, 0, -100, 0, 90);

    RCLCPP_INFO(this->get_logger(), "Tilting right: %d degrees", degreesY);

    }
      y++;
      }else if(y==5){
      RCLCPP_INFO(this->get_logger(), "Accel Z: %f G's", msg.data);
      y++;
      }else if(y==6){
      RCLCPP_INFO(this->get_logger(), "Magn X: %f Gauss", msg.data);
      y++;
      }else if(y==7){
      RCLCPP_INFO(this->get_logger(), "Magn Y: %f Gauss", msg.data);
      y++;
      }else if(y==8){
      RCLCPP_INFO(this->get_logger(), "Magn Z: %f Gauss", msg.data);
      y++;
      }else if(y==9){
      RCLCPP_INFO(this->get_logger(), "Pressure: %f kPa", msg.data);
      y++;
      }else if(y==10){
      RCLCPP_INFO(this->get_logger(), "Altitude: %f m", msg.data);
      y++;
      }else if(y==11){
      RCLCPP_INFO(this->get_logger(), "Temperature: %f °C", msg.data);
      y++;
      }else if(y==12){
      RCLCPP_INFO(this->get_logger(), "Humidity: %f %%", msg.data);
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

float map(float x, float in_min, float in_max, float out_min, float out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
