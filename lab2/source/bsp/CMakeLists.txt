# Add sources for directory
target_sources( ${executable_name}.elf
                PRIVATE
                    led.c
                    systick.c
)