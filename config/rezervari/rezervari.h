#ifndef REZERVARI_H
#define REZERVARI_H

typedef struct sala Sala;
typedef struct listsali ListSali;

// structura unei rezervari
typedef struct rezervare {
    int id;
    char *nume_sala;
    int ora;
    int zi;
    int luna;
    int an;
    struct rezervare *next;
} Rezervare;

// structura listei de rezervari
typedef struct listrezervari {
    Rezervare *head;
    Rezervare *tail;
    int size;
} ListRezervari;

// adauga o rezervare la finalul listei
void add_rezervation(ListRezervari *ls_rez, ListSali *ls_sali, char *nume_sala, int ora, int zi, int luna, int an);

// anuleaza o rezervare de la inceput
void cancel_rezervation_beginning(ListRezervari *ls_rez, ListSali *ls_sali);

// anuleaza o rezervare de la sfarsit
void cancel_rezervation_end(ListRezervari *ls_rez, ListSali *ls_sali);

// anuleaza o rezervare cerura din lista
void cancel_rezervation(ListRezervari *ls_rez, ListSali *ls_sali, int id);

// sterge toate rezervarile asociate unei sali
void cancel_rezervations_by_hall_name(ListRezervari *ls_rez, char *nume_sala);

// afiseaza toate rezervarile
void display_rezervations(ListRezervari *ls_rez);

// modifica disponibilitatea salii
void modify_availability_in_hall(ListSali *ls_sali, char *nume_sala, bool disponibilitate);

#endif