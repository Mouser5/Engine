﻿cmake_minimum_required(VERSION 3.30)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)

# Указываем проект
project("Engine")

# Устанавливаем папку вывода исполняемых файлов
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>)

# Добавляем исполняемый файл
add_executable(Engine "main.cpp" "Engine.h" "Engine.cpp" "Subject.h" "Subject.cpp" "Wrapper.h" "Wrapper.cpp")

# Указываем путь к заголовочным файлам
target_include_directories(Engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
