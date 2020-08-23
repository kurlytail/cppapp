
find_package(wxWidgets COMPONENTS net core base REQUIRED)
include(${wxWidgets_USE_FILE})

add_executable(glyph2d MainWindow.cc Glyph.cc)
target_link_libraries(glyph2d PUBLIC ${wxWidgets_LIBRARIES})