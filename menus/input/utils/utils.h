#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

typedef enum {
    INPUT_ERROR = -1,
    INPUT_SUCCESS = 0,
    INPUT_GO_BACK = 1
} InputResult;

InputResult error_msg(char *msg);
bool is_pure_number(char *buffer);
InputResult success_msg(char *msg, bool display);

#endif
