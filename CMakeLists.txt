cmake_minimum_required(VERSION 3.22)
project(argvdump C ASM)
set(CMAKE_C_STANDARD_REQUIRED 11)

add_executable(argvdump argvdump.c mysyscall.S)
add_executable(noargs noargs.c)

target_compile_options(argvdump PRIVATE -ffreestanding -O -g)
target_link_options(argvdump PRIVATE -Wl,-e,start
    -nostartfiles -nodefaultlibs -static)
