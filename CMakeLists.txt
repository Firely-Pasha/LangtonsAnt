cmake_minimum_required(VERSION 3.12)
project(LangtonsAnt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(Qt5Widgets_DIR "/opt/Qt/5.11.2/gcc_64/lib/cmake/Qt5Widgets")                        # Path to Qt5Widgets
set(Qt5Core_DIR "/opt/Qt/5.11.2/gcc_64/lib/cmake/Qt5Core")                              # Path to Qt5Core
set(Qt5OpenGL_DIR "/opt/Qt/5.11.2/gcc_64/lib/cmake/Qt5OpenGL")                          # Path to Qt5OpenGL

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(LangtonsAnt src/main.cpp src/ui/scene/Scene.cpp src/ui/scene/Scene.h src/ui/scene/GLWidget.cpp src/ui/scene/GLWidget.h src/ui/scene/SceneObject.cpp src/ui/scene/SceneObject.h src/ui/scene/Ant.cpp src/ui/scene/Ant.h src/ui/scene/Cell.cpp src/ui/scene/Cell.h src/data/config/Config.cpp src/data/config/Config.h src/data/config/AntConfig.cpp src/data/config/AntConfig.h src/data/config/FootstepConfig.cpp src/data/config/FootstepConfig.h src/ui/scene/CellType.cpp src/ui/scene/CellType.h)

target_link_libraries(LangtonsAnt ${Qt5Widgets_LIBRARIES} ${OPENGL_LIBRARIES})