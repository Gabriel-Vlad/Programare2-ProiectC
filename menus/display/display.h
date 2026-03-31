#ifndef DISPLAY_H
#define DISPLAY_H

// Printeaza o linie de separator formata din '-'
// Exemplu: |------|------------|------------|
void print_separator(int col_count, int *col_widths);

// Printeaza un rand de tabel cu coloane aliniate
// Exemplu: | 1    | SalaA      | 100        |
void print_row(int col_count, int *col_widths, char **values);

// Printeaza header-ul tabelului (separator + nume coloane + separator)
void print_table_header(int col_count, int *col_widths, char **headers);

#endif
