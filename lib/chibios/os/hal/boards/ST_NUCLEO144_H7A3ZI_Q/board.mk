# List of all the board related files.
BOARDSRC = $(CHIBIOS)/os/hal/boards/ST_NUCLEO144_H7A3ZI_Q/board.c

# Required include directories
BOARDINC = $(CHIBIOS)/os/hal/boards/ST_NUCLEO144_H7A3ZI_Q

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)
