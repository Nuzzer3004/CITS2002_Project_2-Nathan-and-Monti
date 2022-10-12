//
// CITS2002 Project 2 2022
// Student1: 23058262 Nguyen Nathan 50
// Student2: 23057892 Chambers Monti 50
//

#include "trove.h"

void usage(char *argv0){
/* Reports the programs synopsis if errors in command-line processing */
    fprintf(stderr, "Usage: %s [-f trovefile] word or\n %s [-f trovefile] [-b | -r | -u] [-l length] filelist", argv0, argv0);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
    /* Receive and validate command-line options & arguments */
    int opt;
    int word_length  = DEFAULT_LENGTH;
    char *trove_file = DEFAULT_FILE;
    char *file_list = NULL;
    bool TypeFlag = true; //  0 = Build/Modify, 1 = Search
    bool BuildFlag = false;
    bool UpdateFlag = false;
    bool RemoveFlag = false;
    opterr	= 0;

    // Interpreting Opt Commands
    while((opt = getopt(argc, argv, OPTLIST)) != -1) {

    // Building Trove File
        if(opt == 'b' || opt == 'u' || opt == 'r') {
            if(!TypeFlag){ // Ensure only one passes
                usage(argv[0]);
            }
            TypeFlag = false;
            if(opt == 'b'){
                BuildFlag = true;
            }
            else if(opt == 'u'){
                UpdateFlag = true;
            }
            else{
                RemoveFlag = true;
            }
        }

    // Provide Name For Trove File
        else if(opt == 'f') {
            trove_file = strdup(optarg);
            printf("File Name Provided = %s\n", trove_file);
        }

    // Adding Specific Word Lengths To Trove File
        else if(opt == 'l') {
            word_length = atoi(optarg);
            // CURRENT ISSUE NEED TO RETURN VALUE
            printf("Word Length Provided = %i\n", word_length);
        }

    // OOPS - AN UNKNOWN ARGUMENT
        else {
            argc = -1;
        }
    }

    if(argc <= 0){ // Display program's usage
        usage(argv[0]);
    }

    argc  -= optind;
    argv  += optind;

    // For Debugging Determining Mode
    if(TypeFlag){
        char *word = argv[argc];
        printf("MODE: Search\n");
        search_trove(trove_file, word);
    }
    else{
        file_list = argv[argc];
        printf("MODE: Build/Modify\n");
        if(BuildFlag){
            build_trove(trove_file, word_length, file_list);
        }
        else if(UpdateFlag){
            update_trove(trove_file, word_length, file_list);
        }
        else if(RemoveFlag){
            remove_trove(trove_file, word_length, file_list);
        }
    }
    exit(EXIT_SUCCESS);
    return 0;
}