#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int error_msg(char *msg) {
    if(msg != NULL) {
        printf("%s", msg);
        printf("\nApasa ENTER pentru a continua...");
        getchar();
    }
    return -1;
}

bool is_pure_number(char *buffer) {
    char *endptrname;
    strtol(buffer, &endptrname, 10);
    return *endptrname == '\0';
}

int success_msg(char *msg, bool afiseaza) {
    if(afiseaza == true) { printf("%s", msg); }
    printf("\nApasa ENTER pentru a continua..."); 
    getchar();
    return 0;
}
