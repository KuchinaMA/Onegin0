#include <stdio.h>

#include "ReadData.h"
#include "PrintRes.h"
#include "Sort.h"
#include "Free.h"


int main() {

    TextData textdata = {0, 0, 0, 0};

    read_from_file("OneginEng.txt", &textdata);

    print_result("OneginResult.txt", &textdata);

    free_all(textdata.buf, textdata.text);

    return 0;
}




