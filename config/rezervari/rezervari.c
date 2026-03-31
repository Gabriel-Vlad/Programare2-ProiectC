#define _CRT_SECURE_NO_WARNINGS
#include "rezervari.h"
#include "../sali/sali.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
        printf("Press ENTER to continue...");
        return;
    }

    if(hall_to_reserve->esteDisponibila == false) {
        printf("Sala este deja rezervata\n");
        printf("Press ENTER to continue...");
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

void cancel_rezervation_beginning(ListRezervari *ls_rez, ListSali *ls_sali) {
    if(ls_rez->size == 0) {
        printf("Nu exista rezervari de anulat");
        return;
    }

    modify_availability_in_hall(ls_sali, ls_rez->head->nume_sala, true);

    if(ls_rez->size == 1) {
        free(ls_rez->head->nume_sala);
        free(ls_rez->head);
        ls_rez->head = NULL;
        ls_rez->tail = NULL;
    } else {
        Rezervare *newHead = ls_rez->head->next;
        free(ls_rez->head->nume_sala);
        free(ls_rez->head);
        ls_rez->head = newHead;
        for(Rezervare *tmp = ls_rez->head; tmp != NULL; tmp = tmp->next) {
            tmp->id--;
        }
    }
    
    ls_rez->size--;
}

void cancel_rezervation_end(ListRezervari *ls_rez, ListSali *ls_sali) {
    if(ls_rez->size == 0) {
        printf("Nu exista rezervari de anulat");
        return;
    }

    modify_availability_in_hall(ls_sali, ls_rez->tail->nume_sala, true);

    if(ls_rez->size == 1) {
        free(ls_rez->head->nume_sala);
        free(ls_rez->head);
        ls_rez->head = NULL;
        ls_rez->tail = NULL;
    } else {
        Rezervare *tmp = ls_rez->head;
        while(tmp->next != ls_rez->tail) {
            tmp = tmp->next;
        }
        free(tmp->next->nume_sala);
        free(tmp->next);
        tmp->next = NULL;
        ls_rez->tail = tmp;
    }
    
    ls_rez->size--;
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

    if(id == 1) { cancel_rezervation_beginning(ls_rez, ls_sali); return; }
    if(id == ls_rez->size) { cancel_rezervation_end(ls_rez, ls_sali); return; }

    Rezervare *tmp = ls_rez->head;
    while(tmp->id != id - 1) {
        tmp = tmp->next;
    }

    modify_availability_in_hall(ls_sali, tmp->next->nume_sala, true);

    for(Rezervare *tmp2 = tmp->next->next; tmp2 != NULL; tmp2 = tmp2->next) {
        tmp2->id--;
    }
    
    Rezervare *toDelete = tmp->next;
    tmp->next = tmp->next->next;

    free(toDelete->nume_sala);
    free(toDelete);

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

// TODO de formatat mai bine afisarea rezervarilor
void display_rezervations(ListRezervari *ls_rez) {
    if(ls_rez->size == 0) {
        printf("Nu exista rezervari de afisat");
        return;
    }

    for(Rezervare *tmp = ls_rez->head; tmp != NULL; tmp = tmp->next) {
        printf("%d %s\n", tmp->id, tmp->nume_sala);
    }
}