cmake_minimum_required(VERSION 3.19)

set(executable HelloWorld.elf)
set(microcontroller ATSAME54P20A)

set(microchip_dfp_path "/Program Files/Microchip/MPLABX/v6.05/packs/Microchip/SAME54_DFP/3.7.122" )
set(cmsis_include_path "/Users/C14029/.mchp_packs/ARM/CMSIS/5.8.0/CMSIS/Core/Include" )

set(mapfile HelloWorld.map)

set(home_directory $ENV{HOME} $ENV{userprofile})

project(    HelloWorld-prj
            VERSION 0.1.0
            LANGUAGES C
)

# File list of .c files
add_executable( HelloWorld.elf
                main.c
)

# Include directories - need at least DFP and CMSIS directories
target_include_directories( HelloWorld.elf 
                            PRIVATE ${microchip_dfp_path}
                            PRIVATE ${cmsis_include_path} 
)

# Set processor and other options for build
target_compile_options(     HelloWorld.elf 
                            PUBLIC "-mprocessor=${microcontroller}" 
)

target_link_options(        HelloWorld.elf 
                            PUBLIC "-mprocessor=${microcontroller}" 
                            PUBLIC "-Wl,-Map=${mapfile}" 
                            PUBLIC "-Wl,--memorysummary,memoryfile.xml"
)

# Set configuration
target_compile_definitions( HelloWorld.elf 
                            PUBLIC "XPRJ_default=default"
)

# Create hex file from target
add_custom_command( TARGET HelloWorld.elf 
                    POST_BUILD COMMAND xc32-bin2hex HelloWorld.elf 
)

# Debug statements
include(CmakePrintHelpers)
#cmake_print_properties( TARGETS HelloWorld.elf PROPERTIES COMPILE_OPTIONS INCLUDE_DIRECTORIES COMPILE_DEFINITIONS SOURCES LINK_OPTIONS)
#cmake_print_variables( home_directory microchip_dfp_path cmsis_include_path)
