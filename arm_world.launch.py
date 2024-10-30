from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='ros_gz_sim',
            executable='create',
            arguments=['-file', '<path_to_urdf_file>', '-name', 'arm'],
            output='screen'
        )
    ])
