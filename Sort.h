#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

<<<<<<< HEAD
=======
// #include "TXLib.h"
>>>>>>> 4b89daa0e36597c8571e5ad7d94b621c48975039
#include "ReadData.h"

int comp_lines_straight(const void *line1, const void *line2);

int comp_lines_reverse(const void *line1, const void *line2);

void quick_sort(LinesData data[], int begining, int ending, int (*comparator) (const void* line1, const void* line2));
int partition(LinesData data[], int begining, int ending, int (*comparator) (const void* line1, const void* line2));
void swap_elems(LinesData data[], int a, int b);

#endif // SORT_H_INCLUDED
