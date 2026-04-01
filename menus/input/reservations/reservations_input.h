#ifndef RESERVATIONS_INPUT_H
#define RESERVATIONS_INPUT_H

#include "models/halls/halls.h"
#include "models/reservations/reservations.h"
#include "menus/input/utils/utils.h"

InputResult add_reservation_parsing(ReservationsList *ls_reservations, HallsList *ls_halls);
InputResult cancel_reservation_parsing(ReservationsList *ls_reservations, HallsList *ls_halls);

#endif