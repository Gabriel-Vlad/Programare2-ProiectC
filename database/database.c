#include "database.h"
#include <stdio.h>

ListSali ls_sali;
ListRezervari ls_rez;

void init_database() {
    ls_sali.head = NULL;
    ls_sali.tail = NULL;
    ls_sali.size = 0;

    ls_rez.head = NULL;
    ls_rez.tail = NULL;
    ls_rez.size = 0;
}