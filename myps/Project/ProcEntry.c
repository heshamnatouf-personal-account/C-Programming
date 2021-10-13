/* 
 * Author: Hesham Natouf
 * Date: Tue 27 Apr 2021 05:18:43 AM MDT
 * Description: final project (ProcEntry)
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "ProcEntry.h"

ProcEntry * CreateProcEntry(void) {
    ProcEntry * newEntry = (ProcEntry*)malloc(sizeof(ProcEntry));
    
    // Allocate newEntry
    if (newEntry == NULL) {
        return NULL;
    }

    //intialize variables
    newEntry->pid = 0;
    newEntry->ppid = 0;
    newEntry->state = '\0';
    newEntry->utime = 0;
    newEntry->stime = 0;
    newEntry->num_threads = 0;
    newEntry->comm = NULL;
    newEntry->path = NULL;
    
    return newEntry;
}

ProcEntry * CreateProcEntryFromFile(const char statFile[]) {
    
   FILE * datafile = fopen(statFile, "r");
    if (datafile == NULL) {
        perror("fopen");
        return NULL;
    }

    ProcEntry  * newEntry = (ProcEntry *)malloc(sizeof(ProcEntry));
    if (newEntry == NULL) {
        fprintf(stderr, "ERROR: Unable to allocate memory for ProcEntry!\n");
        return NULL;
    }

    newEntry->path = (char *)malloc(sizeof(char) * (strlen(statFile) + 1));
    if(newEntry->path == NULL) {
        fprintf(stderr, "ERROR: Failed to allocate path\n");
        return NULL;
    }
    strncpy(newEntry->path, statFile, strlen(statFile) + 1);

    int numRead = 0;

    for(int i = 1; i <= 20; i++) {
        switch (i) {
            case 1: ;
                numRead = fscanf(datafile, " %d", &newEntry->pid);
                if (numRead != 1) {
                    fprintf(stderr, "ERROR: Failed to read in pid\n");
                    return NULL;
                }
            break;
            case 2: ;
                char tempString[1000];
                numRead = fscanf(datafile, " %1000s", tempString);
                if (numRead != 1) {
                    fprintf(stderr, "ERROR: Failed to read in Comm\n");
                    return NULL;
                }

                newEntry->comm = (char *)malloc(sizeof(char) * (strlen(tempString) + 1));
                if(newEntry->comm == NULL) {
                    fprintf(stderr, "ERROR: Failed to allocate Comm\n");
                    return NULL;
                }
                strncpy(newEntry->comm, tempString, strlen(tempString) + 1);
            break;
            case 3: ;
                numRead = fscanf(datafile, " %c", &newEntry->state);
                if (numRead != 1) {
                    fprintf(stderr, "ERROR: Failed to read in state\n");
                    return NULL;
                }
            break;
            case 4:
                numRead = fscanf(datafile, " %d", &newEntry->ppid);
                if (numRead != 1) {
                    fprintf(stderr, "ERROR: Failed to read in ppid\n");
                    return NULL;
                }
            break;
            case 14:
                numRead = fscanf(datafile, " %lu", &newEntry->utime);
                if (numRead != 1) {
                    fprintf(stderr, "ERROR: Failed to read in utime\n");
                    return NULL;
                }
            break;
            case 15:
                numRead = fscanf(datafile, " %lu", &newEntry->stime);
                if (numRead != 1) {
                    fprintf(stderr, "ERROR: Failed to read in stime\n");
                    return NULL;
                }
            break;
            case 20:
                numRead = fscanf(datafile, " %ld", &newEntry->num_threads);
                if (numRead != 1) {
                    fprintf(stderr, "ERROR: Failed to read in processor number\n");
                    return NULL;
                }
            break;
            default:
                fscanf(datafile, " %*u");
            break;
       }
    }

    fclose(datafile);
    return newEntry;
}

void DestroyProcEntry(ProcEntry * entry) {
    if (entry == NULL) {return;}
    free(entry->comm);
    free(entry->path);
    free(entry);
}

void PrintProcEntry(ProcEntry *entry)
{
     unsigned long int utime = entry->utime / sysconf(_SC_CLK_TCK);
     unsigned long int stime = entry->stime / sysconf(_SC_CLK_TCK);
     fprintf(stdout, "%7d %7d %5c %5lu %5lu %7ld %-25s %-20s\n",
             entry->pid,
             entry->ppid,
             entry->state,
             utime,
             stime,
             entry->num_threads,
             entry->comm,
             entry->path);
}