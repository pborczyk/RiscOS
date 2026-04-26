# set up cross compiling
set(CMAKE_SYSTEM_NAME	  Generic)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

set(TOOLCHAIN_PREFIX    aarch64-none-elf-)
set(TOOLCHAIN_DIRECTORY /home/howorang/tools/arm-gnu-toolchain-15.2.rel1-x86_64-aarch64-none-elf/bin/)

set(CMAKE_C_COMPILER    "${TOOLCHAIN_DIRECTORY}${TOOLCHAIN_PREFIX}gcc")
set(CMAKE_CXX_COMPILER	"${TOOLCHAIN_DIRECTORY}${TOOLCHAIN_PREFIX}g++")
set(CMAKE_ASM_COMPILER	"${TOOLCHAIN_DIRECTORY}${TOOLCHAIN_PREFIX}as")
set(CMAKE_LINKER        "${TOOLCHAIN_DIRECTORY}${TOOLCHAIN_PREFIX}ld")
set(CMAKE_OBJCOPY       "${TOOLCHAIN_DIRECTORY}${TOOLCHAIN_PREFIX}objcopy")

set(CROSSCOMPILING_EMULATOR qemu-system-aarch64)

# search headers and libraries in the target environment
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_INCLUDE_PATH /home/howorang/tools/arm-gnu-toolchain-15.2.rel1-x86_64-aarch64-none-elf/include)