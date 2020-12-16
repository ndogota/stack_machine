/*
** ETNA PROJECT, 06/11/2020 by dogota_n and avenia_r
** AbstractVM
** File description:
**      lines.c : processing lines functions
*/

#include "../include/lines.h"
#include "../include/tools.h"

// count the number of line
int lines_count(const char *dump)
{
	int count = 0;
	for (int i = 0; dump[i] != '\0'; i++) {
		if (dump[i] == '\n')
			count++;
	}
	return count + 1;
}

// check if the line is empty
int empty_checker(const char* line)
{
	int count = 1;
	for (int i = 0; line[i] != '\0' && count == 1; i++) {
		if (line[i] != ' ' && line[i] != '\t')
			count = 0;
	}
	return count;
}

// parsing dump on array of line
char** array_parser(const char *dump, int count_line)
{
	char** array_of_lines = (char **) malloc(lines_count(dump) * sizeof(char *));

	for (int i = 0, j = 0, lines_i = 0; dump[i] != '\0'; i++, lines_i++) {
		// discovering the length of the line
		for (; dump[i] != '\n' && dump[i] != '\0'; i++, j++);

		// malloc the line
		char* line = (char*) malloc((j + 1) * sizeof(char*));

		// dumping data
		for (int k = 0; j > 0; j--, k++)
			line[k] = dump[i - j];

		// saving line
		array_of_lines[lines_i] = line;
	}
	return array_of_lines;
}

// parsing line into simplified version (removing space and tab)
char* line_parser(const char *line, char* big_word)
{
	int j = 0;
	int i = 0;
	int k = 0;
	int comment = 0;

	// count the number of usable character on line
	for (; line[i] != '\0'; i++)
		for (; line[i] != ' ' && line[i] != '\t' && line[i] != '\0'; i++, j++)
			if (line[i] == ';')
				break;

	// malloc the parsed line
	char* line_parsed = (char*) malloc((j + 1) * sizeof(char));

	// dumping usual characters
	for (i = 0; line[i] != '\0'; i++)
		for (; line[i] != ' ' && line[i] != '\t' && line[i] != '\0' && comment == 0; i++, k++)
			if (line[i] == ';')
				comment = 1;
			else
				line_parsed[k] = line[i];

	return line_parsed;
}
