#define _CRT_SECURE_NO_WARNINGS
#include "menus/input/halls/halls_input.h"
#include "menus/input/utils/utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> 

InputResult add_hall_parsing(HallsList *ls_halls) {
    char input[256];
    char hall_name_buffer[100];
    char availability_buffer[50];
    char capacity_buffer[50];
    char extra[256];

    if(fgets(input, sizeof(input), stdin) != NULL) {
        // Verifica daca utilizatorul vrea sa se intoarca
        input[strcspn(input, "\n")] = '\0';
        if(strcmp(input, "x") == 0) { return INPUT_GO_BACK; }

        int cnt_parsed_items = sscanf(input, "%s %s %s %s", hall_name_buffer, capacity_buffer, availability_buffer, extra);
        // Verifica validitatea inputului
        if(cnt_parsed_items != 3) {
            return error_msg("Input invalid. Input preconizat: <nume_sala> <capacitate> <disponibilitate>\n");
        }
        // Verifica daca numele salii este un numar
        if(is_pure_number(hall_name_buffer) == true) {
            return error_msg("Input invalid. <nume_sala> nu poate fi un numar\n");
        }
        // Verifica daca capacitatea nu este numar         
        if(is_pure_number(capacity_buffer) == false) {
            return error_msg("Input invalid. <capacitate> trebuie sa fie un numar natural\n");
        }
        // Verifica disponibilitatea
        if(strcmp(availability_buffer, "Y") != 0 && strcmp(availability_buffer, "N") != 0) {
            return error_msg("Input invalid. <disponibilitate> poate fi doar Y/N\n");
        }

        int capacity = atoi(capacity_buffer);
        if(capacity < 0) {
            return error_msg("Input invalid. <capacitate> trebuie sa fie strict pozitiva\n");
        }
        
        // Conversie din string in bool
        bool is_available = strcmp(availability_buffer, "N") == 0 ? false : true;

        add_hall(ls_halls, hall_name_buffer, capacity, is_available);

        success_msg("Sala a fost adaugata cu succes\n", true);
    }
    return INPUT_ERROR;
}

InputResult remove_hall_parsing(HallsList *ls_halls, ReservationsList *ls_reservations) {
    char input[256];
    char id_buffer[256];
    char extra[256];

    if(fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        if(strcmp(input, "x") == 0) {
            return 1;
        }

        int cnt_parsed_items = sscanf(input, "%s %s", id_buffer, extra);
        // Verifica validitatea inputului
        if(cnt_parsed_items != 1) {
            return error_msg("Input invalid. Input preconizat: <ID>\n");
        }

        // Verifica daca ID-ul este numar natural
        if(is_pure_number(id_buffer) == false) {
            return error_msg("Input invalid. <ID> trebuie sa fie un numar natural\n");
        }
        int id = atoi(id_buffer);

        if(id > ls_halls->size || id < 1) {
            char error_message[100];
            snprintf(error_message, sizeof(error_message), "Sala cu ID-ul %d nu exista\n", id);
            return error_msg(error_message);
        }

        remove_hall(ls_halls, ls_reservations, id);

        return success_msg("Sala a fost stearsa cu succes\n", true);
    }
    return INPUT_ERROR;
}

InputResult search_hall_by_name_parsing(HallsList *ls_halls) {
    char input[256];
    char hall_name_buffer[100];
    char extra[256];

    if(fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        if(strcmp(input, "x") == 0) { return INPUT_GO_BACK; }

        int cnt_parsed_items = sscanf(input, "%s %s", hall_name_buffer, extra);
        if(cnt_parsed_items != 1) {
            return error_msg("Input invalid. Input preconizat: <nume_sala>\n");
        }

        if(is_pure_number(hall_name_buffer) == true) {
            return error_msg("Input invalid. <nume_sala> nu poate fi un numar\n");
        }

        find_hall_by_name(ls_halls, hall_name_buffer);

        return success_msg("", true);
    }
    return INPUT_ERROR;
}

InputResult search_hall_by_capacity_parsing(HallsList *ls_halls) {
    char input[256];
    char capacity_buffer[100];
    char extra[256];

    if(fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        if(strcmp(input, "x") == 0) { return INPUT_GO_BACK; }

        int cnt_parsed_items = sscanf(input, "%s %s", capacity_buffer, extra);
        if(cnt_parsed_items != 1) {
            return error_msg("Input invalid. Input preconizat: <capacitate>\n");
        }

        if(is_pure_number(capacity_buffer) == false) {
            return error_msg("Input invalid. <capacitate> trebuie sa fie un numar natural\n");
        }

        int capacity = atoi(capacity_buffer);

        find_hall_by_capacity(ls_halls, capacity);

        return success_msg("", true);
    }
    return INPUT_ERROR;
}

InputResult search_hall_by_availability_parsing(HallsList *ls_halls) {
    char input[256];
    char availability_buffer[100];
    char extra[256];

    if(fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        if(strcmp(input, "x") == 0) { return INPUT_GO_BACK; }

        int cnt_parsed_items = sscanf(input, "%s %s", availability_buffer, extra);
        if(cnt_parsed_items != 1) {
            return error_msg("Input invalid. Input preconizat: <disponibilitate>\n");
        }

        if(strcmp(availability_buffer, "Y") != 0 && strcmp(availability_buffer, "N") != 0) {
            return error_msg("Input invalid. <disponibilitate> poate fi Y/N\n");
        }

        bool availability = strcmp(availability_buffer, "Y") == 0 ? true : false;

        find_hall_by_availability(ls_halls, availability);

        return success_msg("", true);
    }
    return INPUT_ERROR;
}