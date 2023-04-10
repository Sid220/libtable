#include <stdio.h>
#include "colours.h"
#include "string.h"
#include "table.h"



int main() {
    char *strings[] = {"Hello", "world", "how", "are", "you"};
    char data[2][5][100] = {
            {"hi",  "hey", "joe", "34", "hi"},
            {"dsa", "asd", "23",  "\0", "\0"}
    };
    int length = 5;  // calculate the length of the array

    printTable(strings, 2, 5, data, Default);  // call the function to print the strings


    printf("\n");

    char *header[] = {"DEVICE", "MOUNTED AS", "STORAGE"};
    char storage[4][3][100] = {
            {"/dev/sdb1", "/mount/asd",  "45%"},
            {"/dev/sdb2", "/mount/sa3d", "46%"},
            {"/dev/sdb3", "/mount/std",  "99%"},
            {"/dev/sdb4", "/mount/sadd", "42%"},
    };
    printTable(header, 4, 3, storage, Default);

    printTable(header, 4, 3, storage, Default_Colour);

    printTable(header, 4, 3, storage, Basic);

    printTable(header, 4, 3, storage, Basic_Colour);

    printTable(header, 4, 3, storage, Minimalist);
    return 0;
}

