CC = gcc
CFLAGS = -I.
FILES = main.c menus/menus.c menus/display/display.c menus/input/halls/halls_input.c menus/input/reservations/reservations_input.c menus/input/utils/utils.c models/halls/halls.c models/reservations/reservations.c database/database.c
OUT = main

all:
	$(CC) $(CFLAGS) $(FILES) -o $(OUT)