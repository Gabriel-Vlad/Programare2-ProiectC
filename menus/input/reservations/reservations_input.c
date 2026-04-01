#define _CRT_SECURE_NO_WARNINGS
#include "includes.h"

InputResult add_reservation_parsing(ReservationsList *ls_reservations, HallsList *ls_halls) {
    char input[256];
    char hall_name_buffer[100];
    char hour_buffer[50];
    char date_buffer[50];
    char extra[256];

    if(fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        if(strcmp(input, "x") == 0) { return INPUT_GO_BACK; }

        int cnt_parsed_items = sscanf(input, "%s %s %s %s", hall_name_buffer, hour_buffer, date_buffer, extra);
        
        if (cnt_parsed_items != 3) {
            return error_msg("Input invalid. Input preconizat: <nume_sala> <ora> <DD/MM/YYYY>\n");
        }

        if (is_pure_number(hall_name_buffer) == true) {
            return error_msg("Input invalid. <nume_sala> nu poate fi un numar\n");
        }

        if (is_pure_number(hour_buffer) == false) {
            return error_msg("Input invalid. <ora> trebuie sa fie un numar natural\n");
        }
        
        int hour = atoi(hour_buffer);
        if (hour < 0 || hour > 23) {
            return error_msg("Input invalid. <ora> trebuie sa fie intre 0 si 23\n");
        }

        int day, month, year;
        if (sscanf(date_buffer, "%d/%d/%d", &day, &month, &year) != 3) {
            return error_msg("Input invalid. Formatul datei trebuie sa fie DD/MM/YYYY\n");
        }
        
        if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900) {
            return error_msg("Input invalid. Data invalida\n");
        }

        Hall *hall_to_reserve = NULL;
        for(Hall *tmp = ls_halls->head; tmp != NULL; tmp = tmp->next) {
            if(strcmp(hall_name_buffer, tmp->hall_name) == 0) {
                hall_to_reserve = tmp;
                break;
            }
        }

        if(hall_to_reserve == NULL) {
            return error_msg("Nu exista sala cu numele introdus\n");
        }

        if(hall_to_reserve->is_available == false) {
            return error_msg("Sala este deja rezervata\n");
        }

        add_reservation(ls_reservations, ls_halls, hall_name_buffer, hour, day, month, year);
        
        return success_msg("Rezervarea a fost adaugata cu succes\n", true);
    }
    return INPUT_ERROR;
}

InputResult cancel_reservation_parsing(ReservationsList *ls_reservations, HallsList *ls_halls) {
    char input[256];
    char id_buffer[256];
    char extra[256];

    if(fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        if(strcmp(input, "x") == 0) {
            return INPUT_GO_BACK;
        }

        int cnt_parsed_items = sscanf(input, "%s %s", id_buffer, extra);
        // Verifica validitatea inputului
        if(cnt_parsed_items != 1) {
            return error_msg("Input invalid. Expected input: <ID>\n");
        }

        // Verifica daca ID-ul este numar natural
        if(is_pure_number(id_buffer) == false) {
            return error_msg("Input invalid. <ID> trebuie sa fie un numar natural\n");
        }
        int id = atoi(id_buffer);

        if(id > ls_reservations->size || id < 1) {
            char error_message[100];
            snprintf(error_message, sizeof(error_message), "Rezervarea cu ID-ul %d nu exista\n", id);
            return error_msg(error_message);
        }

        cancel_reservation(ls_reservations, ls_halls, id);

        return success_msg("Rezervarea a fost anulata cu succes\n", true);
    }
    return INPUT_ERROR;
}
