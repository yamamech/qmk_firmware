SRC += yamamech.c

ifeq ($(strip $(YAMAMECH_HHKB)), yes)
	SRC += hhkb/hhkb.c
	OPT_DEFS += -DHHKB_ENABLE
endif
