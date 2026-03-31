#ifndef SALI_H
#define SALI_H

#include <stdbool.h>

typedef struct rezervare Rezervare;
typedef struct listrezervari ListRezervari;

// structura unei sali
typedef struct sala {
    int id;
    int capacitate;
    char *nume_sala;
    bool esteDisponibila;
    struct sala *next;
} Sala;

// structura unei liste de sali
typedef struct listsali {
    Sala *head;
    Sala *tail;
    int size;
} ListSali;

// adauga o sala la finalul listei
void add_hall(ListSali *ls_sali, char *nume_sala, int capacitate, bool esteDisponibila);

// sterge o sala de la inceputul listei
void remove_hall_beginning(ListSali *ls_sali, ListRezervari *ls_rez);

//sterge o sala de la finalul listei
void remove_hall_end(ListSali *ls_sali, ListRezervari *ls_rez);

// sterge o sala oriunde in lista (se foloseste de cele 2 functii pentru cazurile speciale)
void remove_hall(ListSali *ls_sali, ListRezervari *ls_rez, int id);

// cauta o sala dupa nume
void find_hall_by_name(ListSali *ls_sali, char *nume_sala);

//cauta o sala dupa capacitate
void find_hall_by_capacity(ListSali *ls_sali, int capacitate);

// cauta o sala dupa disponibilitate
void find_hall_by_availability(ListSali *ls_sali, bool disponibila);

// afiseaza toate salile
void display_halls(ListSali *ls_sali);

#endif