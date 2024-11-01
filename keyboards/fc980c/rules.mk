# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes	# Mouse keys
EXTRAKEY_ENABLE = yes	# Audio control and System control
CONSOLE_ENABLE = yes	# Console for debug
COMMAND_ENABLE = yes    # Commands for debug and configuration
NKRO_ENABLE = no           # Enable N-Key Rollover
TAP_DANCE_ENABLE = yes


# Optimize size but this may cause error "relocation truncated to fit"
#EXTRALDFLAGS = -Wl,--relax

I2C_DRIVER_REQUIRED = yes

CUSTOM_MATRIX = yes
SRC += matrix.c ad5258.c
