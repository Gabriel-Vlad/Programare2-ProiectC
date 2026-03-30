#ifndef SALI_H
#define SALI_H

typedef struct sala {
    int id;
    int capacitate;
    char *nume;
    bool disponibila;
    struct sala *next;
} Sala;

typedef struct listsali {
    Sala *head;
    Sala *tail;
    int size;
} ListSali;

void add_hall(ListSali *ls, char *nume_sala, int capacitate);
void remove_hall_beginning(ListSali *ls);
void remove_hall_end(ListSali *ls);
void remove_hall(ListSali *ls, int id);
void find_hall_by_name(ListSali *ls, char *nume_sala);
void find_hall_by_capacity(ListSali *ls, int capacitate);
void find_hall_by_availability(ListSali *ls, bool disponibila);
void display_halls(ListSali *ls);

#endif