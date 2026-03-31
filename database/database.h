#ifndef DATABASE_H
#define DATABASE_H

#include "../config/rezervari/rezervari.h"
#include "../config/sali/sali.h"

extern ListSali ls_sali;
extern ListRezervari ls_rez;

void init_database();

#endif