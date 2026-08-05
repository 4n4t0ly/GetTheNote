cmake_minimum_required(VERSION 3.19)
project(GetTheNote LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools)

qt_standard_project_setup()

qt_add_executable(GetTheNote
    WIN32 MACOSX_BUNDLE
    src/main.cpp
    src/mainwindow.cpp
    include/mainwindow.h
)

target_link_libraries(GetTheNote
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS GetTheNote
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET GetTheNote
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
