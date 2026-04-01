#ifndef HALLS_H
#define HALLS_H

#include <stdbool.h>

typedef struct reservation Reservation;
typedef struct reservationslist ReservationsList;

// Structura unei sali
typedef struct hall {
    int id;
    int capacity;
    char *hall_name;
    bool is_available;
    struct hall *next;
} Hall;

// Structura unei liste de sali
typedef struct hallslist {
    Hall *head;
    Hall *tail;
    int size;
} HallsList;

// Adauga o sala la finalul listei
void add_hall(HallsList *ls_halls, char *hall_name, int capacity, bool is_available);

// Sterge o sala
void remove_hall(HallsList *ls_halls, ReservationsList *ls_reservations, int id);

// Cauta o sala dupa nume
void find_hall_by_name(HallsList *ls_halls, char *hall_name);

// Cauta o sala dupa capacitate
void find_hall_by_capacity(HallsList *ls_halls, int capacity);

// Cauta o sala dupa disponibilitate
void find_hall_by_availability(HallsList *ls_halls, bool is_available);

// Afiseaza toate salile
void display_halls(HallsList *ls_halls);

#endif