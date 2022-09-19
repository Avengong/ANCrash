# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Declares and names the project.

project("ancatch")
set(TARGET ancatch)
# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror=implicit-function-declaration")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weverything ")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunreachable-code ")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror ")

#add_compile_options(
#        -std=c++11
#        -Weverything
#        -Wunreachable-code
#        -Werror)


add_library( # Sets the name of the library.
        ancatch
        # Sets the library as a shared library.
        SHARED

        exception_handler.cpp
        xcc_libc_support.c
        alog_print.cc
        xcc_util.c
        an_common.cpp
        xcc_fmt.c
        xcc_unwind.cpp
        xcc_unwind_libcorkscrew.cpp
        xcc_unwind_libunwind.c
        xcc_unwind_clang.c
        # Provides a relative path to your source file(s).
        ancatch.cpp)


# 添加包含目录头文件
target_include_directories(ancatch PUBLIC
        include
        cpp
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
        ancatch
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})


if (USEASAN)

    target_compile_options(ancatch PUBLIC
            -fsanitize=address
            -fno-omit-frame-pointer)

    set_target_properties(ancatch PROPERTIES
            LINK_FLAGS " \
        -fsanitize=address")

else ()

    target_compile_options(ancatch PUBLIC
            -Oz
            -flto
            -Wno-error=reserved-user-defined-literal
            -ffunction-sections
            -fdata-sections)

    set_target_properties(ancatch PROPERTIES
            LINK_FLAGS " \
        -O3 \
        -flto \
        -Wl,--exclude-libs,ALL \
        -Wl,--gc-sections \ "
            )

endif ()


#-Wl,--version-script=${CMAKE_CURRENT_SOURCE_DIR}/xcrash.exports