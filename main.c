#define _CRT_SECURE_NO_WARNINGS
#include "menus/menus.h"
#include <stdio.h>

int main(void) {
	char option;
	MenuState current_menu = MAIN_MENU;

	while (current_menu != EXIT_PROGRAM) {
		switch (current_menu) {
		case MAIN_MENU:
			read_option_and_show_menu(&option, show_main_menu);
			switch (option) {
				case '1': current_menu = ROOM_MANAGEMENT_MENU; break;
				case '2': current_menu = RESERVATION_MANAGEMENT_MENU; break;
				case 'x': 
					current_menu = EXIT_PROGRAM; 
					printf("Programul s-a terminat!"); 
					break;
				default: show_invalid_option(); break;
			}
			break;
		case ROOM_MANAGEMENT_MENU:
			read_option_and_show_menu(&option, show_room_management_menu);
			switch (option) {
				case '1': current_menu = ADD_ROOM_MENU; break;
				case '2': current_menu = DELETE_ROOM_MENU; break;
				case '3':
					show_all_rooms();
					pause_and_continue();
					break;
				case '4': current_menu = SEARCH_ROOM_MENU; break;
				case 'x': current_menu = MAIN_MENU; break;
				default: show_invalid_option(); break;
			}
			break;
		case RESERVATION_MANAGEMENT_MENU:
			read_option_and_show_menu(&option, show_reservation_management_menu);
			switch (option) {
				case '1': current_menu = RESERVE_ROOM_MENU; break;
				case '2':
					show_all_reservations();
					pause_and_continue();
					break;
				case '3': current_menu = CANCEL_RESERVATION_MENU; break;
				case 'x': current_menu = MAIN_MENU; break;
				default: show_invalid_option(); break;
			}
			break;
		case ADD_ROOM_MENU:
			read_option_and_show_menu(&option, show_add_room_menu);
			switch (option) {
				case 'x': current_menu = ROOM_MANAGEMENT_MENU; break;
				default: show_invalid_option(); break;
			}
			break;
		case DELETE_ROOM_MENU:
			read_option_and_show_menu(&option, show_delete_room_menu);
			switch (option) {
				case 'x': current_menu = ROOM_MANAGEMENT_MENU; break;
				default: show_invalid_option(); break;
			}
			break;
		case SEARCH_ROOM_MENU:
			read_option_and_show_menu(&option, show_search_room_menu);
			switch (option) {
				case '1': current_menu = SEARCH_ROOM_BY_NAME_MENU; break;
				case '2': current_menu = SEARCH_ROOM_BY_CAPACITY_MENU; break;
				case '3': current_menu = SEARCH_ROOM_BY_AVAILABILITY_MENU; break;
				case 'x': current_menu = ROOM_MANAGEMENT_MENU; break;
				default: show_invalid_option(); break;
			}
			break;
		case SEARCH_ROOM_BY_NAME_MENU:
			read_option_and_show_menu(&option, show_search_room_by_name_menu);
			switch (option) {
				case 'x': current_menu = SEARCH_ROOM_MENU; break;
				default: show_invalid_option(); break;
			}
			break;
		case SEARCH_ROOM_BY_CAPACITY_MENU:
			read_option_and_show_menu(&option, show_search_room_by_capacity_menu);
			switch (option) {
				case 'x': current_menu = SEARCH_ROOM_MENU; break;
				default: show_invalid_option(); break;
			}
			break;
		case SEARCH_ROOM_BY_AVAILABILITY_MENU:
			read_option_and_show_menu(&option, show_search_room_by_availability_menu);
			switch (option) {
				case 'x': current_menu = SEARCH_ROOM_MENU; break;
				default: show_invalid_option(); break;
			}
			break;
		case RESERVE_ROOM_MENU:
			read_option_and_show_menu(&option, show_reserve_room_menu);
			switch (option) {
				case 'x': current_menu = RESERVATION_MANAGEMENT_MENU; break;
				default: show_invalid_option(); break;
			}
			break;
		case CANCEL_RESERVATION_MENU:
			read_option_and_show_menu(&option, show_cancel_reservation_menu);
			switch (option) {
				case 'x': current_menu = RESERVATION_MANAGEMENT_MENU; break;
				default: show_invalid_option(); break;
			}
			break;
		case EXIT_PROGRAM:
			{}
		}
	}

	return 0;
}