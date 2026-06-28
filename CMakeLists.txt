if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Darwin")
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_LIST_DIR}/aarch64-elf-darwin.cmake")
elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_LIST_DIR}/aarch64-elf-linux.cmake")
else()
    message(FATAL_ERROR "Unsupported host OS: ${CMAKE_HOST_SYSTEM_NAME}")
endif()
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

add_library(LibFdt			OBJECT 	lib/libfdt/fdt_addresses.c
									lib/libfdt/fdt_empty_tree.c
									lib/libfdt/fdt_overlay.c
									lib/libfdt/fdt_ro.c
									lib/libfdt/fdt_rw.c
									lib/libfdt/fdt_strerror.c
									lib/libfdt/fdt_sw.c
									lib/libfdt/fdt_wip.c
									lib/libfdt/fdt.c
									lib/libfdt/fdt.h
									lib/libfdt/libfdt_env.h
									lib/libfdt/libfdt_internal.h
									lib/libfdt/libfdt.h)
# so that the compiler can find the libfdt headers without having to specify relative path in every source file that uses it
target_include_directories(LibFdt PRIVATE lib/libfdt/)


set(LINKER_SCRIPT "${CMAKE_SOURCE_DIR}/linker.ld")
add_link_options(-T "${LINKER_SCRIPT}" -nostdlib)
add_executable(Kernel kernel.c)
set_target_properties(Kernel PROPERTIES LINK_DEPENDS "${LINKER_SCRIPT}" OUTPUT_NAME "Kernel.elf")
target_link_libraries(Kernel EntryPoint MemoryModule StdLibModule LibFdt)

# Strip out kernel.elf to kernel.bin for U-Boot
add_custom_command(TARGET Kernel POST_BUILD
	COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:Kernel> ${CMAKE_BINARY_DIR}/kernel.bin
	COMMENT "Generating kernel.bin for U-Boot"
)


