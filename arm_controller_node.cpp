#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"

class ArmController : public rclcpp::Node {
public:
  ArmController() : Node("arm_controller_node") {
    joint_state_subscriber_ = this->create_subscription<sensor_msgs::msg::JointState>(
      "/joint_states", 10, std::bind(&ArmController::jointStateCallback, this, std::placeholders::_1));
    command_publisher_ = this->create_publisher<std_msgs::msg/Float64MultiArray>("/position_controller/command", 10);
  }

private:
  void jointStateCallback(const sensor_msgs::msg::JointState::SharedPtr msg) {
    std_msgs::msg::Float64MultiArray command_msg;
    command_publisher_->publish(command_msg);
  }

  rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_state_subscriber_;
  rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr command_publisher_;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ArmController>());
  rclcpp::shutdown();
  return 0;
}
