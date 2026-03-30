#ifndef REZERVARI_H
#define REZERVARI_H

#include <stdbool.h>

typedef struct rezervare {
    int id;
    int id_sala;
    char *nume_sala;
    int ora;
    int zi;
    int luna;
    int an;
    struct rezervare *next;
} Rezervare;

typedef struct listrezervari {
    Rezervare *head;
    Rezervare *tail;
    int size;
} ListRezervari;

void add_rezervation(ListRezervari *ls, char *nume_sala, int ora, int zi, int luna, int an);
void cancel_rezervation(ListRezervari *ls);
void display_rezervations(ListRezervari *ls);

#endif