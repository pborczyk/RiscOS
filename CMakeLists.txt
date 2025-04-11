cmake_minimum_required(VERSION 3.19)
project(RiscOS 	VERSION 0.1
			   	DESCRIPTION "RiscV OS"
				LANGUAGES C ASM)
# where is the target environment located
set(CMAKE_FIND_ROOT_PATH  ../RiscOSEnv)
# adjust the default behavior of the FIND_XXX() commands:
# search programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# search headers and libraries in the target environment
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

add_library(EntryPoint		OBJECT entry.asm)
add_library(MemoryModule	OBJECT memory.h memory.c)
add_library(StdLibModule	OBJECT stdlib.h stdlib.c string.h string.c)

set(LINKER_SCRIPT "${CMAKE_SOURCE_DIR}/linker.ld")
add_link_options(-T "${LINKER_SCRIPT}" -lgcc -nostdlib)
add_executable(Kernel kernel.c)
set_target_properties(Kernel PROPERTIES LINK_DEPENDS "${LINKER_SCRIPT}")
target_link_libraries(Kernel EntryPoint MemoryModule StdLibModule)
add_custom_command(TARGET Kernel 
                   POST_BUILD
                   COMMAND "${CMAKE_OBJCOPY}"
                   ARGS -O binary "$<TARGET_FILE:Kernel>" "$<TARGET_FILE:Kernel>.bin")


