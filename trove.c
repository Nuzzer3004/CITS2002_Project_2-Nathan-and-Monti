//
// CITS2002 Project 2 2022
// Student1: 23058262 Nguyen Nathan 50
// Student2: 23057892 Chambers Monti 50
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

#define	OPTLIST "bf:l:,ru"
#define DEFAULT_VALUE 4

int main(int argc, char *argv[])
{
    int  opt;
    char *filenm = NULL;
    int value  = DEFAULT_VALUE;
    char *name = argv[argc - 1];
    opterr	= 0;

    while((opt = getopt(argc, argv, OPTLIST)) != -1)   {
//  Building Trove File
        if(opt == 'b') {
            printf("Building Trove File\n");
        }
//  Provide Name For Trove File
        else if(opt == 'f') {
            filenm  =  strdup(optarg);
            printf("File Name Provided = %s\n", filenm);
        }
//  Adding Specific Word Lengths To Trove File
        else if(opt == 'l') {
            value  =  atoi(optarg);
            printf("Word Length Provided = %i\n", value);
        }
//  Remove Files
        else if(opt == 'r') {
            printf("Removing '%s' from trove-file\n", name);
        }
//  Updating Files
        else if(opt == 'u') {
            printf("Updating '%s' in trove-file\n", name);
        }
//  OOPS - AN UNKNOWN ARGUMENT
        else {
            argc = -1;
        }
    }
    argc  -= optind;
    argv  += optind;
    return 0;
}