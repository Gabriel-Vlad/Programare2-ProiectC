#ifndef HALLS_INPUT_H
#define HALLS_INPUT_H

#include "../../../models/halls/halls.h"
#include "../../../models/rezervations/rezervations.h"

int add_hall_parsing(ListSali *ls_sali);
int remove_hall_parsing(ListSali *ls_sali, ListRezervari *ls_rez);
int search_hall_by_name_parsing(ListSali *ls_sali);
int search_hall_by_capacity_parsing(ListSali *ls_sali);
int search_hall_by_availability_parsing(ListSali *ls_sali);

#endif
