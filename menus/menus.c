#define _CRT_SECURE_NO_WARNINGS
#include "menus.h"
#include <stdio.h>
#include <stdlib.h>

void clear_screen() { system("cls"); }

void show_main_menu() {
	clear_screen();
	printf("----------------------------------------\n");
	printf("            MENIU PRINCIPAL\n");
	printf("----------------------------------------\n");
	printf("[1] Gestionare sali\n");
	printf("[2] Gestionare rezervari\n");
	printf("[x] Iesire\n");
	printf("----------------------------------------\n");
	printf("Alegeti optiunea: ");
}

void show_room_management_menu() {
	clear_screen();
	printf("----------------------------------------\n");
	printf("            GESTIONARE SALI\n");
	printf("----------------------------------------\n");
	printf("[1] Adaugare sala\n");
	printf("[2] Stergere sala\n");
	printf("[3] Afiseaza toate salile\n");
	printf("[4] Cauta sala\n");
	printf("[x] Inapoi\n");
	printf("----------------------------------------\n");
	printf("Alegeti optiunea: ");
}

void show_reservation_management_menu() {
	clear_screen();
	printf("----------------------------------------\n");
	printf("           GESTIONARE REZERVARI\n");
	printf("----------------------------------------\n");
	printf("[1] Rezervare sala\n");
	printf("[2] Afiseaza toate rezervarile\n");
	printf("[3] Anulare Rezervare\n");
	printf("[x] Inapoi\n");
	printf("----------------------------------------\n");
	printf("Alegeti optiunea: ");
}

void show_add_room_menu() {
	clear_screen();
	printf("----------------------------------------\n");
	printf("             ADAUGARE SALA\n");
	printf("----------------------------------------\n");
	printf("Introduceti datele salii: <nume> <capacitate> <disponibilitate>\n");
	printf("[x] Inapoi\n");
	printf("----------------------------------------\n");
	printf("Alegeti optiunea: ");
}

void show_delete_room_menu() {
	clear_screen();
	printf("----------------------------------------\n");
	printf("             STERGERE SALA\n");
	printf("----------------------------------------\n");
	printf("Introduceti ID-ul salii de sters: <id>\n");
	printf("[x] Inapoi\n");
	printf("----------------------------------------\n");
	printf("Alegeti optiunea: ");
}

void show_search_room_menu() {
	clear_screen();
	printf("----------------------------------------\n");
	printf("             CAUTARE SALA\n");
	printf("----------------------------------------\n");
	printf("[1] Dupa nume\n");
	printf("[2] Dupa capacitate\n");
	printf("[3] Dupa disponibilitate\n");
	printf("[x] Inapoi\n");
	printf("----------------------------------------\n");
	printf("Alegeti optiunea: ");
}

void show_search_room_by_name_menu() {
	clear_screen();
	printf("----------------------------------------\n");
	printf("          CAUTARE SALA DUPA NUME\n");
	printf("----------------------------------------\n");
	printf("[x] Inapoi\n");
	printf("----------------------------------------\n");
	printf("Alegeti optiunea: ");
}

void show_search_room_by_capacity_menu() {
	clear_screen();
	printf("----------------------------------------\n");
	printf("     CAUTARE SALA DUPA CAPACITATE\n");
	printf("----------------------------------------\n");
	printf("[x] Inapoi\n");
	printf("----------------------------------------\n");
	printf("Alegeti optiunea: ");
}

void show_search_room_by_availability_menu() {
	clear_screen();
	printf("----------------------------------------\n");
	printf("  CAUTARE SALA DUPA DISPONIBILITATE\n");
	printf("----------------------------------------\n");
	printf("[x] Inapoi\n");
	printf("----------------------------------------\n");
	printf("Alegeti optiunea: ");
}

void show_reserve_room_menu() {
	clear_screen();
	printf("----------------------------------------\n");
	printf("            REZERVARE SALA\n");
	printf("----------------------------------------\n");
	printf("Introduceti datele rezervarii: <ora> <ziua> <data>\n");
	printf("[x] Inapoi\n");
	printf("----------------------------------------\n");
	printf("Alegeti optiunea: ");
}

void show_cancel_reservation_menu() {
	clear_screen();
	printf("----------------------------------------\n");
	printf("          ANULARE REZERVARE\n");
	printf("----------------------------------------\n");
	printf("Introduceti ID-ul rezervarii de anulat: <id>\n");
	printf("[x] Inapoi\n");
	printf("----------------------------------------\n");
	printf("Alegeti optiunea: ");
}

void show_invalid_option() {
	printf("Optiune invalida!\n");
	printf("\nApasati ENTER pentru a continua...");
	while (getchar() != '\n');
}

void read_option_and_show_menu(char *option, void (*fn)(void)) {
	fn();
	scanf("%c", option);
	char next = getchar();
	if (next != '\n') {
		while(getchar() != '\n');
		*option = 0;
	}
}

void show_all_rooms() {
	printf("Functionalitatea nu este implementata...");
}

void show_all_reservations() {
	printf("Functionalitatea nu este implementata...");
}

void pause_and_continue() {
	printf("\nApasati ENTER pentru a continua...");
	while (getchar() != '\n');
}