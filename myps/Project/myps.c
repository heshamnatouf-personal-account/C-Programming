/* 
 * Author: Hesham Natouf
 * Date: Tue 27 Apr 2021 05:18:43 AM MDT
 * Description: final project (myps)
 */

#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <errno.h>
#include "ProcEntry.h"

#define MAX_PATH_LENGTH 4096

static int procFilter (const struct dirent *current);
static int pidSort(const void *a, const void *b);
static int commSort(const void *a, const void *b);

void usageFunction (char * current);

int main (int argc, char * argv[]) {

    /* Declared Variable */
    int n;
    int sortChosen = 0; 
    int zombieState = 0;
    char sortType = 'p';

    struct dirent **fileScanner;

     /* Allocate space for filePath on stack */
    char filePath[MAX_PATH_LENGTH];
    strcpy(filePath,"/proc");


    int opt;
    while ((opt = getopt(argc, argv, "hpczd:")) != -1) {
        switch (opt){
            case 'h':
                usageFunction(argv[0]);
                exit(0);
                break;
            case 'p':
                if (sortChosen == 1) {
                    fprintf(stderr,"Usage: %s [-d <path>] [-p] or [-c]\n", argv[0]);
                    return 0;
                }
                sortChosen = 1;
                sortType = 'p';
                break;
            case 'c':
                if (sortChosen == 1) {
                    fprintf(stderr,"Usage: %s [-d <path>] [-p] or [-c]\n", argv[0]);
                    return 0;
                }
                sortChosen = 1;
                sortType = 'c';
                break;
            case 'z':
                zombieState = 1;
                break;
            case 'd':
                strncpy(filePath, optarg, MAX_PATH_LENGTH);
                break;
            default:
                usageFunction(argv[0]);
                exit(1);
                break;
        }
    }

    errno = 0;
    n = scandir(filePath, &fileScanner, procFilter, alphasort);
    if (n < 0) {
        perror("scandir: ");
        exit(1);
    }

    if (n == 0) {
        fprintf(stdout, "Couldn't find a processes\n");
        return 0;
    }

    ProcEntry ** myprocs = (ProcEntry **) (malloc(sizeof(ProcEntry *) * n));

    char procFile[MAX_PATH_LENGTH];
    int mLength; /* Max pid Length */
    mLength = MAX_PATH_LENGTH - strlen(filePath) - 7;
    for (int i = 0; i < n; i++) {

        strcpy(procFile, filePath);
        strcat(procFile, "/");
        strncat(procFile, fileScanner[i]->d_name, mLength);
        strcat(procFile, "/stat");
        
        myprocs[i] = CreateProcEntryFromFile(procFile);

        
        if (myprocs[i] == NULL) {
            fprintf(stderr, "ERROR: Failed to create ProcEntry\n");
            for (int j = 0; j < n; j++)  {
                free(fileScanner[j]);
                DestroyProcEntry(myprocs[i]);
            }
            free(fileScanner);
            free(myprocs);
            exit(3);
        }
        
    }

    for (int i = 0; i < n; i++)  {
        free(fileScanner[i]);
    }
    free(fileScanner);
    
    if (sortType == 'p') {
        qsort(myprocs, n, sizeof(ProcEntry *), pidSort);
    } else if (sortType == 'c') {
        qsort(myprocs, n, sizeof(ProcEntry *), commSort);
    } else {
        fprintf(stderr, "ERROR: Failed to sort chosen file\n");
        for (int i = 0; i < n; i++)  {
            DestroyProcEntry(myprocs[i]);
        }
        free(myprocs);
        exit(4);
    }

    /* Display Output */
    fprintf(stdout,"%7s %7s %5s %5s %5s %7s %-25s %-20s\n","PID","PPID","STATE","UTIME","STIME","THREADS","CMD","STAT_FILE");

    for(int i = 0; i < n; i++) {
        if (zombieState == 1 && myprocs[i]->state != 'Z') {
            continue;
        }
        PrintProcEntry(myprocs[i]);
    }

    for (int i = 0; i < n; i++)  {
        DestroyProcEntry(myprocs[i]);
    }
    free(myprocs);

    return 0;
}

static int procFilter (const struct dirent *current) {
    if ((current->d_type != DT_DIR) || !isdigit(current->d_name[0])) {
        return 0;
    }
    return 1;
}

static int pidSort(const void *a, const void *b) {
     ProcEntry *f = *(ProcEntry **)a;
     ProcEntry *s = *(ProcEntry **)b;
     int rval = f->pid - s->pid;
     return rval;
}

static int commSort(const void *a, const void *b) {
     ProcEntry *f = *(ProcEntry **)a;
     ProcEntry *s = *(ProcEntry **)b;
     return strcmp(f->comm, s->comm);
}

void usageFunction (char * current) {
    fprintf(stderr, "Usage: %s [-d <path>] [-p] [-c] [-z] [-h]\n", current);
    fprintf(stderr, "\t-d <path> Directory containing proc entries (default: /proc)\n");
    fprintf(stderr, "\t-p        Display proc entries sorted by pid (default)\n");
    fprintf(stderr, "\t-c        Display proc entries sorted by command lexicographically\n");
    fprintf(stderr, "\t-z        Display ONLY proc entries in the zombie state\n");
    fprintf(stderr, "\t-h        Display this help message\n");
}