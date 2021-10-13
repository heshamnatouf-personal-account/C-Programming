/* 
 * Author: Hesham Natouf
 * Date: Sun 04 Apr 2021 03:55:53 PM MDT
 * Description:  Adapted from the Simple Directory Lister Mark II example
 *    provided in the libc manual.
 * https://www.gnu.org/software/libc/manual/html_node/Simple-Directory-Lister-Mark-II.html
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


#define MAX_PATH_LENGTH 4096

#define UNUSED(x) (void)x

int revSort (const struct dirent ** entryA, const struct dirent **entryB) {
    return alphasort(entryA, entryB) * -1;
}

int noSort (const struct dirent ** entryA, const struct dirent **entryB) {
    UNUSED(entryA);
    UNUSED(entryB);
    return 0;
}


static int defaultFilter (const struct dirent *current) {
    if (current->d_name[0] == '.') {
        return 0;
    }
    return 1;
}

static int showAll (const struct dirent *current) {
    UNUSED(current);
    return 1;
}

static int showFilesOnly (const struct dirent *current) {
    if (current->d_type != DT_REG) {
        return 0;
    }
    return 1;
}

void usageFunction (char * current) {
    printf("Usage: %s [-d <path>] [-s] [-a] [-f] [-r]\n", current);
    printf("\t-d <path> Directory to list the contents of\n");
    printf("\t-a        Display all files, including hidden files\n");
    printf("\t-f        Display only regular files\n");
    printf("\t-r        Display entries alphabetically in descending order\n");
    printf("\t-s        Display entries alphabetically in ascending order\n");
}


int main (int argc, char * argv[]) {
    struct dirent **eps;
    int n;
    int opt;

    /* Declare fillterFunction pointer */
    int (*fillterFunction)(const struct dirent *);
    fillterFunction = defaultFilter;

    /* Declare sortFunction pointer */
    int (*sortFunction)(const struct dirent **, const struct dirent **);
    sortFunction = noSort;

    /* Declare dirPath and set default to current directory */
    char dirPath[MAX_PATH_LENGTH];
    strcpy(dirPath, "./");

    /* Use getopt() to processess command line arguments */
    while ( (opt = getopt(argc, argv, "hd:sraf")) != -1) {
        switch (opt) {
            case 'd':
                strncpy(dirPath, optarg, MAX_PATH_LENGTH);
                break;
            case 's':
                sortFunction = alphasort;
                break;
            case 'a':
                fillterFunction = showAll;
                break;
            case 'f':
                fillterFunction = showFilesOnly;
                break;
            case 'r':
                sortFunction = revSort;
                break;
            case 'h':
                usageFunction(argv[0]);
                exit(0);
                break;
            default:
                fprintf(stderr, "Error: Invalid Option Specifid\n");
                fprintf(stderr, "Usage: %s [-d <path>] \n", argv[0]);
                break;
        }
    }
    
    /* Perform the actual scan dir of the dirPath */
    errno = 0; 
    n = scandir (dirPath, &eps, fillterFunction, sortFunction);

    /* validate directory was opened successfully */
    if (n < 0) {
        perror("scandir: ");
        exit(1);
    }

    int cnt;
    for (cnt = 0; cnt < n; ++cnt) {
        fprintf(stdout,"%s\n", eps[cnt]->d_name);
    }
    /* Cleanup memory */
    for (int i = 0; i < n; i++) {
        free(eps[i]);
    }

    free (eps);

    return 0;
}
