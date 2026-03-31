#include "display.h"
#include <stdio.h>

void print_separator(int col_count, int *col_widths) {
    printf("|");
    for (int i = 0; i < col_count; i++) {
        for (int j = 0; j < col_widths[i] + 2; j++) {
            printf("-");
        }
        printf("|");
    }
    printf("\n");
}

void print_row(int col_count, int *col_widths, char **values) {
    printf("|");
    for (int i = 0; i < col_count; i++) {
        printf(" %-*s |", col_widths[i], values[i]);
    }
    printf("\n");
}

void print_table_header(int col_count, int *col_widths, char **headers) {
    printf("\n");
    print_separator(col_count, col_widths);
    print_row(col_count, col_widths, headers);
    print_separator(col_count, col_widths);
}
