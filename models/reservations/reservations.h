#ifndef RESERVATIONS_H
#define RESERVATIONS_H

#include <stdbool.h>

typedef struct hall Hall;
typedef struct hallslist HallsList;

// Structura unei rezervari
typedef struct reservation {
    int id;
    char *hall_name;
    int hour;
    int day;
    int month;
    int year;
    struct reservation *next;
} Reservation;

// Structura listei de rezervari
typedef struct reservationslist {
    Reservation *head;
    Reservation *tail;
    int size;
} ReservationsList;

// Adauga o rezervare la finalul listei
void add_reservation(ReservationsList *ls_reservations, HallsList *ls_halls, char *hall_name, int hour, int day, int month, int year);

// Anuleaza o rezervare
void cancel_reservation(ReservationsList *ls_reservations, HallsList *ls_halls, int id);

// Sterge toate rezervarile asociate unei sali
void cancel_reservations_by_hall_name(ReservationsList *ls_reservations, char *hall_name);

// Afiseaza toate rezervarile
void display_reservations(ReservationsList *ls_reservations);

// Modifica disponibilitatea salii
void modify_availability_in_hall(HallsList *ls_halls, char *hall_name, bool availability);

#endif