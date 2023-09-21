#include <stdio.h>

<<<<<<< HEAD
=======
// #include "TXLib.h"
>>>>>>> 4b89daa0e36597c8571e5ad7d94b621c48975039
#include "ReadData.h"
#include "PrintRes.h"
#include "Sort.h"
#include "Free.h"


int main() {

    TextData textdata = {0, 0, 0, 0};

    read_from_file("OneginEng.txt", &textdata); // hey, why not reading from file with custom file name?
                                                // just get name from console/command line into buffer and open file with that name :)
    print_result("OneginResult.txt", &textdata);

    free_all(textdata.buf, textdata.text);

    return 0;
}

