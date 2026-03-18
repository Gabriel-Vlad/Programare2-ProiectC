#define _CRT_SECURE_NO_WARNINGS
#include "menus/menus.h"
#include <stdio.h>

void show_all_rooms() {}
void show_all_reservations() {}

int main(void) {
	char option;
	MenuState current_menu = MAIN_MENU;
	while (current_menu != EXIT_PROGRAM) {
		switch (current_menu) {
		case MAIN_MENU:
			show_main_menu();
			scanf("%c", &option);
			getchar();
			switch (option) {
			case '1':
				current_menu = ROOM_MANAGEMENT_MENU;
				break;
			case '2':
				current_menu = RESERVATION_MANAGEMENT_MENU;
				break;
			case 'x':
				current_menu = EXIT_PROGRAM;
				printf("Programul s-a terminat!\n");
				break;
			default:
				printf("Optiune invalida!\n");
				break;
			}
			break;
		case ROOM_MANAGEMENT_MENU:
			show_room_management_menu();
			scanf("%c", &option);
			getchar();
			switch (option) {
			case '1':
				current_menu = ADD_ROOM_MENU;
				break;
			case '2':
				current_menu = DELETE_ROOM_MENU;
				break;
			case '3':
				show_all_rooms();
				break;
			case '4':
				current_menu = SEARCH_ROOM_MENU;
				break;
			case 'x':
				current_menu = MAIN_MENU;
				break;
			default:
				printf("Optiune invalida!\n");
				break;
			}
			break;
		case RESERVATION_MANAGEMENT_MENU:
			show_reservation_management_menu();
			scanf("%c", &option);
			getchar();
			switch (option) {
			case '1':
				current_menu = RESERVE_ROOM_MENU;
				break;
			case '2':
				show_all_reservations();
				break;
			case '3':
				current_menu = CANCEL_RESERVATION_MENU;
				break;
			case 'x':
				current_menu = MAIN_MENU;
				break;
			default:
				printf("Optiune invalida!\n");
				break;
			}
			break;
		case ADD_ROOM_MENU:
			show_add_room_menu();
			scanf("%c", &option);
			getchar();
			switch (option) {
			case 'x':
				current_menu = ROOM_MANAGEMENT_MENU;
				break;
			default:
				printf("Optiune invalida!\n");
				break;
			}
			break;
		case DELETE_ROOM_MENU:
			show_delete_room_menu();
			scanf("%c", &option);
			getchar();
			switch (option) {
			case 'x':
				current_menu = ROOM_MANAGEMENT_MENU;
				break;
			default:
				printf("Optiune invalida!\n");
				break;
			}
			break;
		case SEARCH_ROOM_MENU:
			show_search_room_menu();
			scanf("%c", &option);
			getchar();
			switch (option) {
			case '1':
				current_menu = SEARCH_ROOM_BY_NAME_MENU;
				break;
			case '2':
				current_menu = SEARCH_ROOM_BY_CAPACITY_MENU;
				break;
			case '3':
				current_menu = SEARCH_ROOM_BY_AVAILABILITY_MENU;
				break;
			case 'x':
				current_menu = ROOM_MANAGEMENT_MENU;
				break;
			default:
				printf("Optiune invalida!\n");
				break;
			}
			break;
		case SEARCH_ROOM_BY_NAME_MENU:
			show_search_room_by_name_menu();
			scanf("%c", &option);
			getchar();
			switch (option) {
			case 'x':
				current_menu = SEARCH_ROOM_MENU;
				break;
			default:
				printf("Optiune invalida!\n");
				break;
			}
			break;
		case SEARCH_ROOM_BY_CAPACITY_MENU:
			show_search_room_by_capacity_menu();
			scanf("%c", &option);
			getchar();
			switch (option) {
			case 'x':
				current_menu = SEARCH_ROOM_MENU;
				break;
			default:
				printf("Optiune invalida!\n");
				break;
			}
			break;
		case SEARCH_ROOM_BY_AVAILABILITY_MENU:
			show_search_room_by_availability_menu();
			scanf("%c", &option);
			getchar();
			switch (option) {
			case 'x':
				current_menu = SEARCH_ROOM_MENU;
				break;
			default:
				printf("Optiune invalida!\n");
				break;
			}
			break;
		case RESERVE_ROOM_MENU:
			show_reserve_room_menu();
			scanf("%c", &option);
			getchar();
			switch (option) {
			case 'x':
				current_menu = RESERVATION_MANAGEMENT_MENU;
				break;
			default:
				printf("Optiune invalida!\n");
				break;
			}
			break;
		case CANCEL_RESERVATION_MENU:
			show_cancel_reservation_menu();
			scanf("%c", &option);
			getchar();
			switch (option) {
			case 'x':
				current_menu = RESERVATION_MANAGEMENT_MENU;
				break;
			default:
				printf("Optiune invalida!\n");
				break;
			}
			break;
		}
	}

	return 0;
}