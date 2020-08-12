

#add_executable(stocks main.cc MainWindow.cc)
#target_link_libraries(stocks stocklib)
#target_link_libraries(stocks Qt5::Widgets)

add_executable(stocks main.cc)
target_link_libraries(stocks stocklib)
target_link_libraries(stocks gui)