#include <stdio.h>
#include <assert.h>

#include "ReadData.h"

int size_of_file(FILE *fp) {

    assert(fp != NULL);

    fseek(fp, 0, SEEK_END);
<<<<<<< HEAD
    int sz = (int)ftell(fp);
=======
    int sz = ftell(fp);     // WARNING: ftell returns long int!
>>>>>>> 4b89daa0e36597c8571e5ad7d94b621c48975039
    fseek(fp, 0, SEEK_SET);

    return sz;
}


int number_of_symbs(const char *buf, size_t len, char symb) {

    assert(buf != NULL);

    int nSymbs = 0;

    for (size_t i = 0; i < len; ++i) {

        if (buf[i] == symb) {
            nSymbs ++;
        }
    }

    return nSymbs;
}


<<<<<<< HEAD
LinesData *create_pointer_arr(char *buf, size_t sz, int nLines) {

    assert(buf != NULL);
    assert(nLines >= 0);

    LinesData *text = (LinesData*) calloc(2*nLines, sizeof(LinesData));

    for(int i = 0; i < nLines; i++) {
        (text[i]).pointer = NULL;
=======
LinesData *create_pointer_arr(char *buf, int sz, int nLines) {
    LinesData *text = (LinesData*) calloc(2*nLines, sizeof(LinesData)); // why 2 * nLines, we have precise quantity of lines from file...
    for(int i = 0; i < nLines; i++) {                                   // i can guess the reason is in going out of bounds, but it is
        (text[i]).pointer = NULL;                                       // line 35 which is responsible for that
>>>>>>> 4b89daa0e36597c8571e5ad7d94b621c48975039
        (text[i]).len = 0;
    }

    (text[0]).pointer = buf;
<<<<<<< HEAD
    int line = 1;

    for(size_t i = 0; i < sz; ++i) {
=======
    int line = 1;                                                       
    for(int i = 0; i < sz; ++i) {
>>>>>>> 4b89daa0e36597c8571e5ad7d94b621c48975039
        if (buf[i] == '\n') {
            buf[i] = '\0';
            (text[line]).pointer = buf + i + 1;                                         // think about value of line variable when we reach the last '\n';
                                                                                        // will it be inside bounds of array *text, but with length nLines? 
            (text[line - 1]).len = (text[line]).pointer - (text[line - 1]).pointer;     // WARNING: pointer difference is long int type!
            line ++;
        }
    }
    //printf("%d", line);
    return text;
}


char *read_data_from_file(FILE *fp, size_t sz) {

    if (fp == NULL) {
        printf("There's no file with text of poem\n");  // to stderr! and also return from this func with an error, e.g. NULL
    }

<<<<<<< HEAD
    char *buf = (char*) calloc(sz + 1, sizeof(char));
    assert(buf != 0);

    size_t nRead = fread(buf, sizeof(char), sz, fp);
    assert (nRead <= sz);

    //printf("%d %d\n", nRead, sz);

    buf[nRead] = '\n';
=======
    char *buf = (char*) calloc(sz + 1, sizeof(char));   // check if memory was allocated successfully, because there can be failure!

    int nRead = fread(buf, sizeof(char), sz, fp);       // WARNING: fread returns size_t!
    assert (nRead <= sz);

    buf[nRead - 1] = '\n';                              // hey, buf[nRead - 1] is the last read symbol, it might be a letter from the last string!
>>>>>>> 4b89daa0e36597c8571e5ad7d94b621c48975039

    return buf;
}


void read_from_file(const char *InputFile, TextData *textdata) {
    // asserts of pointer arguments, and not only in this function!

<<<<<<< HEAD
    FILE *finput = fopen(InputFile , "rb" );
=======
    FILE *finput = fopen(InputFile , "r" );
    // at least assert on fopen result, but better processing an error somehow (return error code, printf error, etc.)
>>>>>>> 4b89daa0e36597c8571e5ad7d94b621c48975039

    textdata->sz = size_of_file(finput);
    textdata->buf = read_data_from_file(finput, textdata->sz);  // do you notice you pass a lot of textdata->... to different functions?
                                                                // no need, why not just passing textdata? you'll even obtain return value
    fclose(finput);                                             // for something else instead of using it for assignment textdata->... = *func* :)

    textdata->nLines = number_of_symbs(textdata->buf, textdata->sz, '\n');  
    if (textdata->buf[textdata->sz - 1] != '\n') {              // but on line 55 we put '\n' at the end, if does not make sense
        textdata->nLines ++;
    }

    textdata->text = create_pointer_arr(textdata->buf, textdata->sz, textdata->nLines);
}
