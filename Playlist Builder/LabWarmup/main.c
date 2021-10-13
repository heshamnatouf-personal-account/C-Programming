#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "Song.h"


int main(int argc, char * argv[]) {

   if (argc != 3) {
      fprintf(stderr, "Usage: %s <catalog.csv> <size>\n", argv[0]);
      exit(1);
   }

   char * userFilename = argv[1];
   char * userSize = argv[2];

   /* open and validate file */
   errno = 0;
   FILE * datafile = fopen(userFilename, "r");
   if (datafile == NULL) {
      perror("fopen");
      exit(1);
   }

   /* convert size from string to int */
   // int listSize = atoi(userSize);
   int listSize = 0;
   int rc = sscanf(userSize, "%d", &listSize);
   if (rc != 1) {
      fprintf(stderr, "Error: Please enter an integer value for size!\n");
      exit(1);
   }

   if (listSize <= 0) {
      fprintf(stderr, "Error: Please specify a list size greater than zero!\n");
      exit(0);
   }

   Song ** songlist = (Song **) malloc(sizeof(Song *) * listSize);
   if (songlist == NULL) {
      fprintf(stderr, "ERROR: Unable to allocate memory forsonglist!\n");
      exit(1);
   }

   /* Temporary variables for holding CSV fields */
   const int MAX_FIELD_SIZE = 256;
   char artistField[MAX_FIELD_SIZE];
   char albumField[MAX_FIELD_SIZE];
   char titleField[MAX_FIELD_SIZE];
   int durationField;

   int songCount = 0;
   int numRead;
   while (!feof(datafile) && songCount < listSize) {
      numRead = fscanf(datafile, "%255[^,],%255[^,],%255[^,],%d\n", artistField, albumField, titleField, &durationField);
      if (numRead == 4) {
         songlist[songCount++] = CreateSong(artistField, albumField, titleField, durationField);
      } else {
         fprintf(stderr, "Error: read %d of 4 when processing CSV!\n", numRead);
      }
   }
   /* Cleanup a bit */
   fclose(datafile);

   fprintf(stdout, "Successfully loaded %d songs!\n", songCount);


   /* Display the songList*/
   for (int i = 0; i < songCount; i++) {
      PrintSong(songlist[i]);
   }

   /* cleanup the songlist */
   for (int i = 0; i < songCount; i++) {
      DestroySong(songlist[i]);
   }
   free(songlist);

   

   return 0;
}