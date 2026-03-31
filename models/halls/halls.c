#define _CRT_SECURE_NO_WARNINGS
#include "halls.h"
#include "../rezervations/rezervations.h"
#include "../../menus/display/display.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Dimensiunile coloanelor tabelului de sali
#define HALL_COL_COUNT 4
static int hall_col_widths[HALL_COL_COUNT] = { 4, 20, 10, 15 };
static char *hall_headers[HALL_COL_COUNT] = { "ID", "Nume Sala", "Capacitate", "Disponibilitate" };

// Afiseaza un rand de sala in format tabel
static void print_hall_row(Sala *sala) {
    char id_str[12];
    char cap_str[12];
    snprintf(id_str, sizeof(id_str), "%d", sala->id);
    snprintf(cap_str, sizeof(cap_str), "%d", sala->capacitate);
    char *disp_str = sala->esteDisponibila ? "DA" : "NU";
    char *values[HALL_COL_COUNT] = { id_str, sala->nume_sala, cap_str, disp_str };
    print_row(HALL_COL_COUNT, hall_col_widths, values);
}

void add_hall(ListSali *ls_sali, char *nume_sala, int capacitate, bool esteDisponibila) {
    Sala *nou = (Sala *)malloc(sizeof(Sala));
    if(nou == NULL) {
        printf("Eroare interna. Nu s-a putut aloca memorie pentru o sala noua\n");
        return;
    }

    nou->nume_sala = malloc(strlen(nume_sala) + 1);
    strcpy(nou->nume_sala, nume_sala);
    nou->capacitate = capacitate;
    nou->esteDisponibila = esteDisponibila;
    nou->next = NULL;
    
    if(ls_sali->size == 0) {
        ls_sali->head = nou;
        ls_sali->tail = nou;
    } else {
        ls_sali->tail->next = nou;
        ls_sali->tail = nou;
    }
    ls_sali->size++;
    nou->id = ls_sali->size;
}

void remove_hall(ListSali *ls_sali, ListRezervari *ls_rez, int id) {
    if(id < 1 || id > ls_sali->size) {
        printf("Sala cu ID: %d nu exista\n", id);
        return;
    }

    Sala *tmp = ls_sali->head;
    Sala *prev = NULL;

    while (tmp != NULL && tmp->id != id) {
        prev = tmp;
        tmp = tmp->next;
    }

    if (tmp == NULL) return;

    cancel_rezervations_by_hall_name(ls_rez, tmp->nume_sala);

    if (prev == NULL) {
        ls_sali->head = tmp->next;
    } else {
        prev->next = tmp->next;
    }

    if (tmp == ls_sali->tail) {
        ls_sali->tail = prev;
    }

    for (Sala *tmp2 = tmp->next; tmp2 != NULL; tmp2 = tmp2->next) {
        tmp2->id--;
    }

    free(tmp->nume_sala);
    free(tmp);

    ls_sali->size--;
}

void find_hall_by_name(ListSali *ls_sali, char *nume_sala) {
    if(ls_sali->size == 0) {
        printf("Lista de sali este goala\n");
        return;
    }

    Sala *gasit = NULL;
    for(Sala *tmp = ls_sali->head; tmp != NULL; tmp = tmp->next) {
        if(strcmp(tmp->nume_sala, nume_sala) == 0) {
            gasit = tmp;
            break;
        }
    }

    if(gasit == NULL) {
        printf("Nu exista sala cu numele %s\n", nume_sala);
    } else {
        print_table_header(HALL_COL_COUNT, hall_col_widths, hall_headers);
        print_hall_row(gasit);
        print_separator(HALL_COL_COUNT, hall_col_widths);
    }
}

void find_hall_by_capacity(ListSali *ls_sali, int capacitate) {
    if(ls_sali->size == 0) {
        printf("Lista de sali este goala\n");
        return;
    }

    bool gasit = false;
    for(Sala *tmp = ls_sali->head; tmp != NULL; tmp = tmp->next) {
        if(tmp->capacitate == capacitate) {
            if(!gasit) {
                print_table_header(HALL_COL_COUNT, hall_col_widths, hall_headers);
            }
            gasit = true;
            print_hall_row(tmp);
        }
    }

    if(gasit) {
        print_separator(HALL_COL_COUNT, hall_col_widths);
    } else {
        printf("Nu exista sala cu capacitatea %d\n", capacitate);
    }
}

void find_hall_by_availability(ListSali *ls_sali, bool esteDisponibila) {
    if(ls_sali->size == 0) {
        printf("Lista de sali este goala\n");
        return;
    }

    bool gasit = false;
    for(Sala *tmp = ls_sali->head; tmp != NULL; tmp = tmp->next) {
        if(tmp->esteDisponibila == esteDisponibila) {
            if(!gasit) {
                print_table_header(HALL_COL_COUNT, hall_col_widths, hall_headers);
            }
            gasit = true;
            print_hall_row(tmp);
        }
    }

    if(gasit) {
        print_separator(HALL_COL_COUNT, hall_col_widths);
    } else {
        printf("Nu exista sali %s\n", esteDisponibila ? "disponibile" : "indisponibile");
    }
}

void display_halls(ListSali *ls_sali) {
    if(ls_sali->size == 0) {
        printf("Nu exista sali de afisat\n");
        return;
    }

    print_table_header(HALL_COL_COUNT, hall_col_widths, hall_headers);
    for(Sala *tmp = ls_sali->head; tmp != NULL; tmp = tmp->next) {
        print_hall_row(tmp);
    }
    print_separator(HALL_COL_COUNT, hall_col_widths);
}