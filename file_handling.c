

#include "trove.h"

FILE *file_opener(char filename[]) {
    /* Returns the opened file pointer */

    FILE *fp = fopen(filename, "r");

    if(fp == NULL) {
        fprintf(stderr, "cannot open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }
    return fp;
}

void file_reader(FILE *file){
    /* Returns number of unique words and  */
    char line[LINE_SIZE];

    // Reading file line by line and putting contents into array of structures
    while(fgets(line, sizeof line, file) != NULL){
        printf("Line: %s\n", line);
    }
}
