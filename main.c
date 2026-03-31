#define _CRT_SECURE_NO_WARNINGS
#include "menus/menus.h"
#include "menus/colors.h"
#include "models/rezervations/rezervations.h"
#include "models/halls/halls.h"
#include "menus/input/halls/halls_input.h"
#include "menus/input/rezervations/rezervations_input.h"
#include "database/database.h"
#include <stdio.h>

int main(void) {
	init_database();
	MenuState current_menu = MAIN_MENU;

	while (current_menu != EXIT_PROGRAM) {
		switch (current_menu) {
		case MAIN_MENU:
			switch (read_option_and_show_menu(show_main_menu)) {
				case '1': current_menu = ROOM_MANAGEMENT_MENU; break;
				case '2': current_menu = RESERVATION_MANAGEMENT_MENU; break;
				case 'x': 
					current_menu = EXIT_PROGRAM; 
					printf(COLOR_SUCCESS "\nProgramul s-a terminat!\n" RESET); 
					break;
				default: show_invalid_option(); break;
			}
			break;

		case ROOM_MANAGEMENT_MENU:
			switch (read_option_and_show_menu(show_room_management_menu)) {
				case '1': current_menu = ADD_ROOM_MENU; break;
				case '2': current_menu = DELETE_ROOM_MENU; break;
				case '3':
					display_halls(&ls_sali);
					pause_and_continue();
					break;
				case '4': current_menu = SEARCH_ROOM_MENU; break;
				case 'x': current_menu = MAIN_MENU; break;
				default: show_invalid_option(); break;
			}
			break;

		case RESERVATION_MANAGEMENT_MENU:
			switch (read_option_and_show_menu(show_reservation_management_menu)) {
				case '1': current_menu = RESERVE_ROOM_MENU; break;
				case '2':
					display_rezervations(&ls_rez);
					pause_and_continue();
					break;
				case '3': current_menu = CANCEL_RESERVATION_MENU; break;
				case 'x': current_menu = MAIN_MENU; break;
				default: show_invalid_option(); break;
			}
			break;

		case ADD_ROOM_MENU:
			show_add_room_menu();
			if (add_hall_parsing(&ls_sali) == 1) { current_menu = ROOM_MANAGEMENT_MENU; }
			break;

		case DELETE_ROOM_MENU:
			show_delete_room_menu();
		    if (remove_hall_parsing(&ls_sali, &ls_rez) == 1) { current_menu = ROOM_MANAGEMENT_MENU; }
			break;

		case SEARCH_ROOM_MENU:
			switch (read_option_and_show_menu(show_search_room_menu)) {
				case '1': current_menu = SEARCH_ROOM_BY_NAME_MENU; break;
				case '2': current_menu = SEARCH_ROOM_BY_CAPACITY_MENU; break;
				case '3': current_menu = SEARCH_ROOM_BY_AVAILABILITY_MENU; break;
				case 'x': current_menu = ROOM_MANAGEMENT_MENU; break;
				default: show_invalid_option(); break;
			}
			break;

		case SEARCH_ROOM_BY_NAME_MENU:
			show_search_room_by_name_menu();
			if (search_hall_by_name_parsing(&ls_sali) == 1) { current_menu = SEARCH_ROOM_MENU; } 
			break;

		case SEARCH_ROOM_BY_CAPACITY_MENU:
			show_search_room_by_capacity_menu();
			if (search_hall_by_capacity_parsing(&ls_sali) == 1) { current_menu = SEARCH_ROOM_MENU; }
			break;

		case SEARCH_ROOM_BY_AVAILABILITY_MENU:
			show_search_room_by_availability_menu();
			if (search_hall_by_availability_parsing(&ls_sali) == 1) { current_menu = SEARCH_ROOM_MENU; }
			break;

		case RESERVE_ROOM_MENU:
			show_reserve_room_menu();
			if (add_rezervation_parsing(&ls_rez, &ls_sali) == 1) { current_menu = RESERVATION_MANAGEMENT_MENU; }
			break;

		case CANCEL_RESERVATION_MENU:
			show_cancel_reservation_menu();
			if (cancel_rezervation_parsing(&ls_rez, &ls_sali) == 1) { current_menu = RESERVATION_MANAGEMENT_MENU; }
			break;

		case EXIT_PROGRAM:
			break;
		}
	}

	return 0;
}