#define _CRT_SECURE_NO_WARNINGS
#include "includes.h"

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

    FILE *database_halls = fopen("database/halls.txt", "r");
    if(database_halls == NULL) {
        printf("Nu s-a putut deschide sali.txt\n");
        return;
    }

    FILE *database_rez = fopen("database/reservations.txt", "r");
    if(database_rez == NULL) {
        printf("Nu s-a putu deschide rezervari.txt\n");
        return;
    }

    char input[256];

    while(fgets(input, sizeof(input), database_halls) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        char hall_name[100], availability_buffer;;
        int capacity;

        sscanf(input, "%s %d %c", hall_name, &capacity, &availability_buffer);
        bool availability = availability_buffer == 'Y' ? true : false;

        add_hall(&ls_halls, hall_name, capacity, availability);

    }

    while(fgets(input, sizeof(input), database_rez) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        
        char rez_name[100], data_buffer[15];
        int hour,day, month, year;

        sscanf(input, "%s %d %s", rez_name, &hour, data_buffer);
        sscanf(data_buffer, "%d/%d/%d", &day, &month, &year);

        add_reservation(&ls_reservations, &ls_halls, rez_name, hour, day, month, year);
    }

    fclose(database_halls);
    fclose(database_rez);
}

// Salveaza salile in fisier
void save_data_halls() {
    FILE *database_halls = fopen("database/halls.txt", "w");
    if(database_halls == NULL) {
        printf("Nu s-a putut deschide sali.txt\n");
        return;
    }

    for(Hall *tmp = ls_halls.head; tmp != NULL; tmp = tmp->next) {
        char availability = tmp->is_available == true ? 'Y' : 'N';
        fprintf(database_halls, "%s %d %c\n", tmp->hall_name, tmp->capacity, availability); 
    }

    fclose(database_halls);
}

// Salveaza rezervarile in fisier
void save_data_reservations() {
    FILE *database_rez = fopen("database/reservations.txt", "w");
    if(database_rez == NULL) {
        printf("Nu s-a putut deschide rezervari.txt\n");
        return;
    }

    for(Reservation *tmp = ls_reservations.head; tmp != NULL; tmp = tmp->next) {
        char data[20];
        snprintf(data, sizeof(data), "%d/%d/%d", tmp->day, tmp->month, tmp->year);
        fprintf(database_rez, "%s %d %s\n", tmp->hall_name, tmp->hour, data);
    }

    fclose(database_rez);
}