#define _CRT_SECURE_NO_WARNINGS
#include "rezervations.h"
#include "../halls/halls.h"
#include "../../menus/display/display.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Dimensiunile coloanelor tabelului de rezervari
#define REZ_COL_COUNT 4
static int rez_col_widths[REZ_COL_COUNT] = { 4, 20, 4, 12 };
static char *rez_headers[REZ_COL_COUNT] = { "ID", "Nume Sala", "Ora", "Data" };

// Afiseaza un rand de rezervare in format tabel
static void print_rez_row(Rezervare *rez) {
    char id_str[12];
    char ora_str[12];
    char data_str[16];
    snprintf(id_str, sizeof(id_str), "%d", rez->id);
    snprintf(ora_str, sizeof(ora_str), "%d", rez->ora);
    snprintf(data_str, sizeof(data_str), "%02d/%02d/%04d", rez->zi, rez->luna, rez->an);
    char *values[REZ_COL_COUNT] = { id_str, rez->nume_sala, ora_str, data_str };
    print_row(REZ_COL_COUNT, rez_col_widths, values);
}

void modify_availability_in_hall(ListSali *ls_sali, char *nume_sala, bool disponibilitate) {
    for(Sala *tmp = ls_sali->head; tmp != NULL; tmp = tmp->next) {
        if(strcmp(nume_sala, tmp->nume_sala) == 0) {
            tmp->esteDisponibila = disponibilitate;
            break;
        }
    }
}

void add_rezervation(ListRezervari *ls_rez, ListSali *ls_sali, char *nume_sala, int ora, int zi, int luna, int an) {
    Sala *hall_to_reserve = NULL;
    for(Sala *tmp = ls_sali->head; tmp != NULL; tmp = tmp->next) {
        if(strcmp(nume_sala, tmp->nume_sala) == 0) {
            hall_to_reserve = tmp;
            break;
        }
    }

    if(hall_to_reserve == NULL) {
        printf("Nu exista sala cu numele introdus\n");
        return;
    }

    if(hall_to_reserve->esteDisponibila == false) {
        printf("Sala este deja rezervata\n");
        return;
    }

    Rezervare *nou = (Rezervare *)malloc(sizeof(Rezervare));
    if(nou == NULL) {
        printf("Nu s-a putut aloca memorie pentru o rezervare noua");
        return;
    }

    nou->nume_sala = malloc(strlen(nume_sala) + 1);
    strcpy(nou->nume_sala, nume_sala);
    nou->ora = ora;
    nou->zi = zi;
    nou->luna = luna;
    nou->an = an;
    ls_rez->size++;
    nou->id = ls_rez->size;
    nou->next = NULL;

    modify_availability_in_hall(ls_sali, nou->nume_sala, false);

    if(ls_rez->head == NULL) {
        ls_rez->head = nou;
        ls_rez->tail = nou;
    } else {
        ls_rez->tail->next = nou;
        ls_rez->tail = nou;
    }
}

void cancel_rezervation(ListRezervari *ls_rez, ListSali *ls_sali, int id) {
    if(id < 1 || id > ls_rez->size) {
        printf("ID invalid");
        return;
    }

    if(ls_rez->size == 0) {
        printf("Nu exista rezervari");
        return;
    }

    Rezervare *tmp = ls_rez->head;
    Rezervare *prev = NULL;

    while (tmp != NULL && tmp->id != id) {
        prev = tmp;
        tmp = tmp->next;
    }

    if (tmp == NULL) return; 

    modify_availability_in_hall(ls_sali, tmp->nume_sala, true);

    if (prev == NULL) {
        ls_rez->head = tmp->next;
    } else {
        prev->next = tmp->next;
    }

    if (tmp == ls_rez->tail) {
        ls_rez->tail = prev;
    }

    for (Rezervare *tmp2 = tmp->next; tmp2 != NULL; tmp2 = tmp2->next) {
        tmp2->id--;
    }

    free(tmp->nume_sala);
    free(tmp);

    ls_rez->size--;
}

void cancel_rezervations_by_hall_name(ListRezervari *ls_rez, char *nume_sala) {
    if (ls_rez == NULL || ls_rez->head == NULL) return;

    Rezervare *current = ls_rez->head;
    Rezervare *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->nume_sala, nume_sala) == 0) {
            Rezervare *toDelete = current;
            if (prev == NULL) {
                ls_rez->head = current->next;
            } else {
                prev->next = current->next;
            }
            
            if (toDelete == ls_rez->tail) {
                ls_rez->tail = prev;
            }

            current = current->next;
            free(toDelete->nume_sala);
            free(toDelete);
            ls_rez->size--;
        } else {
            prev = current;
            current = current->next;
        }
    }
    
    int id = 1;
    for (Rezervare *tmp = ls_rez->head; tmp != NULL; tmp = tmp->next) {
        tmp->id = id++;
    }
}

void display_rezervations(ListRezervari *ls_rez) {
    if(ls_rez->size == 0) {
        printf("Nu exista rezervari de afisat\n");
        return;
    }

    print_table_header(REZ_COL_COUNT, rez_col_widths, rez_headers);
    for(Rezervare *tmp = ls_rez->head; tmp != NULL; tmp = tmp->next) {
        print_rez_row(tmp);
    }
    print_separator(REZ_COL_COUNT, rez_col_widths);
}