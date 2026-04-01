#define _CRT_SECURE_NO_WARNINGS
#include "database/database.h"
#include "models/halls/halls.h"
#include "models/reservations/reservations.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define HALLS_FILE "database/halls.txt"
#define RESERVATIONS_FILE "database/reservations.txt"

HallsList ls_halls;
ReservationsList ls_reservations;

void init_database() {
    // Initializeaza baza de date
    ls_halls.head = NULL;
    ls_halls.tail = NULL;
    ls_halls.size = 0;

    ls_reservations.head = NULL;
    ls_reservations.tail = NULL;
    ls_reservations.size = 0;
}

// Citeste datele din fisiere
void read_data() {
    init_database();

    FILE *database_halls = fopen(HALLS_FILE, "r");
    if(database_halls == NULL) {
        printf("Nu s-a putut deschide halls.txt\n");
    } else {
        char input[256];
        while(fgets(input, sizeof(input), database_halls) != NULL) {
            input[strcspn(input, "\n")] = '\0';
            char hall_name[100], availability_buffer;
            int capacity;

            if (sscanf(input, "%s %d %c", hall_name, &capacity, &availability_buffer) == 3) {
                bool availability = (availability_buffer == 'Y');
                add_hall(&ls_halls, hall_name, capacity, availability);
            }
        }
        fclose(database_halls);
    }

    FILE *database_rez = fopen(RESERVATIONS_FILE, "r");
    if(database_rez == NULL) {
        printf("Nu s-a putut deschide reservations.txt\n");
    } else {
        char input[256];
        while(fgets(input, sizeof(input), database_rez) != NULL) {
            input[strcspn(input, "\n")] = '\0';
            
            char rez_name[100], data_buffer[15];
            int hour, day, month, year;

            if (sscanf(input, "%s %d %s", rez_name, &hour, data_buffer) == 3) {
                if (sscanf(data_buffer, "%d/%d/%d", &day, &month, &year) == 3) {
                    add_reservation(&ls_reservations, &ls_halls, rez_name, hour, day, month, year);
                }
            }
        }
        fclose(database_rez);
    }
}

// Salveaza salile in fisier
void save_data_halls() {
    FILE *database_halls = fopen(HALLS_FILE, "w");
    if(database_halls == NULL) {
        printf("Nu s-a putut deschide halls.txt pentru salvare\n");
        return;
    }

    for(Hall *tmp = ls_halls.head; tmp != NULL; tmp = tmp->next) {
        char availability = tmp->is_available ? 'Y' : 'N';
        fprintf(database_halls, "%s %d %c\n", tmp->hall_name, tmp->capacity, availability); 
    }

    fclose(database_halls);
}

// Salveaza rezervarile in fisier
void save_data_reservations() {
    FILE *database_rez = fopen(RESERVATIONS_FILE, "w");
    if(database_rez == NULL) {
        printf("Nu s-a putut deschide reservations.txt pentru salvare\n");
        return;
    }

    for(Reservation *tmp = ls_reservations.head; tmp != NULL; tmp = tmp->next) {
        char data[20];
        snprintf(data, sizeof(data), "%d/%d/%d", tmp->day, tmp->month, tmp->year);
        fprintf(database_rez, "%s %d %s\n", tmp->hall_name, tmp->hour, data);
    }

    fclose(database_rez);
}