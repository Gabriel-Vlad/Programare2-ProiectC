#ifndef REZERVATIONS_INPUT_H
#define REZERVATIONS_INPUT_H

#include "../../../models/halls/halls.h"
#include "../../../models/rezervations/rezervations.h"

int add_rezervation_parsing(ListRezervari *ls_rez, ListSali *ls_sali);
int cancel_rezervation_parsing(ListRezervari *ls_rez, ListSali *ls_sali);

#endif