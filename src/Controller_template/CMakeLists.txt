# cosinewave
add_executable(cosinewave_controller cosinewave.cpp BaseController.cpp)
add_dependencies(cosinewave_controller ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(cosinewave_controller  ${catkin_LIBRARIES})

# sinewave
add_executable(sinewave_controller sinewave.cpp BaseController.cpp)
add_dependencies(sinewave_controller ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(sinewave_controller  ${catkin_LIBRARIES})