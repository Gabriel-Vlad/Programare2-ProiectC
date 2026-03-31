#define _CRT_SECURE_NO_WARNINGS
#include "rezervations_input.h"
#include "../utils/utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int add_rezervation_parsing(ListRezervari *ls_rez, ListSali *ls_sali) {
    char input[256];
    char hall_name_buffer[100];
    char ora_buffer[50];
    char data_buffer[50];
    char extra[256];

    if(fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        if(strcmp(input, "x") == 0) { return 1; }

        int cnt_parsed_items = sscanf(input, "%s %s %s %s", hall_name_buffer, ora_buffer, data_buffer, extra);
        
        if (cnt_parsed_items != 3) {
            return error_msg("Input invalid. Input preconizat: <nume_sala> <ora> <DD/MM/YYYY>\n");
        }

        if (is_pure_number(hall_name_buffer) == true) {
            return error_msg("Input invalid. <nume_sala> nu poate fi un numar\n");
        }

        if (is_pure_number(ora_buffer) == false) {
            return error_msg("Input invalid. <ora> trebuie sa fie un numar natural\n");
        }
        
        int ora = atoi(ora_buffer);
        if (ora < 0 || ora > 23) {
            return error_msg("Input invalid. <ora> trebuie sa fie intre 0 si 23\n");
        }

        int zi, luna, an;
        if (sscanf(data_buffer, "%d/%d/%d", &zi, &luna, &an) != 3) {
            return error_msg("Input invalid. Formatul datei trebuie sa fie DD/MM/YYYY\n");
        }
        
        if (zi < 1 || zi > 31 || luna < 1 || luna > 12 || an < 1900) {
            return error_msg("Input invalid. Data invalida\n");
        }

        Sala *hall_to_reserve = NULL;
        for(Sala *tmp = ls_sali->head; tmp != NULL; tmp = tmp->next) {
            if(strcmp(hall_name_buffer, tmp->nume_sala) == 0) {
                hall_to_reserve = tmp;
                break;
            }
        }

        if(hall_to_reserve == NULL) {
            return error_msg("Nu exista sala cu numele introdus\n");
        }

        if(hall_to_reserve->esteDisponibila == false) {
            return error_msg("Sala este deja rezervata\n");
        }

        add_rezervation(ls_rez, ls_sali, hall_name_buffer, ora, zi, luna, an);
        
        return success_msg("Rezervarea a fost adaugata cu succes\n", true);
    }
    return -1;
}

int cancel_rezervation_parsing(ListRezervari *ls_rez, ListSali *ls_sali) {
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

        if(id > ls_rez->size || id < 1) {
            char error_message[100];
            snprintf(error_message, sizeof(error_message), "Rezervarea cu ID-ul %d nu exista\n", id);
            return error_msg(error_message);
        }

        cancel_rezervation(ls_rez, ls_sali, id);

        return success_msg("Rezervarea a fost anulata cu succes\n", true);
    }
    return -1;
}
