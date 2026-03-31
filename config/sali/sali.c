#define _CRT_SECURE_NO_WARNINGS
#include "sali.h"
#include "../rezervari/rezervari.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void add_hall(ListSali *ls_sali, char *nume_sala, int capacitate, bool esteDisponibila) {
    Sala *nou = (Sala *)malloc(sizeof(Sala));
    if(nou == NULL) {
        printf("Cannot allocate memory for a new hall");
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

void remove_hall_beginning(ListSali *ls_sali, ListRezervari *ls_rez) {
    if(ls_sali->size == 0) {
        printf("No halls exist");
        return;
    }

    cancel_rezervations_by_hall_name(ls_rez, ls_sali->head->nume_sala);

    if(ls_sali->size == 1) {
        free(ls_sali->head->nume_sala);
        free(ls_sali->head);
        ls_sali->head = NULL;
        ls_sali->tail = NULL;
    } else {
        Sala *newHead = ls_sali->head->next;
        for(Sala *tmp = ls_sali->head->next; tmp != NULL; tmp = tmp->next) {
            tmp->id--;
        }
        free(ls_sali->head->nume_sala);
        free(ls_sali->head);
        ls_sali->head = newHead;
    }

    ls_sali->size--;
}

void remove_hall_end(ListSali *ls_sali, ListRezervari *ls_rez) {
    if(ls_sali->size == 0) {
        printf("No halls exist");
        return;
    }

    cancel_rezervations_by_hall_name(ls_rez, ls_sali->tail->nume_sala);

    if(ls_sali->size == 1) {
        free(ls_sali->head->nume_sala);
        free(ls_sali->head);
        ls_sali->head = NULL;
        ls_sali->tail = NULL;
    } else {
        Sala *tmp = ls_sali->head;
        while(tmp->next != ls_sali->tail) {
            tmp = tmp->next;
        }
        free(ls_sali->tail->nume_sala);
        free(ls_sali->tail);
        tmp->next = NULL;
        ls_sali->tail = tmp;
    }

    ls_sali->size--;
}


void remove_hall(ListSali *ls_sali, ListRezervari *ls_rez, int id) {
    if(id < 1 || id > ls_sali->size) {
        printf("Hall with ID: %d doesn't exist", id);
        return;
    }
    if(id == 1) {remove_hall_beginning(ls_sali, ls_rez); return;}
    if(id == ls_sali->size) {remove_hall_end(ls_sali, ls_rez); return;}

    Sala *tmp = ls_sali->head;
    while(tmp->id != id - 1) {
        tmp = tmp->next;
    }
    for(Sala *tmp2 = tmp->next->next; tmp2 != NULL; tmp2 = tmp2->next) {
        tmp2->id--;
    }
    Sala *toDelete = tmp->next;
    cancel_rezervations_by_hall_name(ls_rez, toDelete->nume_sala);
    tmp->next = tmp->next->next;
    
    free(toDelete->nume_sala);
    free(toDelete);

    ls_sali->size--;
}

void find_hall_by_name(ListSali *ls_sali, char *nume_sala) {
    if(ls_sali->size == 0) {
        printf("Lista de sali este goala");
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
        printf("%d %s %d %d\n", gasit->id, gasit->nume_sala, gasit->capacitate, gasit->esteDisponibila);
    }
}


void find_hall_by_capacity(ListSali *ls_sali, int capacitate) {
     if(ls_sali->size == 0) {
        printf("Lista de sali este goala");
        return;
    }

    bool gasit = false;
    for(Sala *tmp = ls_sali->head; tmp != NULL; tmp = tmp->next) {
        if(tmp->capacitate == capacitate) {
            gasit = 1;
            printf("%d %s\n", tmp->id, tmp->nume_sala);
        }
    }

    if(gasit == false) {
        printf("Nu exista sala cu capacitatea %d", capacitate);
    }
}

void find_hall_by_availability(ListSali *ls_sali, bool esteDisponibila) {
     if(ls_sali->size == 0) {
        printf("Lista de sali este goala\n");
        printf("Press ENTER to continue");
        return;
    }

    bool gasit = false;
    for(Sala *tmp = ls_sali->head; tmp != NULL; tmp = tmp->next) {
        if(tmp->esteDisponibila == esteDisponibila) {
            gasit = true;
            printf("%d %s\n", tmp->id, tmp->nume_sala);
        }
    }

    if(gasit == false) {
        printf("Nu exista sala cu disponibilitatea %d\n", esteDisponibila);
        printf("Press ENTER to continue...");
    }
}

// TODO de formatat mai bine afisarea salilor
void display_halls(ListSali *ls_sali) {
    if(ls_sali->size == 0) {
        printf("Nu exista sali de afisat");
        return;
    }
    for(Sala *tmp = ls_sali->head; tmp != NULL; tmp = tmp->next) {
        printf("%d %s %d %d\n", tmp->id, tmp->nume_sala, tmp->capacitate, tmp->esteDisponibila);
    }
}