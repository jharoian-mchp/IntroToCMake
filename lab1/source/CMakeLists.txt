cmake_minimum_required(VERSION 3.19)

set(executable_name HelloWorld)         # Name used for target and .elf and .hex files in build folder
set(microcontroller ATSAME54P20A)       # Target microcontroller - needed for xc32

# Project name is independent of the target name
# Semantic version number updated here 
project(    lab1-helloworld
            VERSION 0.1.0
            LANGUAGES C
)

# List of .c files
add_executable( ${executable_name}.elf
                main.c
)

set(home_directory $ENV{HOME} $ENV{userprofile})

# Modify the paths below for DFP and CMSIS include
# Pack updates appear in home_directory and original files appear in MPLAB X install directory
set(microchip_dfp_path "/Program Files/Microchip/MPLABX/v6.05/packs/Microchip/SAME54_DFP/3.7.122" )
set(cmsis_include_path "${home_directory}/.mchp_packs/ARM/CMSIS/5.8.0/CMSIS/Core/Include" )

# Include directories - need at least DFP and CMSIS directories
target_include_directories( ${executable_name}.elf 
                            PRIVATE ${microchip_dfp_path}
                            PRIVATE ${cmsis_include_path} 
)

# Set processor and other options for build
target_compile_options(     ${executable_name}.elf 
                            PUBLIC "-mprocessor=${microcontroller}" 
)

target_link_options(       ${executable_name}.elf 
                            PUBLIC "-mprocessor=${microcontroller}" 
                            PUBLIC "-Wl,-Map=${executable_name}.map" 
                            PUBLIC "-Wl,--memorysummary,memoryfile.xml"
)

# Set configuration
target_compile_definitions( ${executable_name}.elf 
                            PUBLIC "XPRJ_default=default"
)

# Create hex file from target
add_custom_command( TARGET ${executable_name}.elf 
                    POST_BUILD COMMAND xc32-bin2hex ${executable_name}.elf 
)

# Debug statements
include(CmakePrintHelpers)
#cmake_print_properties( TARGETS HelloWorld.elf PROPERTIES COMPILE_OPTIONS INCLUDE_DIRECTORIES COMPILE_DEFINITIONS SOURCES LINK_OPTIONS)
#cmake_print_variables( home_directory microchip_dfp_path cmsis_include_path)
