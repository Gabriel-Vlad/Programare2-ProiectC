#include "menus/display/display.h"
#include "menus/colors.h"
#include <stdio.h>

void print_separator(int col_count, int *col_widths) {
    printf(COLOR_TABLE_BRD "|");
    for (int i = 0; i < col_count; i++) {
        for (int j = 0; j < col_widths[i] + 2; j++) {
            printf("-");
        }
        printf("|");
    }
    printf(RESET "\n");
}

void print_row(int col_count, int *col_widths, char **values) {
    printf(COLOR_TABLE_BRD "|" RESET);
    for (int i = 0; i < col_count; i++) {
        printf(COLOR_DATA " %-*s " COLOR_TABLE_BRD "|" RESET, col_widths[i], values[i]);
    }
    printf("\n");
}

void print_table_header(int col_count, int *col_widths, char **headers) {
    printf("\n");
    print_separator(col_count, col_widths);
    printf(COLOR_TABLE_BRD "|" RESET);
    for (int i = 0; i < col_count; i++) {
        printf(COLOR_TABLE_HDR " %-*s " COLOR_TABLE_BRD "|" RESET, col_widths[i], headers[i]);
    }
    printf("\n");
    print_separator(col_count, col_widths);
}
