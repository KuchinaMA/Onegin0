#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Sort.h"

<<<<<<< HEAD
=======
void sort_straight(LinesData *line, int nLines) {
    qsort(line, nLines, sizeof(LinesData), comp_lines_straight);    // do you know that writing variable in sizeof will automatically
}                                                                   // give its type to sizeof without explicitly writing it?
>>>>>>> 4b89daa0e36597c8571e5ad7d94b621c48975039

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

    while (true)    // usually it's better to have condition inside while statement than in while body
    {
        while (i1 <= end_1 && (isalpha(str1[i1]) == 0)) {
            i1++;
        }

        while (i2 <= end_2 && (isalpha(str2[i2]) == 0)) {
            i2++;
        }

        if (tolower(str1[i1]) == tolower(str2[i2])) {   // this condition can be in while statement, i1++ and i2++ can be right
            i1++;                                       // after main while beginning (line 31), both have int type to set them
            i2++;                                       // to -1 at lines 27, 28 and while converts into do while to make at least
        }                                               // one iteration happen

        else if (tolower(str1[i1]) < tolower(str2[i2])) {
            return -1;
        }

        else {
            return 1;
        }
<<<<<<< HEAD
        if (i1 > end_1 && i2 > end_2) {
            return 0;
        }
        else if (i1 > end_1 && i2 <= end_2) {
            return -1;
        }
        else if (i1 <= end_1 && i2 > end_2){
            return 1;
=======
        if (i1 > end_1 || i2 > end_2) {         // better to remove this if
            if (i1 > end_1 && i2 > end_2) {
                return 0;
            }
            else if (i1 > end_1) {              // && (i2 <= end_2)
                return -1;
            }
            else {                              // (i1 <= end_1) && (i2 > end_2)
                return 1;
            }
>>>>>>> 4b89daa0e36597c8571e5ad7d94b621c48975039
        }
    }
}

<<<<<<< HEAD
=======
void sort_reverse(LinesData *line, int nLines) {                // with function on line 9: why not just one function with pointer to function-comparator
    qsort(line, nLines, sizeof(LinesData), comp_lines_reverse); // as an argument instead of two different functions that do exactly the same? copypaste :(
}

>>>>>>> 4b89daa0e36597c8571e5ad7d94b621c48975039

int comp_lines_reverse(const void *line1, const void *line2) {  // similar to comp_lines_straight

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

<<<<<<< HEAD
void quick_sort(LinesData *data, int begining, int ending, int (*comparator) (const void* line1, const void* line2)) {

    assert(data != 0);
    assert(begining >= 0);

    if (begining < ending) {

        int middle = partition(data, begining, ending, comparator);
        quick_sort(data, begining, middle, comparator);
        quick_sort(data, middle + 1, ending, comparator);
=======
void quick_sort(char **data, int begining, int ending) {    // function-comparator as an argument; now you sort not char *, but LinesData!
    if (begining < ending) {                                // i guess after rewriting to structures you didn't use quick_sort :(
        int middle = partition(data, begining, ending);
        quick_sort(data, begining, middle);
        quick_sort(data, middle + 1, ending);
>>>>>>> 4b89daa0e36597c8571e5ad7d94b621c48975039
    }
}


<<<<<<< HEAD
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
=======
int partition(char **data, int begining, int ending) {      // LinesData *data!
    int left = begining;
    int right = ending;
    int middle = (left + right) / 2;    // left + (right - left) / 2 to avoid overflow
    char *midElem = data[middle];
    while (left <= right) {
        while (comp_lines_straight(&midElem, &data[left]) > 0) {    // not hardcoded comp_lines_straight but function-comparator
            left++;                                                 // as an argument of partition function
>>>>>>> 4b89daa0e36597c8571e5ad7d94b621c48975039
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


<<<<<<< HEAD
void swap_elems(LinesData *data, int a, int b) {

    assert(data != 0);
    assert(a >= 0);
    assert(b >= 0);

    LinesData tmp = data[a];
    data[a] = data[b];
=======
void swap_elems(char *data[], int a, int b) {                       // i guess quick_sort does not work, here is the main reason:
    char *tmp = data[a];                                            // now you sort not char *, but LineData; therefore you should
    data[a] = data[b];                                              // swap not only char *, but LineData!
>>>>>>> 4b89daa0e36597c8571e5ad7d94b621c48975039
    data[b] = tmp;
}
