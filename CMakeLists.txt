cmake_minimum_required(VERSION 3.22)
project(practice_7 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 关键修改：添加 PrintSupport 组件
find_package(Qt6 REQUIRED COMPONENTS Widgets PrintSupport)
qt_standard_project_setup()

qt_add_executable(
        notepad
        main.cpp
        main_window.h
        main_window.cpp
        text_transform.h
        find_replace_dialog.ui
        word_frequency_dialog.ui
        spell_checker.h
        spell_checker.cpp
)

# 正确链接两个库
target_link_libraries(notepad PRIVATE Qt6::Widgets Qt6::PrintSupport)

add_executable(
        test_sort
        test_sort.cpp
        sort.h
)
# 注意：test_sort 不需要链接 Qt，如果它确实需要，请添加相应的 target_link_libraries