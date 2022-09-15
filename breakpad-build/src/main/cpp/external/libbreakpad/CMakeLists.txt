# 指定版本  3.22.1 试试？？
cmake_minimum_required(VERSION 3.18.1)

# 指定了项目名字，支持所有的语言
#project(breakpad)
set(BREAKPAD_SRC ${CMAKE_CURRENT_SOURCE_DIR})
set(TARGET_NAME breakpad)

#target_include_directories(breakpad
#        ${BREAKPAD_SRC}/src
#        ${BREAKPAD_SRC}/src/common/android/include) // 这个会报错！！ 我去

include_directories(
        ${BREAKPAD_SRC}/src
        ${BREAKPAD_SRC}/src/common/android/include
)

file(GLOB BREAKPAD_COMMON_SRC
        ${BREAKPAD_SRC}/src/client/linux/crash_generation/crash_generation_client.cc
        ${BREAKPAD_SRC}/src/client/linux/dump_writer_common/thread_info.cc
        ${BREAKPAD_SRC}/src/client/linux/dump_writer_common/ucontext_reader.cc
        ${BREAKPAD_SRC}/src/client/linux/handler/exception_handler.cc
        ${BREAKPAD_SRC}/src/client/linux/handler/minidump_descriptor.cc
        ${BREAKPAD_SRC}/src/client/linux/log/log.cc
        ${BREAKPAD_SRC}/src/client/linux/microdump_writer/microdump_writer.cc
        ${BREAKPAD_SRC}/src/client/linux/minidump_writer/linux_dumper.cc
        ${BREAKPAD_SRC}/src/client/linux/minidump_writer/linux_ptrace_dumper.cc
        ${BREAKPAD_SRC}/src/client/linux/minidump_writer/minidump_writer.cc
        ${BREAKPAD_SRC}/src/client/minidump_file_writer.cc
        # .c --变成 .cc
        ${BREAKPAD_SRC}/src/common/convert_UTF.cc
        ${BREAKPAD_SRC}/src/common/md5.cc
        ${BREAKPAD_SRC}/src/common/string_conversion.cc
        ${BREAKPAD_SRC}/src/common/linux/elfutils.cc
        ${BREAKPAD_SRC}/src/common/linux/file_id.cc
        ${BREAKPAD_SRC}/src/common/linux/guid_creator.cc
        ${BREAKPAD_SRC}/src/common/linux/linux_libc_support.cc
        ${BREAKPAD_SRC}/src/common/linux/memory_mapped_file.cc
        ${BREAKPAD_SRC}/src/common/linux/safe_readlink.cc

        )

file(GLOB BREAKPAD_ASM_SOURCE
        # 路径从Android变成 linux
        ${BREAKPAD_SRC}/src/common/linux/breakpad_getcontext.S)


set_source_files_properties(${BREAKPAD_ASM_SOURCE} PROPERTIES LANGUAGE C)

# .a 编译一个静态库
add_library(breakpad STATIC
        ${BREAKPAD_COMMON_SRC}
        ${BREAKPAD_ASM_SOURCE}
        )
target_link_libraries(
        breakpad
        log)




