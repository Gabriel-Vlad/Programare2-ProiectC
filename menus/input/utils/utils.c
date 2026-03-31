#include "utils.h"
#include "../../colors.h"
#include <stdio.h>
#include <stdlib.h>

int error_msg(char *msg) {
    if(msg != NULL) {
        printf(COLOR_ERROR "%s" RESET, msg);
        printf(COLOR_INFO "\nApasa ENTER pentru a continua..." RESET);
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
    if(afiseaza == true) { printf(COLOR_SUCCESS "%s" RESET, msg); }
    printf(COLOR_INFO "\nApasa ENTER pentru a continua..." RESET); 
    getchar();
    return 0;
}
