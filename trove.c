//
// CITS2002 Project 2 2022
// Student1: 23058262 Nguyen Nathan 50
// Student2: 23057892 Chambers Monti 50
//

#include <stdio.h>
#include <stdlib.h>
#include "trove.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int count = 0;

void trove(void) {
    /* Trove computation */
}

int main(int argc, char *argv[])
{
    /* Maximum 5 arguments */
    if (argc > 5) {
        fprintf(stderr, "Usage: %s argument\n", argv[0]);
        exit(EXIT_FAILURE);
    } else if (argc ) {
        printf("Hello World\n");
        exit(EXIT_SUCCESS);
        return 0;
    }
}