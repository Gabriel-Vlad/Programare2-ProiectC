#define _CRT_SECURE_NO_WARNINGS
#include "menus/menus.h"
#include "menus/display/display.h"
#include "menus/input/utils/utils.h"
#include "menus/colors.h"
#include <stdio.h>
#include <stdlib.h>

void clear_screen() { system("cls"); }

// W=42: border 42 dashes, option pad=37, info pad=41
void show_main_menu() {
	clear_screen();
	printf(COLOR_BORDER "|------------------------------------------|" RESET "\n");
	printf(COLOR_BORDER "|" COLOR_TITLE "             MENIU PRINCIPAL              " COLOR_BORDER "|" RESET "\n");
	printf(COLOR_BORDER "|------------------------------------------|" RESET "\n");
	printf(COLOR_BORDER "|" COLOR_KEY " [1]" COLOR_TEXT " %-37s" COLOR_BORDER "|" RESET "\n", "Gestionare sali");
	printf(COLOR_BORDER "|" COLOR_KEY " [2]" COLOR_TEXT " %-37s" COLOR_BORDER "|" RESET "\n", "Gestionare rezervari");
	printf(COLOR_BORDER "|" COLOR_DANGER " [x] %-37s" COLOR_BORDER "|" RESET "\n", "Iesire");
	printf(COLOR_BORDER "|------------------------------------------|" RESET "\n");
	printf("\n" COLOR_PROMPT "Alege optiunea: " RESET);
}

// W=42
void show_room_management_menu() {
	clear_screen();
	printf(COLOR_BORDER "|------------------------------------------|" RESET "\n");
	printf(COLOR_BORDER "|" COLOR_TITLE "             GESTIONARE SALI              " COLOR_BORDER "|" RESET "\n");
	printf(COLOR_BORDER "|------------------------------------------|" RESET "\n");
	printf(COLOR_BORDER "|" COLOR_KEY " [1]" COLOR_TEXT " %-37s" COLOR_BORDER "|" RESET "\n", "Adaugare sala");
	printf(COLOR_BORDER "|" COLOR_KEY " [2]" COLOR_TEXT " %-37s" COLOR_BORDER "|" RESET "\n", "Stergere sala");
	printf(COLOR_BORDER "|" COLOR_KEY " [3]" COLOR_TEXT " %-37s" COLOR_BORDER "|" RESET "\n", "Afiseaza toate salile");
	printf(COLOR_BORDER "|" COLOR_KEY " [4]" COLOR_TEXT " %-37s" COLOR_BORDER "|" RESET "\n", "Cauta sala");
	printf(COLOR_BORDER "|" COLOR_DANGER " [x] %-37s" COLOR_BORDER "|" RESET "\n", "Inapoi");
	printf(COLOR_BORDER "|------------------------------------------|" RESET "\n");
	printf("\n" COLOR_PROMPT "Alege optiunea: " RESET);
}

// W=42
void show_reservation_management_menu() {
	clear_screen();
	printf(COLOR_BORDER "|------------------------------------------|" RESET "\n");
	printf(COLOR_BORDER "|" COLOR_TITLE "           GESTIONARE REZERVARI           " COLOR_BORDER "|" RESET "\n");
	printf(COLOR_BORDER "|------------------------------------------|" RESET "\n");
	printf(COLOR_BORDER "|" COLOR_KEY " [1]" COLOR_TEXT " %-37s" COLOR_BORDER "|" RESET "\n", "Rezervare sala");
	printf(COLOR_BORDER "|" COLOR_KEY " [2]" COLOR_TEXT " %-37s" COLOR_BORDER "|" RESET "\n", "Afiseaza toate rezervarile");
	printf(COLOR_BORDER "|" COLOR_KEY " [3]" COLOR_TEXT " %-37s" COLOR_BORDER "|" RESET "\n", "Anulare Rezervare");
	printf(COLOR_BORDER "|" COLOR_DANGER " [x] %-37s" COLOR_BORDER "|" RESET "\n", "Inapoi");
	printf(COLOR_BORDER "|------------------------------------------|" RESET "\n");
	printf("\n" COLOR_PROMPT "Alege optiunea: " RESET);
}

// W=70
void show_add_room_menu() {
	clear_screen();
	printf(COLOR_BORDER "|----------------------------------------------------------------------" COLOR_BORDER "|" RESET "\n");
	printf(COLOR_BORDER "|" COLOR_TITLE "                            ADAUGARE SALA                             " COLOR_BORDER "|" RESET "\n");
	printf(COLOR_BORDER "|----------------------------------------------------------------------" COLOR_BORDER "|" RESET "\n");
	printf(COLOR_BORDER "|" COLOR_INFO " %-69s" COLOR_BORDER "|" RESET "\n", "Introduceti datele salii: <nume> <capacitate> <disponibilitate>(Y/N)");
	printf(COLOR_BORDER "|" COLOR_TEXT " %-69s" COLOR_BORDER "|" RESET "\n", "Exemplu: Amfiteatru 200 Y");
	printf(COLOR_BORDER "|" COLOR_DANGER " [x] %-65s" COLOR_BORDER "|" RESET "\n", "Inapoi");
	printf(COLOR_BORDER "|----------------------------------------------------------------------" COLOR_BORDER "|" RESET "\n");
	printf("\n" COLOR_PROMPT "Alege optiunea: " RESET);
}

// W=42
void show_delete_room_menu() {
	clear_screen();
	printf(COLOR_BORDER "|------------------------------------------|" RESET "\n");
	printf(COLOR_BORDER "|" COLOR_TITLE "              STERGERE SALA               " COLOR_BORDER "|" RESET "\n");
	printf(COLOR_BORDER "|------------------------------------------|" RESET "\n");
	printf(COLOR_BORDER "|" COLOR_INFO " %-41s" COLOR_BORDER "|" RESET "\n", "Introduceti ID-ul salii de sters: <ID>");
	printf(COLOR_BORDER "|" COLOR_TEXT " %-41s" COLOR_BORDER "|" RESET "\n", "Exemplu: 3");
	printf(COLOR_BORDER "|" COLOR_DANGER " [x] %-37s" COLOR_BORDER "|" RESET "\n", "Inapoi");
	printf(COLOR_BORDER "|------------------------------------------|" RESET "\n");
	printf("\n" COLOR_PROMPT "Alege optiunea: " RESET);
}

// W=42
void show_search_room_menu() {
	clear_screen();
	printf(COLOR_BORDER "|------------------------------------------|" RESET "\n");
	printf(COLOR_BORDER "|" COLOR_TITLE "               CAUTARE SALA               " COLOR_BORDER "|" RESET "\n");
	printf(COLOR_BORDER "|------------------------------------------|" RESET "\n");
	printf(COLOR_BORDER "|" COLOR_KEY " [1]" COLOR_TEXT " %-37s" COLOR_BORDER "|" RESET "\n", "Dupa nume");
	printf(COLOR_BORDER "|" COLOR_KEY " [2]" COLOR_TEXT " %-37s" COLOR_BORDER "|" RESET "\n", "Dupa capacitate");
	printf(COLOR_BORDER "|" COLOR_KEY " [3]" COLOR_TEXT " %-37s" COLOR_BORDER "|" RESET "\n", "Dupa disponibilitate");
	printf(COLOR_BORDER "|" COLOR_DANGER " [x] %-37s" COLOR_BORDER "|" RESET "\n", "Inapoi");
	printf(COLOR_BORDER "|------------------------------------------|" RESET "\n");
	printf("\n" COLOR_PROMPT "Alege optiunea: " RESET);
}

// W=42
void show_search_room_by_name_menu() {
	clear_screen();
	printf(COLOR_BORDER "|------------------------------------------|" RESET "\n");
	printf(COLOR_BORDER "|" COLOR_TITLE "          CAUTARE SALA DUPA NUME          " COLOR_BORDER "|" RESET "\n");
	printf(COLOR_BORDER "|------------------------------------------|" RESET "\n");
	printf(COLOR_BORDER "|" COLOR_INFO " %-41s" COLOR_BORDER "|" RESET "\n", "Introduceti numele salii: <nume_sala>");
	printf(COLOR_BORDER "|" COLOR_DANGER " [x] %-37s" COLOR_BORDER "|" RESET "\n", "Inapoi");
	printf(COLOR_BORDER "|------------------------------------------|" RESET "\n");
	printf("\n" COLOR_PROMPT "Alege optiunea: " RESET);
}

// W=45
void show_search_room_by_capacity_menu() {
	clear_screen();
	printf(COLOR_BORDER "|---------------------------------------------|" RESET "\n");
	printf(COLOR_BORDER "|" COLOR_TITLE "        CAUTARE SALA DUPA CAPACITATE         " COLOR_BORDER "|" RESET "\n");
	printf(COLOR_BORDER "|---------------------------------------------|" RESET "\n");
	printf(COLOR_BORDER "|" COLOR_INFO " %-44s" COLOR_BORDER "|" RESET "\n", "Introduceti capacitatea salii: <capacitate>");
	printf(COLOR_BORDER "|" COLOR_DANGER " [x] %-40s" COLOR_BORDER "|" RESET "\n", "Inapoi");
	printf(COLOR_BORDER "|---------------------------------------------|" RESET "\n");
	printf("\n" COLOR_PROMPT "Alege optiunea: " RESET);
}

// W=60
void show_search_room_by_availability_menu() {
	clear_screen();
	printf(COLOR_BORDER "|------------------------------------------------------------|" RESET "\n");
	printf(COLOR_BORDER "|" COLOR_TITLE "             CAUTARE SALA DUPA DISPONIBILITATE              " COLOR_BORDER "|" RESET "\n");
	printf(COLOR_BORDER "|------------------------------------------------------------|" RESET "\n");
	printf(COLOR_BORDER "|" COLOR_INFO " %-59s" COLOR_BORDER "|" RESET "\n", "Introduceti disponibilitatea salii: <disponibilitate>(Y/N)");
	printf(COLOR_BORDER "|" COLOR_DANGER " [x] %-55s" COLOR_BORDER "|" RESET "\n", "Inapoi");
	printf(COLOR_BORDER "|------------------------------------------------------------|" RESET "\n");
	printf("\n" COLOR_PROMPT "Alege optiunea: " RESET);
}

// W=69
void show_reserve_room_menu() {
	clear_screen();
	printf(COLOR_BORDER "|---------------------------------------------------------------------|" RESET "\n");
	printf(COLOR_BORDER "|" COLOR_TITLE "                           REZERVARE SALA                            " COLOR_BORDER "|" RESET "\n");
	printf(COLOR_BORDER "|---------------------------------------------------------------------|" RESET "\n");
	printf(COLOR_BORDER "|" COLOR_INFO " %-68s" COLOR_BORDER "|" RESET "\n", "Introduceti datele rezervarii: <nume_sala> <ora> <data>(DD/MM/YYYY)");
	printf(COLOR_BORDER "|" COLOR_TEXT " %-68s" COLOR_BORDER "|" RESET "\n", "Exemplu: Amfiteatru 14 25/12/2026");
	printf(COLOR_BORDER "|" COLOR_DANGER " [x] %-64s" COLOR_BORDER "|" RESET "\n", "Inapoi");
	printf(COLOR_BORDER "|---------------------------------------------------------------------|" RESET "\n");
	printf("\n" COLOR_PROMPT "Alege optiunea: " RESET);
}

// W=46
void show_cancel_reservation_menu() {
	clear_screen();
	printf(COLOR_BORDER "|----------------------------------------------|" RESET "\n");
	printf(COLOR_BORDER "|" COLOR_TITLE "              ANULARE REZERVARE               " COLOR_BORDER "|" RESET "\n");
	printf(COLOR_BORDER "|----------------------------------------------|" RESET "\n");
	printf(COLOR_BORDER "|" COLOR_INFO " %-45s" COLOR_BORDER "|" RESET "\n", "Introduceti ID-ul rezervarii de anulat: <ID>");
	printf(COLOR_BORDER "|" COLOR_TEXT " %-45s" COLOR_BORDER "|" RESET "\n", "Exemplu: 2");
	printf(COLOR_BORDER "|" COLOR_DANGER " [x] %-41s" COLOR_BORDER "|" RESET "\n", "Inapoi");
	printf(COLOR_BORDER "|----------------------------------------------|" RESET "\n");
	printf("\n" COLOR_PROMPT "Alege optiunea: " RESET);
}

void show_invalid_option() {
	printf(COLOR_ERROR "\nOptiune invalida!" RESET "\n");
	printf(COLOR_INFO "\nApasa ENTER pentru a continua..." RESET);
	while (getchar() != '\n');
}

char read_option_and_show_menu(void (*fn)(void)) {
	char option;
	fn();
	scanf("%c", &option);
	char next = getchar();
	if (next != '\n') {
		while(getchar() != '\n');
		return 0;
	}
	return option;
}

void pause_and_continue() {
	printf(COLOR_INFO "\nApasa ENTER pentru a continua..." RESET);
	while (getchar() != '\n');
}
