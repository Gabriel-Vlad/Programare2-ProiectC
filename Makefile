CC = gcc
FILES = main.c menus/menus.c menus/input.c config/sali/sali.c config/rezervari/rezervari.c database/database.c
OUT = main

all:
		$(CC) $(FILES) -o $(OUT)