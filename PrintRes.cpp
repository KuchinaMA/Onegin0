#include <stdio.h>
#include <assert.h>

#include "ReadData.h"
#include "PrintRes.h"
#include "Sort.h"

void print_strings(FILE *fresult, LinesData *text, int nLines) {

    assert(fresult != NULL);
    assert(text != NULL);
    assert(nLines >= 0);

    for (int i = 0; i < nLines; ++i) {
        fprintf(fresult, "%s\n", (text[i]).pointer);
    }
}


void print_buf(FILE *fresult, char *buf, size_t sz) {

    assert(fresult != NULL);
    assert(buf != NULL);

    for (size_t i = 0; i < sz; ++i) {

        if (buf[i] == '\0') {
<<<<<<< HEAD
            fputc('\n', fresult);
        }

=======
            fprintf(fresult, "\n");     // why massive fprintf function for printing one tiny symbol?
        }                               // moreover, you have fputc in line 21 :)
>>>>>>> 4b89daa0e36597c8571e5ad7d94b621c48975039
        else {
            fputc(buf[i], fresult);     
        }                               // OPTIONAL, nice function refactoring idea: you are compelled to output buffer symbol by symbol
    }                                   // due to impossibility to replace all '\0' to '\n' at once... but do we need that?
}                                       // maybe we can use '\0' to our advantage? look, we can easily output first string: fprintf("%s\n", buf);,
                                        // but then we are to find a position where this outputted string ends in buffer...
                                        // do you know any way to do that via fprintf/printf/...? somehow get information about how many symbols
                                        // fprintf/printf/... has written?

void print_result(const char *OutputFile, TextData *textdata) {

    FILE *fresult = fopen(OutputFile , "wb" );

    assert(fresult != NULL);

<<<<<<< HEAD
    fprintf(fresult, "Сортировка строк в алфавитном порядке\n\n");
    quick_sort(textdata->text, 0, textdata->sz - 1, comp_lines_straight);
    //qsort(textdata->text, textdata->nLines, sizeof(LinesData), comp_lines_straight);
=======
    fprintf(fresult, "пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅ пїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅ\n\n");
    sort_straight(textdata->text, textdata->nLines);
    //quick_sort(text, 0, nLines - 1);
>>>>>>> 4b89daa0e36597c8571e5ad7d94b621c48975039
    print_strings(fresult, textdata->text, textdata->nLines);
    fprintf(fresult, "\n\n");

    fprintf(fresult, "--------------------------------------------------------------------------------------------------\n\n");
<<<<<<< HEAD
    fprintf(fresult, "Обратная сортировка\n\n");
    qsort(textdata->text, textdata->nLines, sizeof(LinesData), comp_lines_reverse);
=======
    fprintf(fresult, "пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ\n\n");
    sort_reverse(textdata->text, textdata->nLines);
>>>>>>> 4b89daa0e36597c8571e5ad7d94b621c48975039
    print_strings(fresult, textdata->text, textdata->nLines);
    fprintf(fresult, "\n\n");

    fprintf(fresult, "--------------------------------------------------------------------------------------------------\n\n");
    fprintf(fresult, "пїЅпїЅпїЅпїЅпїЅ пїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅ\n\n");
    print_buf(fresult, textdata->buf, textdata->sz);

    fclose(fresult);
}
