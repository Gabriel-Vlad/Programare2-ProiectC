#ifndef DATABASE_H
#define DATABASE_H

#include "../models/rezervations/rezervations.h"
#include "../models/halls/halls.h"

extern ListSali ls_sali;
extern ListRezervari ls_rez;

void init_database();

#endif