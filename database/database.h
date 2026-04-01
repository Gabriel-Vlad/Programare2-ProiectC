#ifndef DATABASE_H
#define DATABASE_H

#include "models/reservations/reservations.h"
#include "models/halls/halls.h"

extern HallsList ls_halls;
extern ReservationsList ls_reservations;

void init_database();
void read_data();
void save_data_halls();
void save_data_reservations();

#endif