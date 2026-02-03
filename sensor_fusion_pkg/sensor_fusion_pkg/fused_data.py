import rclpy
from rclpy.node import Node

from std_msgs.msg import Float32
from sensor_msgs.msg import Imu

class FusedData(Node):

    def __init__(self):
        super().__init__('fused_data')
        self._imu_subscription = self.create_subscription(
            Imu,
            '/imu/data',
            self._imu_listener_callback,
            10
        )
        self._depth_subscription = self.create_subscription(
            Float32,
            '/depth',
            self._depth_listener_callback,
            10
        )
        self._publisher_ = self.create_publisher(Float32, 'vertical_velocity', 10)
        self._timer = self.create_timer(0.1, self.timer_callback)
        self._last_imu = 0
        self._last_depth = 0

    def _imu_listener_callback(self, msg):

        self._last_imu = msg.data

    def _depth_listener_callback(self, msg):

        self._last_depth = msg.data

    def timer_callback(self):

        self.get_logger().info(f'Depth: {self._last_depth}, IMU: {str(self._last_imu)}')

        # fuse data here and fill message

        msg = Float32()

        self._publisher_.publish(msg)



def main(args=None):
    rclpy.init(args=args)

    fused_data = FusedData()

    rclpy.spin(fused_data)

    fused_data.destroy_node()

    rclpy.shutdown()

if __name__ == '__main__':

    main()