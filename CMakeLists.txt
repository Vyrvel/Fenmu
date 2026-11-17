cmake_minimum_required(VERSION 3.19)
project(Fenmu LANGUAGES CXX)

include(GNUInstallDirs)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools)
find_package(PkgConfig REQUIRED)

pkg_check_modules(LIBALPM REQUIRED IMPORTED_TARGET libalpm)

qt_standard_project_setup()

qt_add_executable(Fenmu
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.hpp
    mainwindow.ui
    packagemanager.hpp
    packagemanager.cpp
)

qt_add_translations(
    TARGETS Fenmu
    TS_FILES Fenmu_en_US.ts
)

target_link_libraries(Fenmu
    PRIVATE
        Qt::Core
        Qt::Widgets
        PkgConfig::LIBALPM
)

install(TARGETS Fenmu
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Fenmu
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})