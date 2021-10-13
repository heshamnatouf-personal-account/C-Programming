/* File: main.c
 * Author: Hesham Natouf
 * Date: Sun 28 Mar 2021 05:28:27 PM MDT
 * Description: Lab Activity
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "Student.h"

Student ** growingArray (Student ** studentArrayList, int listSize, int newSize);
int qsortStudent (const void * studentA, const void * studentB);

int main(int argc, char * argv[]) {

   if (argc != 2) {
      fprintf(stderr, "Usage: %s <gradebook.csv>\n", argv[0]);
      exit(1);
   }

   char * userFilename = argv[1];
   // char * userSize = argv[2];
   int userSize = 8;

   /* open and validate file */
   errno = 0;
   FILE * datafile = fopen(userFilename, "r");
   if (datafile == NULL) {
      perror("fopen");
      exit(1);
   }

   Student ** studentlist = (Student **) malloc(sizeof(Student *) * userSize);
   if (studentlist == NULL) {
      fprintf(stderr, "ERROR: Unable to allocate memory for studentlist!\n");
      exit(1);
   }

   /* Temporary variables for holding CSV fields */
   const int MAX_FIELD_SIZE = 256;
   char lastname[MAX_FIELD_SIZE];
   char firstname[MAX_FIELD_SIZE];
   int id;
   int score;


   int studentCount = 0;
   int numRead = 0;
   while (!feof(datafile)) {
      if (studentCount == userSize) {
         Student ** studentArray = growingArray(studentlist, userSize, userSize * 2);
         studentlist = studentArray;
         userSize *= 2;
      }
      numRead = fscanf(datafile, "%255[^,],%255[^,],%d,%d\n", lastname, firstname, &id, &score);
      if (numRead == 4) {
         studentlist[studentCount++] = CreateStudent(lastname, firstname, id, score);
      } else {
         fprintf(stderr, "Error: read %d of 4 when processing CSV!\n", numRead);
      }
   }
   /* Cleanup a bit */
   fclose(datafile);

   fprintf(stdout, "Successfully loaded %d students!\n", studentCount);

   qsort(studentlist, studentCount, sizeof(Student *), qsortStudent);

   /* Display the StudentList*/
   for (int i = 0; i < studentCount; i++) {
      PrintStudent(studentlist[i]);
   }

   /* cleanup the studentlist */
   for (int i = 0; i < studentCount; i++) {
      DestroyStudent(studentlist[i]);
   }
   free(studentlist);

   return 0;
}

Student ** growingArray (Student ** studentArrayList, int listSize, int newSize) {
   if (studentArrayList == NULL || newSize < listSize) {
      return NULL;
   }

   Student ** arrayList = (Student **) malloc(sizeof(Student *) * newSize);
   if  (arrayList == NULL) {
      return NULL;
   }

   for(int i = 0; i < listSize; i++) {
      arrayList[i] = studentArrayList[i];
   }
   free (studentArrayList);

   fprintf(stdout, "Growing Array: %d -> %d\n", listSize, newSize);
   return arrayList;
}

int qsortStudent (const void * studentA, const void * studentB) {
   return CompareStudents(studentA, studentB);
}