#include "menus/input/utils/utils.h"
#include "menus/colors.h"
#include <stdio.h>
#include <stdlib.h>

InputResult error_msg(char *msg) {
    if(msg != NULL) {
        printf(COLOR_ERROR "%s" RESET, msg);
        printf(COLOR_INFO "\nApasa ENTER pentru a continua..." RESET);
        getchar();
    }
    return INPUT_ERROR;
}

bool is_pure_number(char *buffer) {
    char *endptrname;
    strtol(buffer, &endptrname, 10);
    return *endptrname == '\0';
}

InputResult success_msg(char *msg, bool display) {
    if(display == true) { printf(COLOR_SUCCESS "%s" RESET, msg); }
    printf(COLOR_INFO "\nApasa ENTER pentru a continua..." RESET); 
    getchar();
    return INPUT_SUCCESS;
}
