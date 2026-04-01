#define _CRT_SECURE_NO_WARNINGS
#include "models/halls/halls.h"
#include "models/reservations/reservations.h"
#include "menus/display/display.h"
#include "menus/colors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Dimensiunile coloanelor tabelului de sali
#define HALL_COL_COUNT 4
static int hall_col_widths[HALL_COL_COUNT] = { 4, 20, 10, 15 };
static char *hall_headers[HALL_COL_COUNT] = { "ID", "Nume Sala", "Capacitate", "Disponibilitate" };

// Afiseaza un rand de sala in format tabel
static void print_hall_row(Hall *hall) {
    char id_str[12];
    char cap_str[12];
    snprintf(id_str, sizeof(id_str), "%d", hall->id);
    snprintf(cap_str, sizeof(cap_str), "%d", hall->capacity);
    char *disp_str = hall->is_available ? "DA" : "NU";
    char *values[HALL_COL_COUNT] = { id_str, hall->hall_name, cap_str, disp_str };
    print_row(HALL_COL_COUNT, hall_col_widths, values);
}

void add_hall(HallsList *ls_halls, char *hall_name, int capacity, bool is_available) {
    Hall *new_hall = (Hall *)malloc(sizeof(Hall));
    if(new_hall == NULL) {
        printf(COLOR_ERROR "Eroare interna. Nu s-a putut aloca memorie pentru o sala noua\n" RESET);
        return;
    }

    new_hall->hall_name = malloc(strlen(hall_name) + 1);
    strcpy(new_hall->hall_name, hall_name);
    new_hall->capacity = capacity;
    new_hall->is_available = is_available;
    new_hall->next = NULL;
    
    if(ls_halls->size == 0) {
        ls_halls->head = new_hall;
        ls_halls->tail = new_hall;
    } else {
        ls_halls->tail->next = new_hall;
        ls_halls->tail = new_hall;
    }
    ls_halls->size++;
    new_hall->id = ls_halls->size;
}

void remove_hall(HallsList *ls_halls, ReservationsList *ls_reservations, int id) {
    if(id < 1 || id > ls_halls->size) {
        printf(COLOR_ERROR "Sala cu ID: %d nu exista\n" RESET, id);
        return;
    }

    Hall *tmp = ls_halls->head;
    Hall *prev = NULL;

    while (tmp != NULL && tmp->id != id) {
        prev = tmp;
        tmp = tmp->next;
    }

    if (tmp == NULL) return;

    cancel_reservations_by_hall_name(ls_reservations, tmp->hall_name);

    if (prev == NULL) {
        ls_halls->head = tmp->next;
    } else {
        prev->next = tmp->next;
    }

    if (tmp == ls_halls->tail) {
        ls_halls->tail = prev;
    }

    for (Hall *tmp2 = tmp->next; tmp2 != NULL; tmp2 = tmp2->next) {
        tmp2->id--;
    }

    free(tmp->hall_name);
    free(tmp);

    ls_halls->size--;
}

void find_hall_by_name(HallsList *ls_halls, char *hall_name) {
    if(ls_halls->size == 0) {
        printf(COLOR_WARNING "Lista de sali este goala\n" RESET);
        return;
    }

    Hall *found = NULL;
    for(Hall *tmp = ls_halls->head; tmp != NULL; tmp = tmp->next) {
        if(strcmp(tmp->hall_name, hall_name) == 0) {
            found = tmp;
            break;
        }
    }

    if(found == NULL) {
        printf(COLOR_WARNING "Nu exista sala cu numele %s\n" RESET, hall_name);
    } else {
        print_table_header(HALL_COL_COUNT, hall_col_widths, hall_headers);
        print_hall_row(found);
        print_separator(HALL_COL_COUNT, hall_col_widths);
    }
}

void find_hall_by_capacity(HallsList *ls_halls, int capacity) {
    if(ls_halls->size == 0) {
        printf(COLOR_WARNING "Lista de sali este goala\n" RESET);
        return;
    }

    bool found = false;
    for(Hall *tmp = ls_halls->head; tmp != NULL; tmp = tmp->next) {
        if(tmp->capacity == capacity) {
            if(!found) {
                print_table_header(HALL_COL_COUNT, hall_col_widths, hall_headers);
            }
            found = true;
            print_hall_row(tmp);
        }
    }

    if(found) {
        print_separator(HALL_COL_COUNT, hall_col_widths);
    } else {
        printf(COLOR_WARNING "Nu exista sala cu capacitatea %d\n" RESET, capacity);
    }
}

void find_hall_by_availability(HallsList *ls_halls, bool is_available) {
    if(ls_halls->size == 0) {
        printf(COLOR_WARNING "Lista de sali este goala\n" RESET);
        return;
    }

    bool found = false;
    for(Hall *tmp = ls_halls->head; tmp != NULL; tmp = tmp->next) {
        if(tmp->is_available == is_available) {
            if(!found) {
                print_table_header(HALL_COL_COUNT, hall_col_widths, hall_headers);
            }
            found = true;
            print_hall_row(tmp);
        }
    }

    if(found) {
        print_separator(HALL_COL_COUNT, hall_col_widths);
    } else {
        printf(COLOR_WARNING "Nu exista sali %s\n" RESET, is_available ? "disponibile" : "indisponibile");
    }
}

void display_halls(HallsList *ls_halls) {
    if(ls_halls->size == 0) {
        printf(COLOR_WARNING "Nu exista sali de afisat\n" RESET);
        return;
    }

    print_table_header(HALL_COL_COUNT, hall_col_widths, hall_headers);
    for(Hall *tmp = ls_halls->head; tmp != NULL; tmp = tmp->next) {
        print_hall_row(tmp);
    }
    print_separator(HALL_COL_COUNT, hall_col_widths);
}