#define _CRT_SECURE_NO_WARNINGS
#include "halls_input.h"
#include "../utils/utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> 

int add_hall_parsing(ListSali *ls_sali) {
    char input[256];
    char hall_name_buffer[100];
    char availability_buffer[50];
    char capacity_buffer[50];
    char extra[256];

    if(fgets(input, sizeof(input), stdin) != NULL) {
        // Check if user chooses to go back
        input[strcspn(input, "\n")] = '\0';
        if(strcmp(input, "x") == 0) { return 1; }

        int cnt_parsed_items = sscanf(input, "%s %s %s %s", hall_name_buffer, capacity_buffer, availability_buffer, extra);
        // Check if the input is valid
        if(cnt_parsed_items != 3) {
            return error_msg("Input invalid. Expected input: <nume_sala> <capacitate> <disponibilitate>\n");
        }
        // Check if <hall_name> is purely a number
        if(is_pure_number(hall_name_buffer) == true) {
            return error_msg("Input invalid. <hall_name> cannot be a pure number");
        }
        // Check if <capacity> is not a number         
        if(is_pure_number(capacity_buffer) == false) {
            return error_msg("Input invalid. <capacity> has to be a natu");
        }
        // Check if <availability> is a valid option
        if(strcmp(availability_buffer, "Y") != 0 && strcmp(availability_buffer, "N") != 0) {
            return error_msg("Input invalid. <disponibilitate> can only be Y/N\n");
        }

        int capacity = atoi(capacity_buffer);
        if(capacity < 0) {
            return error_msg("Input invalid. <capacitate> trebuie sa fie strict pozitiva");
        }
        
        // Parse from string to bool
        bool isAvailable = strcmp(availability_buffer, "N") == 0 ? false : true;

        add_hall(ls_sali, hall_name_buffer, capacity, isAvailable);

        success_msg("Sala a fost adaugata cu succes\n", true);
    }
    return -1;
}

int remove_hall_parsing(ListSali *ls_sali, ListRezervari *ls_rez) {
    char input[256];
    char id_buffer[256];
    char extra[256];

    if(fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        if(strcmp(input, "x") == 0) {
            return 1;
        }

        int cnt_parsed_items = sscanf(input, "%s %s", id_buffer, extra);
        // Check if the input is valid
        if(cnt_parsed_items != 1) {
            return error_msg("Input invalid. Expected input: <ID>\n");
        }

        // Check if <ID> is a natural number
        if(is_pure_number(id_buffer) == false) {
            return error_msg("Input invalid. <ID> trebuie sa fie un numar natural\n");
        }
        int id = atoi(id_buffer);

        if(id > ls_sali->size || id < 1) {
            char error_message[100];
            snprintf(error_message, sizeof(error_message), "Sala cu ID-ul %d nu exista\n", id);
            return error_msg(error_message);
        }

        remove_hall(ls_sali, ls_rez, id);

        return success_msg("Sala a fost stearsa cu succes\n", true);
    }
    return -1;
}

int search_hall_by_name_parsing(ListSali *ls_sali) {
    char input[256];
    char hall_name_buffer[100];
    char extra[256];

    if(fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        if(strcmp(input, "x") == 0) { return 1; }

        int cnt_parsed_items = sscanf(input, "%s %s", hall_name_buffer, extra);
        if(cnt_parsed_items != 1) {
            return error_msg("Input invalid. Expected input: <hall_name>\n");
        }

        if(is_pure_number(hall_name_buffer) == true) {
            return error_msg("Input invalid. <nume_sala> nu poate fi un numar\n");
        }

        find_hall_by_name(ls_sali, hall_name_buffer);

        return success_msg("", true);
    }
    return -1;
}

// TODO implement to return multiple halls
int search_hall_by_capacity_parsing(ListSali *ls_sali) {
    char input[256];
    char capacity_buffer[100];
    char extra[256];

    if(fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        if(strcmp(input, "x") == 0) { return 1; }

        int cnt_parsed_items = sscanf(input, "%s %s", capacity_buffer, extra);
        if(cnt_parsed_items != 1) {
            return error_msg("Input invalid. Expected input: <capacity>\n");
        }

        if(is_pure_number(capacity_buffer) == false) {
            return error_msg("Input invalid. <capacity> trebuie sa fie un numar natural\n");
        }

        int capacity = atoi(capacity_buffer);

        find_hall_by_capacity(ls_sali, capacity);

        return success_msg("", true);
    }
    return -1;
}

// TODO implement to return multiple halls
int search_hall_by_availability_parsing(ListSali *ls_sali) {
    char input[256];
    char availability_buffer[100];
    char extra[256];

    if(fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        if(strcmp(input, "x") == 0) { return 1; }

        int cnt_parsed_items = sscanf(input, "%s %s", availability_buffer, extra);
        if(cnt_parsed_items != 1) {
            return error_msg("Input invalid. Expected input: <availability>\n");
        }

        if(strcmp(availability_buffer, "Y") != 0 && strcmp(availability_buffer, "N") != 0) {
            return error_msg("Input invalid. <availability> poate fi Y/N\n");
        }

        int availability = strcmp(availability_buffer, "Y") == 0 ? true : false;

        find_hall_by_availability(ls_sali, availability);

        return success_msg("", true);
    }
    return -1;
}