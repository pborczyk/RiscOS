set(CMAKE_TOOLCHAIN_FILE ./aarch64-elf.cmake)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# otherwise cmake built in compiler test will fail on cross compiler
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
set(CMAKE_VERBOSE_MAKEFILE ON)
cmake_minimum_required(VERSION 3.19)
project(RiscOS 	VERSION 0.1
			   	DESCRIPTION "Big OS"
				LANGUAGES C ASM)

include_directories(${CMAKE_INCLUDE_PATH})

add_library(EntryPoint		OBJECT entry.asm)
# this disables float support across the codebase, we have to do it because it is broken before kernel inits the FPU see: https://forum.osdev.org/viewtopic.php?t=56542
add_compile_options(-ffreestanding -c -g -nostdlib -mstrict-align -mgeneral-regs-only)
add_library(MemoryModule	OBJECT memory.h memory.c)
add_library(StdLibModule	OBJECT stdlib.h stdlib.c string.h string.c)

set(LINKER_SCRIPT "${CMAKE_SOURCE_DIR}/linker.ld")
add_link_options(-T "${LINKER_SCRIPT}" -nostdlib)
add_executable(Kernel kernel.c)
set_target_properties(Kernel PROPERTIES LINK_DEPENDS "${LINKER_SCRIPT}" OUTPUT_NAME "Kernel.elf")
target_link_libraries(Kernel EntryPoint MemoryModule StdLibModule)


