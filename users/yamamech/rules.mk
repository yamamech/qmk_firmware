SRC += yamamech.c

ifeq ($(strip $(YAMAMECH_HHKB)), yes)
	SRC += hhkb/hhkb.c
	OPT_DEFS += -DHHKB_ENABLE
endif

ifeq ($(strip $(YAMAMECH_SECRETS)), yes)
	SRC += secrets/secrets.c
	OPT_DEFS += -DSECRETS_ENABLE
endif

ifeq ($(strip $(YAMAMECH_RGBLIGHT_ENABLE)), yes)
	SRC += lighting/lighting.c
endif
