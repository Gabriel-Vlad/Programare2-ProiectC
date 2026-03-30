CC = gcc
FILES = main.c menus/menus.c config/config.c
OUT = main

all:
		$(CC) $(FILES) -o $(OUT)