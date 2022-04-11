cmake_minimum_required(VERSION 3.0.2)
project(r3_comm_network)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES r3_comm_network
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(post_office_node src/nodes/post_office_node.cpp src/post_office.cpp src/comms_unit.cpp)
add_executable(mailman_node src/nodes/mailman_node.cpp src/mailman.cpp src/comms_unit.cpp src/letter_processor.cpp)
add_executable(mailbox_A src/nodes/mailbox_A.cpp src/mailbox.cpp src/comms_unit.cpp src/letter_processor.cpp)
add_executable(mailbox_B src/nodes/mailbox_B.cpp src/mailbox.cpp src/comms_unit.cpp src/letter_processor.cpp)

target_link_libraries(post_office_node ${catkin_LIBRARIES})
target_link_libraries(mailman_node ${catkin_LIBRARIES})
target_link_libraries(mailbox_A ${catkin_LIBRARIES})
target_link_libraries(mailbox_B ${catkin_LIBRARIES})