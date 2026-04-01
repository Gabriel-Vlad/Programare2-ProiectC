#ifndef HALLS_INPUT_H
#define HALLS_INPUT_H

#include "models/halls/halls.h"
#include "models/reservations/reservations.h"
#include "menus/input/utils/utils.h"

InputResult add_hall_parsing(HallsList *ls_halls);
InputResult remove_hall_parsing(HallsList *ls_halls, ReservationsList *ls_reservations);
InputResult search_hall_by_name_parsing(HallsList *ls_halls);
InputResult search_hall_by_capacity_parsing(HallsList *ls_halls);
InputResult search_hall_by_availability_parsing(HallsList *ls_halls);

#endif
