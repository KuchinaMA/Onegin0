#include <stdio.h>
#include <assert.h>

#include "ReadData.h"
#include "PrintRes.h"
#include "Sort.h"

void print_strings(FILE *fresult, LinesData *text, int nLines) {
    for (int i = 0; i < nLines; ++i) {
        fprintf(fresult, "%s\n", (text[i]).pointer);
    }
}


void print_buf(FILE *fresult, char *buf, int sz) {
    for (int i = 0; i < sz; ++i) {
        if (buf[i] == '\0') {
            fprintf(fresult, "\n");     // why massive fprintf function for printing one tiny symbol?
        }                               // moreover, you have fputc in line 21 :)
        else {
            fputc(buf[i], fresult);     
        }                               // OPTIONAL, nice function refactoring idea: you are compelled to output buffer symbol by symbol
    }                                   // due to impossibility to replace all '\0' to '\n' at once... but do we need that?
}                                       // maybe we can use '\0' to our advantage? look, we can easily output first string: fprintf("%s\n", buf);,
                                        // but then we are to find a position where this outputted string ends in buffer...
                                        // do you know any way to do that via fprintf/printf/...? somehow get information about how many symbols
                                        // fprintf/printf/... has written?

void print_result(const char *OutputFile, TextData *textdata) {

    FILE *fresult = fopen(OutputFile , "w" );

    fprintf(fresult, "���������� ����� � ���������� �������\n\n");
    sort_straight(textdata->text, textdata->nLines);
    //quick_sort(text, 0, nLines - 1);
    print_strings(fresult, textdata->text, textdata->nLines);
    fprintf(fresult, "\n\n");

    fprintf(fresult, "--------------------------------------------------------------------------------------------------\n\n");
    fprintf(fresult, "�������� ����������\n\n");
    sort_reverse(textdata->text, textdata->nLines);
    print_strings(fresult, textdata->text, textdata->nLines);
    fprintf(fresult, "\n\n");

    fprintf(fresult, "--------------------------------------------------------------------------------------------------\n\n");
    fprintf(fresult, "����� � ������������ ����\n\n");
    print_buf(fresult, textdata->buf, textdata->sz);

    fclose(fresult);
}
