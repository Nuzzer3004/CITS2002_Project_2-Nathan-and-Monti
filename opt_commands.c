//
// CITS2002 Project 2 2022
// Student1: 23058262 Nguyen Nathan 50
// Student2: 23057892 Chambers Monti 50
//

#include "trove.h"

#define LINE_SIZE 100

FILE *opener(char filename[]) {
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

void build(char filename[]) {
    FILE *fp = opener(filename);
    file_reader(fp);
}

