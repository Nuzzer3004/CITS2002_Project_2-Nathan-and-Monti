//
// CITS2002 Project 2 2022
// Student1: 23058262 Nguyen Nathan 50
// Student2: 23057892 Chambers Monti 50
//

/*
Trove file format:

 Filenames stored in trove file should be absolute pathnames

 Each indexed word and each absolute filename should be stored only once

 the trove file may not be a text file



Command-line options:

 -b
 builds a new file from contents of a file-list, replace existing file

 -f "trovefile"
 provide the name of trove-file to be built or searched
 default = /tmp/trove

 -l "length"
 provide the minimum length of a word to be added to file must be an int
 default = 4

 -r
 remove file-list files from trove file

 -u
 update the trove-file with contents of files in file-list
 duplicate information is first removed

Step by step plan:

 1. Determine if trove is required to build/modify a file
 or search an existing file

 2. (recursively) traverse the filelist to find all files to be indexed

 3. Open each file found and fild all 'words' of atleast length

 4. Store each word and each filename in our data-structure

 5. Store trove file on disk without compression

 6. Compress files using gzip and zcat

*/

// GLOBAL INCLUDES
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

// PREPROCESSOR CONSTANTS
#define	OPTLIST "bf:l:,ru"
#define DEFAULT_VALUE 4

// GLOBAL FUNCTIONS
extern void build(char filename[]);

// GLOBAL VARIABLES

// Our own data structure for long term data
