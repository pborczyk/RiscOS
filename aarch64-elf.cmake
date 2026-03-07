# set up cross compiling
set(CMAKE_SYSTEM_NAME	  Generic)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

set(TOOLCHAIN_PREFIX    aarch64-elf-)
set(CMAKE_C_COMPILER    "${TOOLCHAIN_PREFIX}gcc")
set(CMAKE_CXX_COMPILER	"${TOOLCHAIN_PREFIX}g++")
set(CMAKE_ASM_COMPILER	"${TOOLCHAIN_PREFIX}as")
set(CMAKE_LINKER        "${TOOLCHAIN_PREFIX}ld")
set(CMAKE_OBJCOPY       "${TOOLCHAIN_PREFIX}objcopy")

set(CROSSCOMPILING_EMULATOR qemu-system-aarch64)


# where is the target environment located
set(CMAKE_FIND_ROOT_PATH  /Users/howorang/Projects/RiscOSEnv/)

# search headers and libraries in the target environment
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_INCLUDE_PATH /opt/homebrew/Cellar/aarch64-elf-gcc/15.2.0/lib/gcc/aarch64-elf/15.2.0/include)