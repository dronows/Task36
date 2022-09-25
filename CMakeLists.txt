# CMakeList.txt: проект CMake для Task36; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("Task36")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


# Добавьте источник в исполняемый файл этого проекта.
add_executable (Task36 "main.cpp" )
set(CMAKE_PREFIX_PATH "F:\\Qt\\5.12.12\\msvc2017_64\\lib\\cmake")
find_package(Qt5Widgets REQUIRED)
# TODO: Добавьте тесты и целевые объекты, если это необходимо.
target_link_libraries(Task36 Qt5::Widgets)
