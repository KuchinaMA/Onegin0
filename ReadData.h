#ifndef READDATA_H_INCLUDED
#define READDATA_H_INCLUDED

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "TXLib.h"

struct LinesData {
    char *pointer;
    int len;
};

struct TextData {
    int sz;
    char *buf;
    int nLines;
    LinesData *text;
};

int size_of_file(FILE *fp);
int number_of_symbs(const char *str, size_t len, char symb);
LinesData *create_pointer_arr(char *buf, int sz, int nLines);
char *read_data_from_file(FILE *fp, int sz);
void read_from_file(const char *InputFile,TextData *textdata);


#endif // READDATA_H_INCLUDED
