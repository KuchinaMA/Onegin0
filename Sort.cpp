#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Sort.h"


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
        if (i1 > end_1 && i2 > end_2) {
            return 0;
        }
        else if (i1 > end_1 && i2 <= end_2) {
            return -1;
        }
        else if (i1 <= end_1 && i2 > end_2){
            return 1;
        }
    }
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
        if (i1 < 0 && i2 < 0) {
            return 0;
        }
        else if (i1 < 0 && i2 >= 0) {
            return -1;
        }
        else if (i2 < 0 && i1 >= 0) {
            return 1;
        }
    }
}

void quick_sort(LinesData *data, int begining, int ending, int (*comparator) (const void* line1, const void* line2)) {

    assert(data != 0);
    assert(begining >= 0);

    if (begining < ending) {

        int middle = partition(data, begining, ending, comparator);
        quick_sort(data, begining, middle, comparator);
        quick_sort(data, middle + 1, ending, comparator);
    }
}


int partition(LinesData *data, int begining, int ending, int (*comparator) (const void* line1, const void* line2)) {

    assert(data != 0);
    assert(begining >= 0);

    int left = begining;
    int right = ending;
    int middle = left + (right - left) / 2;
    LinesData midElem = data[middle];

    while (left <= right) {

        while (comparator(&midElem, &data[left]) > 0) {
            left++;
        }

        while (comparator(&data[right], &midElem) > 0) {
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


void swap_elems(LinesData *data, int a, int b) {

    assert(data != 0);
    assert(a >= 0);
    assert(b >= 0);

    LinesData tmp = data[a];
    data[a] = data[b];
    data[b] = tmp;
}
