#ifndef FREE_H_INCLUDED
#define FREE_H_INCLUDED

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "TXLib.h"
#include "ReadData.h"

void free_all(char *buf, LinesData *text);

#endif // FREE_H_INCLUDED
