# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Declares and names the project.

project("ancrash")
set(TARGET ancrash)
# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        ancrash

        # Sets the library as a shared library.
        SHARED


        coffe/coffeecatch.c
        coffe/coffeejni.c
        # Provides a relative path to your source file(s).
        native-lib.cpp)


# 添加包含目录头文件
target_include_directories(ancrash PUBLIC
        coffe
        include
        )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

# 静态链接库，也就是说当前项目需要使用到的库！第三方或者系统的
target_link_libraries( # Specifies the target library.
        ancrash
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})