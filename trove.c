//
// CITS2002 Project 2 2022
// Student1: 23058262 Nguyen Nathan 50
// Student2: 23057892 Chambers Monti 50
//
#include "trove.h"

#define	OPTLIST "bf:l:,ru"
#define DEFAULT_VALUE 4

int main(int argc, char *argv[])
{
    int opt;
    int value  = DEFAULT_VALUE;
    char *filenm = NULL;
    char *name = argv[argc - 1];
    bool TypeFlag = false; //  0 = Build/Modify, 1 = Search
    opterr	= 0;

    // Interpreting Opt Commands
    while((opt = getopt(argc, argv, OPTLIST)) != -1)   {
//  Building Trove File
        if(opt == 'b') {
            printf("Building Trove File\n");
            build(name);
        }
//  Provide Name For Trove File
        else if(opt == 'f') {
            filenm  =  strdup(optarg);
            printf("File Name Provided = %s\n", filenm);
            if (argv[3] == name) {
                TypeFlag = true;
            }
        }
//  Adding Specific Word Lengths To Trove File
        else if(opt == 'l') {
            value = atoi(optarg);
            //CURRENT ISSUE NEED TO RETURN VALUE
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

// For Debugging Determining Mode
    if (TypeFlag == true) {
        printf("MODE: Search\n");
    } else {
        printf("MODE: Build/Modify\n");
    }
    return 0;
}