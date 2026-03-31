CC = gcc
FILES = main.c menus/menus.c menus/input/halls/halls_input.c menus/input/rezervations/rezervations_input.c menus/input/utils/utils.c models/halls/halls.c models/rezervations/rezervations.c database/database.c
OUT = main

all:
	$(CC) $(FILES) -o $(OUT)