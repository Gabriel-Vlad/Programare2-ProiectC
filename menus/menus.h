#ifndef MENUS_H
#define MENUS_H

typedef enum {
	MAIN_MENU,
	ROOM_MANAGEMENT_MENU,
	RESERVATION_MANAGEMENT_MENU,
	ADD_ROOM_MENU,
	DELETE_ROOM_MENU,
	SEARCH_ROOM_MENU,
	RESERVE_ROOM_MENU,
	CANCEL_RESERVATION_MENU,
	SEARCH_ROOM_BY_NAME_MENU,
	SEARCH_ROOM_BY_CAPACITY_MENU,
	SEARCH_ROOM_BY_AVAILABILITY_MENU,
	EXIT_PROGRAM
} MenuState;

void clear_screen();

void show_main_menu();
void show_room_management_menu();
void show_reservation_management_menu();

void show_add_room_menu();
void show_delete_room_menu();
void show_search_room_menu();

void show_reserve_room_menu();
void show_cancel_reservation_menu();

void show_search_room_by_name_menu();
void show_search_room_by_capacity_menu();
void show_search_room_by_availability_menu();

#endif