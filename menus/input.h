#ifndef INPUT_H
#define INPUT_H

#include "../config/sali/sali.h"
#include "../config/rezervari/rezervari.h"

int add_hall_parsing(ListSali *ls_sali);
int remove_hall_parsing(ListSali *ls_sali, ListRezervari *ls_rez);
int search_hall_by_name_parsing(ListSali *ls_sali);
int search_hall_by_capacity_parsing(ListSali *ls_sali);
int search_hall_by_availability_parsing(ListSali *ls_sali);

int add_rezervation_parsing(ListRezervari *ls_rez, ListSali *ls_sali);

#endif
