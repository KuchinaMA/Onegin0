#include <stdio.h>
#include <stdlib.h>

#include "Free.h"
#include "ReadData.h"

void free_all(char *buf, LinesData *text) {
    free(buf);
    free(text);
}
