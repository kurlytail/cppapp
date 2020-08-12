
find_package(wxWidgets COMPONENTS net core base REQUIRED)
include(${wxWidgets_USE_FILE})
add_library(gui STATIC MainWindow.cc)
target_link_libraries(gui PUBLIC ${wxWidgets_LIBRARIES})