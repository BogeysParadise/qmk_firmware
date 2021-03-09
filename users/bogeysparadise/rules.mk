SRC += bogeysparadise.c \
       process_records.c

# 	   combos.c

ifneq ($(PLATFORM),CHIBIOS)
    LTO_ENABLE        = yes
endif

GRAVE_ESC_ENABLE      = yes
#TAP_DANCE_ENABLE 	  = no       # Need to add code to enable.
#COMBO_ENABLE 		  = yes      # Enable Combos

#ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
#    SRC += tap_dances.c
#endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
    SRC += tap_dances.c
endif

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
    SRC += rgb_stuff.c
    ifeq ($(strip $(RGBLIGHT_TWINKLE)), yes)
        OPT_DEFS += -DRGBLIGHT_TWINKLE
    endif
    ifeq ($(strip $(RGBLIGHT_NOEEPROM)), yes)
        OPT_DEFS += -DRGBLIGHT_NOEEPROM
    endif
    ifeq ($(strip $(RGBLIGHT_STARTUP_ANIMATION)), yes)
        OPT_DEFS += -DRGBLIGHT_STARTUP_ANIMATION
    endif
endif

RGB_MATRIX_ENABLE ?= no
ifneq ($(strip $(RGB_MATRIX_ENABLE)), no)
    SRC += rgb_matrix_stuff.c
endif

ifeq ($(strip $(MAKE_BOOTLOADER)), yes)
    OPT_DEFS += -DMAKE_BOOTLOADER
endif

# At least until build.mk or the like drops, this is here to prevent
# VUSB boards from enabling NKRO, as they do not support it. Ideally
# this should be handled per keyboard, but until that happens ...
ifeq ($(strip $(PROTOCOL)), VUSB)
    NKRO_ENABLE       = no
endif

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
    SRC += oled_stuff.c
endif

#ifeq ($(strip $(SPLIT_KEYBOARD)), yes)
#    ifneq ($(strip $(SPLIT_TRANSPORT)), custom)
#        SPLIT_TRANSPORT = custom
#        QUANTUM_LIB_SRC += drashna_transport.c
#        OPT_DEFS += -DDRASHNA_CUSTOM_TRANSPORT
        # Unused functions are pruned away, which is why we can add multiple drivers here without bloat.
#        ifeq ($(PLATFORM),AVR)
#            ifneq ($(NO_I2C),yes)
#                QUANTUM_LIB_SRC += i2c_master.c \
#                                   i2c_slave.c
#            endif
#        endif

#        SERIAL_DRIVER ?= bitbang
#        OPT_DEFS += -DSERIAL_DRIVER_$(strip $(shell echo $(SERIAL_DRIVER) | tr '[:lower:]' '[:upper:]'))
#        ifeq ($(strip $(SERIAL_DRIVER)), bitbang)
#            QUANTUM_LIB_SRC += serial.c
#        else
#            QUANTUM_LIB_SRC += serial_$(strip $(SERIAL_DRIVER)).c
#        endif
#    endif
#endif
