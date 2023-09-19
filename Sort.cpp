#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Sort.h"

void sort_straight(LinesData *line, int nLines) {
    qsort(line, nLines, sizeof(LinesData), comp_lines_straight);
}

int comp_lines_straight(const void *line1, const void *line2) {

    assert(line1 != NULL);
    assert(line2 != NULL);

    LinesData l1 = *(const LinesData*)line1;
    LinesData l2 = *(const LinesData*)line2;

    char *str1 = l1.pointer;
    char *str2 = l2.pointer;

    size_t end_1 = l1.len - 1;
    size_t end_2 = l2.len - 1;

    size_t i1 = 0;
    size_t i2 = 0;

    while (true)
    {
        while (i1 <= end_1 && (isalpha(str1[i1]) == 0)) {
            i1++;
        }

        while (i2 <= end_2 && (isalpha(str2[i2]) == 0)) {
            i2++;
        }

        if (tolower(str1[i1]) == tolower(str2[i2])) {
            i1++;
            i2++;
        }

        else if (tolower(str1[i1]) < tolower(str2[i2])) {
            return -1;
        }

        else {
            return 1;
        }
        if (i1 > end_1 || i2 > end_2) {
            if (i1 > end_1 && i2 > end_2) {
                return 0;
            }
            else if (i1 > end_1) {
                return -1;
            }
            else {
                return 1;
            }
        }
    }
}

void sort_reverse(LinesData *line, int nLines) {
    qsort(line, nLines, sizeof(LinesData), comp_lines_reverse);
}


int comp_lines_reverse(const void *line1, const void *line2) {

    assert(line1 != NULL);
    assert(line2 != NULL);

    LinesData l1 = *(const LinesData*)line1;
    LinesData l2 = *(const LinesData*)line2;

    char *str1 = l1.pointer;
    char *str2 = l2.pointer;

    int i1 = l1.len - 1;
    int i2 = l2.len - 1;


    while (true)
    {
        while (i1 >= 0 && (isalpha(str1[i1]) == 0)) {
            i1--;
        }

        while (i2 >= 0 && (isalpha(str2[i2]) == 0)) {
            i2--;
        }

        if (tolower(str1[i1]) == tolower(str2[i2])) {
            i1--;
            i2--;
        }

        else if (tolower(str1[i1]) < tolower(str2[i2])) {
            return -1;
        }

        else {
            return 1;
        }
        if (i1 < 0 || i2 < 0) {
            if (i1 < 0 && i2 < 0) {
                return 0;
            }
            else if (i1 < 0) {
                return -1;
            }
            else {
                return 1;
            }
        }

    }
}

void quick_sort(char **data, int begining, int ending) {
    if (begining < ending) {
        int middle = partition(data, begining, ending);
        quick_sort(data, begining, middle);
        quick_sort(data, middle + 1, ending);
    }
}


int partition(char **data, int begining, int ending) {
    int left = begining;
    int right = ending;
    int middle = (left + right) / 2;
    char *midElem = data[middle];
    while (left <= right) {
        while (comp_lines_straight(&midElem, &data[left]) > 0) {
            left++;
        }
        while (comp_lines_straight(&data[right], &midElem) > 0) {
            right--;
        }
        if (left >= right) {
            break;
        }
        swap_elems(data, left, right);
        left++;
        right--;
    }
    return right;
}


void swap_elems(char *data[], int a, int b) {
    char *tmp = data[a];
    data[a] = data[b];
    data[b] = tmp;
}
