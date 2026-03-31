#ifndef COLORS_H
#define COLORS_H

#define RESET       "\x1b[0m"

// Culori
#define RED         "\x1b[31m"
#define GREEN       "\x1b[32m"
#define YELLOW      "\x1b[33m"
#define WHITE       "\x1b[37m"
#define BOLD_RED    "\x1b[1;31m"
#define BOLD_GREEN  "\x1b[1;32m"
#define BOLD_YELLOW "\x1b[1;33m"
#define BOLD_WHITE  "\x1b[1;37m"

// Semantic
#define COLOR_BORDER    WHITE         // | si ---
#define COLOR_TITLE     BOLD_WHITE    // Titluri meniu
#define COLOR_KEY       GREEN         // [1], [2] - accent vizibil
#define COLOR_TEXT      YELLOW        // Text actiune langa key
#define COLOR_DANGER    RED           // [x] Iesire / Inapoi
#define COLOR_INFO      WHITE         // Instructiuni
#define COLOR_PROMPT    BOLD_GREEN    // "Alege optiunea:"
#define COLOR_ERROR     BOLD_RED      // Erori
#define COLOR_SUCCESS   BOLD_GREEN    // Succes
#define COLOR_WARNING   BOLD_YELLOW   // Avertismente
#define COLOR_TABLE_HDR BOLD_WHITE    // Header tabel
#define COLOR_TABLE_BRD WHITE         // Borduri tabel
#define COLOR_DATA      WHITE         // Date tabel

#endif
