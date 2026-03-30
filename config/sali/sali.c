#define _CRT_SECURE_NO_WARNINGS
#include "sali.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void add_hall(ListSali *ls, char *nume_sala, int capacitate) {
    Sala *nou = (Sala *)malloc(sizeof(Sala));
    if(nou == NULL) {
        printf("Cannot allocate memory for a new hall");
        return;
    }
    ls->size++;
    nou->id = ls->size;
    nou->nume = malloc(strlen(nume_sala) + 1);
    strcpy(nou->nume, nume_sala);
    nou->capacitate = capacitate;
    nou->disponibila = true;
    nou->next = NULL;
    
    if(ls->size == 0) {
        ls->head = nou;
        ls->tail = nou;
    } else {
        ls->tail->next = nou;
    }
}

void remove_hall_beginning(ListSali *ls) {
    if(ls->size == 0) {
        printf("No halls exist");
        return;
    }

    if(ls->size == 1) {
        free(ls->head->nume);
        free(ls->head);
        ls->head = NULL;
        ls->tail = NULL;
    } else {
        Sala *newHead = ls->head->next;
        for(Sala *tmp = ls->head->next; tmp != NULL; tmp = tmp->next) {
            tmp->id--;
        }
        free(ls->head->nume);
        free(ls->head);
        ls->head = newHead;
    }

    ls->size--;
}

void remove_hall_end(ListSali *ls) {
    if(ls->size == 0) {
        printf("No halls exist");
        return;
    }

    if(ls->size == 1) {
        free(ls->head->nume);
        free(ls->head);
        ls->head = NULL;
        ls->tail = NULL;
    } else {
        Sala *tmp = ls->head;
        while(tmp->next != ls->tail) {
            tmp = tmp->next;
        }
        free(ls->tail->nume);
        free(ls->tail);
        tmp->next = NULL;
        ls->tail = tmp;
    }

    ls->size--;
}


void remove_hall(ListSali *ls, int id) {
    if(id < 1 || id > ls->size) {
        printf("Hall with ID: %d doesn't exist", id);
        return;
    }
    if(id == 1) {remove_hall_beginning(ls); return;}
    if(id == ls->size) {remove_hall_end(ls); return;}

    Sala *tmp = ls->head;
    while(tmp->id != id - 1) {
        tmp = tmp->next;
    }
    for(Sala *tmp2 = tmp->next->next; tmp2 != NULL; tmp2 = tmp2->next) {
        tmp2->id--;
    }
    Sala *toDelete = tmp->next;
    tmp->next = tmp->next->next;
    
    free(toDelete->nume);
    free(toDelete);

    ls->size--;
}

void find_hall_by_name(ListSali *ls, char *nume_sala) {
    if(ls->size == 0) {
        printf("Lista de sali este goala");
        return;
    }

    Sala *gasit = NULL;
    for(Sala *tmp = ls->head; tmp != NULL; tmp = tmp->next) {
        if(strcmp(tmp->nume, nume_sala) == 0) {
            gasit = tmp;
            break;
        }
    }

    if(gasit == NULL) {
        printf("Nu exista sala cu numele %s", nume_sala);
    } else {
        printf("%d %s", gasit->id, gasit->nume);
    }
}


void find_hall_by_capacity(ListSali *ls, int capacitate) {
     if(ls->size == 0) {
        printf("Lista de sali este goala");
        return;
    }

    bool gasit = false;
    for(Sala *tmp = ls->head; tmp != NULL; tmp = tmp->next) {
        if(tmp->capacitate == capacitate) {
            gasit = 1;
            printf("%d %s\n", tmp->id, tmp->nume);
        }
    }

    if(gasit == false) {
        printf("Nu exista sala cu capacitatea %d", capacitate);
    }
}

void find_hall_by_availability(ListSali *ls, bool disponibila) {
     if(ls->size == 0) {
        printf("Lista de sali este goala");
        return;
    }

    bool gasit = false;
    for(Sala *tmp = ls->head; tmp != NULL; tmp = tmp->next) {
        if(tmp->disponibila == disponibila) {
            gasit = true;
            printf("%d %s\n", tmp->id, tmp->nume);
        }
    }

    if(gasit == false) {
        printf("Nu exista sala cu disponibilitatea %d", disponibila);
    }
}

void display_halls(ListSali *ls) {
    if(ls->size == 0) {
        printf("No halls to display");
        return;
    }
    for(Sala *tmp = ls->head; tmp != NULL; tmp = tmp->next) {
        printf("%d %s\n", tmp->id, tmp->nume);
    }
}