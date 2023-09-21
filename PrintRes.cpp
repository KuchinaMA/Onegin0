#include <stdio.h>
#include <assert.h>

#include "TXLib.h"
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
            fputc('\n', fresult);
        }

        else {
            fputc(buf[i], fresult);
        }
    }
}

void print_result(const char *OutputFile, TextData *textdata) {

    FILE *fresult = fopen(OutputFile , "wb" );

    assert(fresult != NULL);

    fprintf(fresult, "Сортировка строк в алфавитном порядке\n\n");
    quick_sort(textdata->text, 0, textdata->sz - 1, comp_lines_straight);
    //qsort(textdata->text, textdata->nLines, sizeof(LinesData), comp_lines_straight);
    print_strings(fresult, textdata->text, textdata->nLines);
    fprintf(fresult, "\n\n");

    fprintf(fresult, "--------------------------------------------------------------------------------------------------\n\n");
    fprintf(fresult, "Обратная сортировка\n\n");
    qsort(textdata->text, textdata->nLines, sizeof(LinesData), comp_lines_reverse);
    print_strings(fresult, textdata->text, textdata->nLines);
    fprintf(fresult, "\n\n");

    fprintf(fresult, "--------------------------------------------------------------------------------------------------\n\n");
    fprintf(fresult, "Текст в оригинальном виде\n\n");
    print_buf(fresult, textdata->buf, textdata->sz);

    fclose(fresult);
}
