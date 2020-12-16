/*
** ETNA PROJECT, 06/11/2020 by dogota_n and avenia_r
** AbstractVM
** File description:
**      lines.h headers for lines.c functions
*/

#include <stdlib.h>

// lines syntax processing functions
int lines_count(const char *dump);
int empty_checker(const char* line);
char** array_parser(const char *dump, int count_line);
char* line_parser(const char *line, char* big_word);