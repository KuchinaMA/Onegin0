#ifndef PRINTRES_H_INCLUDED
#define PRINTRES_H_INCLUDED

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

<<<<<<< HEAD
=======
// #include "TXLib.h"
>>>>>>> 4b89daa0e36597c8571e5ad7d94b621c48975039

void print_strings(FILE *fresult, LinesData *text, int nLines);
void print_buf(FILE *fresult, char *buf, size_t sz);
void print_result(const char *OutputFile, TextData *textdata);

#endif // PRINTRES_H_INCLUDED
