#define _CRT_SECURE_NO_WARNINGS
#include "models/reservations/reservations.h"
#include "models/halls/halls.h"
#include "menus/display/display.h"
#include "menus/colors.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Dimensiunile coloanelor tabelului de rezervari
#define REZ_COL_COUNT 4
static int rez_col_widths[REZ_COL_COUNT] = { 4, 20, 4, 12 };
static char *rez_headers[REZ_COL_COUNT] = { "ID", "Nume Sala", "Ora", "Data" };

// Afiseaza un rand de rezervare in format tabel
static void print_rez_row(Reservation *rez) {
    char id_str[12];
    char ora_str[12];
    char data_str[16];
    snprintf(id_str, sizeof(id_str), "%d", rez->id);
    snprintf(ora_str, sizeof(ora_str), "%d", rez->hour);
    snprintf(data_str, sizeof(data_str), "%02d/%02d/%04d", rez->day, rez->month, rez->year);
    char *values[REZ_COL_COUNT] = { id_str, rez->hall_name, ora_str, data_str };
    print_row(REZ_COL_COUNT, rez_col_widths, values);
}

void modify_availability_in_hall(HallsList *ls_halls, char *hall_name, bool availability) {
    for(Hall *tmp = ls_halls->head; tmp != NULL; tmp = tmp->next) {
        if(strcmp(hall_name, tmp->hall_name) == 0) {
            tmp->is_available = availability;
            break;
        }
    }
}

void add_reservation(ReservationsList *ls_reservations, HallsList *ls_halls, char *hall_name, int hour, int day, int month, int year) {
    Hall *hall_to_reserve = NULL;
    for(Hall *tmp = ls_halls->head; tmp != NULL; tmp = tmp->next) {
        if(strcmp(hall_name, tmp->hall_name) == 0) {
            hall_to_reserve = tmp;
            break;
        }
    }

    if(hall_to_reserve == NULL) {
        printf(COLOR_WARNING "Nu exista sala cu numele introdus\n" RESET);
        return;
    }

    if(hall_to_reserve->is_available == false) {
        printf(COLOR_WARNING "Sala este deja rezervata\n" RESET);
        return;
    }

    Reservation *nou = (Reservation *)malloc(sizeof(Reservation));
    if(nou == NULL) {
        printf(COLOR_ERROR "Nu s-a putut aloca memorie pentru o rezervare noua\n" RESET);
        return;
    }

    nou->hall_name = malloc(strlen(hall_name) + 1);
    strcpy(nou->hall_name, hall_name);
    nou->hour = hour;
    nou->day = day;
    nou->month = month;
    nou->year = year;
    ls_reservations->size++;
    nou->id = ls_reservations->size;
    nou->next = NULL;

    modify_availability_in_hall(ls_halls, nou->hall_name, false);

    if(ls_reservations->head == NULL) {
        ls_reservations->head = nou;
        ls_reservations->tail = nou;
    } else {
        ls_reservations->tail->next = nou;
        ls_reservations->tail = nou;
    }
}

void cancel_reservation(ReservationsList *ls_reservations, HallsList *ls_halls, int id) {
    if(id < 1 || id > ls_reservations->size) {
        printf(COLOR_ERROR "ID invalid\n" RESET);
        return;
    }

    if(ls_reservations->size == 0) {
        printf(COLOR_WARNING "Nu exista rezervari\n" RESET);
        return;
    }

    Reservation *tmp = ls_reservations->head;
    Reservation *prev = NULL;

    while (tmp != NULL && tmp->id != id) {
        prev = tmp;
        tmp = tmp->next;
    }

    if (tmp == NULL) return; 

    modify_availability_in_hall(ls_halls, tmp->hall_name, true);

    if (prev == NULL) {
        ls_reservations->head = tmp->next;
    } else {
        prev->next = tmp->next;
    }

    if (tmp == ls_reservations->tail) {
        ls_reservations->tail = prev;
    }

    for (Reservation *tmp2 = tmp->next; tmp2 != NULL; tmp2 = tmp2->next) {
        tmp2->id--;
    }

    free(tmp->hall_name);
    free(tmp);

    ls_reservations->size--;
}

void cancel_reservations_by_hall_name(ReservationsList *ls_reservations, char *hall_name) {
    if (ls_reservations == NULL || ls_reservations->head == NULL) return;

    Reservation *current = ls_reservations->head;
    Reservation *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->hall_name, hall_name) == 0) {
            Reservation *toDelete = current;
            if (prev == NULL) {
                ls_reservations->head = current->next;
            } else {
                prev->next = current->next;
            }
            
            if (toDelete == ls_reservations->tail) {
                ls_reservations->tail = prev;
            }

            current = current->next;
            free(toDelete->hall_name);
            free(toDelete);
            ls_reservations->size--;
        } else {
            prev = current;
            current = current->next;
        }
    }
    
    int id = 1;
    for (Reservation *tmp = ls_reservations->head; tmp != NULL; tmp = tmp->next) {
        tmp->id = id++;
    }
}

void display_reservations(ReservationsList *ls_reservations) {
    if(ls_reservations->size == 0) {
        printf(COLOR_WARNING "Nu exista rezervari de afisat\n" RESET);
        return;
    }

    print_table_header(REZ_COL_COUNT, rez_col_widths, rez_headers);
    for(Reservation *tmp = ls_reservations->head; tmp != NULL; tmp = tmp->next) {
        print_rez_row(tmp);
    }
    print_separator(REZ_COL_COUNT, rez_col_widths);
}