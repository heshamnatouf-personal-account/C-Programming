#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "PlaylistNode.h"

void NewlineTrim(char* line);
void BufferPurge(void);

void PrintMenu(char playlistTitle[]) {
    char selectionMenu;
    /* Declare variables */
    int currentPosition  = 0;
    int newPosition      = 0;
    int rc               = 0;
    int nodeNum          = 0;

    char id         [50];
    char artistName [50];
    char songName   [50];
    int  songLength  = 0;


    PlaylistNode * headNode         = NULL;
    PlaylistNode * tailNode         = NULL;
    PlaylistNode * currentNode      = NULL;
    PlaylistNode * songNode         = NULL;
    PlaylistNode * oldNodePrevious  = NULL;
    PlaylistNode * newNodePrevious  = NULL;


  do { 
      /* PROGRAM MENU */
      printf("%s PLAYLIST MENU\n", playlistTitle);
      printf("a - Add song\n");
      printf("r - Remove song\n");
      printf("c - Change position of song\n");
      printf("s - Output songs by specific artist\n");
      printf("t - Output total time of playlist (in seconds)\n");
      printf("o - Output full playlist\n");
      printf("q - Quit\n\n");

      printf("Choose an option: ");
      scanf(" %c", &selectionMenu);
      printf("\n");

      switch(selectionMenu){
        case 'A':
        case 'a':
            printf("ADD SONG\n");

            BufferPurge();
            printf("Enter song's unique ID: ");
            fgets(id, 50, stdin);
            NewlineTrim(id);
            
            printf("Enter song's name: ");
            fgets(songName, 50, stdin);
            NewlineTrim(songName);

            printf("Enter artist's name: ");
            fgets(artistName, 50, stdin);
            NewlineTrim(artistName);

            printf("Enter song's length (in seconds): ");
            scanf("%d", &songLength);
            printf("\n\n");

            /* Create playListNode and vertify */
            currentNode = CreatePlaylistNode(id, songName, artistName, songLength);
            if (currentNode == NULL) {
                printf("Unique ID: %s\n", id);
                printf("Song Name: %s\n", songName);
                printf("Artist Name: %s\n", artistName);
                printf("Song Length (in seconds): %d\n", songLength);
                exit(1);
            }

            /* Check if this is the first node in the list */
            if (headNode == NULL) {
                headNode = currentNode;
                tailNode = currentNode;
            } else {
                /* Insert playlistNode after tailNode and vertify */
                rc = InsertPlaylistNodeAfter(tailNode, currentNode);
                if (rc < 0) {
                    printf("Error: Unable to insert node into list...\n");
                    PrintPlaylistNode(currentNode);
                    exit(1);
                }
                tailNode = currentNode;
            }
        break;

        case 'R':
        case 'r':
            printf("REMOVE SONG\n");
            printf("Enter song's unique ID: ");
            fgets(id, 50, stdin);
            NewlineTrim(id);

            songNode = headNode;
            currentNode = NULL;
            int i = 0;

            do {
                if (strcmp(songNode->uniqueID, id) == 0) {
                    i = 1;
                    if(songNode == headNode) {
                        headNode = songNode->nextNodePtr;
                    } else {
                        currentNode->nextNodePtr = songNode->nextNodePtr;
                    }
                    printf("\"%s\" removed.\n\n",songNode->songName);
                    DestroyPlaylistNode(songNode);
                } else {
                    printf("Cannot find specified song, Nothing Rremoved\n");
                    currentNode = songNode;
                    songNode = songNode->nextNodePtr;
                }
            } while((i == 0) && (songNode != NULL));
            i = 0;
        break;
        
         case 'C':
         case 'c':
            songNode = headNode;
            nodeNum = 0;
            while ((songNode != NULL) && (nodeNum < (currentPosition - 1))) {
                nodeNum++;
                songNode = GetNextPlaylistNode(songNode);
            }
            if (songNode == NULL) {
                printf("Error: nothing to be moved!\n");
            } else {
                if (songNode == headNode) {
                    headNode = GetNextPlaylistNode(songNode);
                } else {
                    oldNodePrevious = headNode;
                    while (GetNextPlaylistNode(oldNodePrevious)) {
                        oldNodePrevious = GetNextPlaylistNode(oldNodePrevious);
                    }
                    SetNextPlaylistNode(oldNodePrevious, GetNextPlaylistNode(songNode));
                    if (songNode == tailNode) {
                        tailNode = oldNodePrevious;
                    }
                }
                if (newPosition <= 1){
                    SetNextPlaylistNode(songNode, headNode);
                    headNode = songNode;
                    printf("\"%s\" moved to position 1\n\n", songNode->songName);
                } else {
                    newNodePrevious = headNode;
                    nodeNum = 0;
                    while ((newNodePrevious != NULL) && ((nodeNum + 2) < newPosition)) {
                        newNodePrevious = GetNextPlaylistNode(newNodePrevious);
                        nodeNum++;
                    }
                    if (newNodePrevious == NULL) {
                        InsertPlaylistNodeAfter(tailNode, songNode);
                        tailNode = songNode;
                        newPosition = nodeNum + 1;
                    } else {
                        InsertPlaylistNodeAfter(newNodePrevious, songNode);
                        newPosition = nodeNum + 2;
                    }
                    if (tailNode == newNodePrevious) {
                        tailNode = songNode;
                    }
                    printf("\"%s\" moved to position %d\n\n", songNode->songName, newPosition);
                }
            }
        break;
            
         case 'S':
         case 's':
            printf("OUTPUT SONGS BY SPECIFIC ARTIST\n");
            BufferPurge();
            printf("Enter artist's name: ");
            fgets(artistName, 50, stdin);
            NewlineTrim(artistName);
            printf("\n");

            currentNode = headNode;
            nodeNum = 1;
            while(currentNode != NULL) {
                if(strcmp(artistName, currentNode->artistName) == 0) {
                    printf("%d.\n", nodeNum);
                    PrintPlaylistNode(currentNode);
                    printf(" ");
                }
                currentNode = GetNextPlaylistNode(currentNode);
                nodeNum++;
            }
        break;

         case 'T':
         case 't':
            printf("OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)\n");
            int totalTime = 0;
            currentNode = headNode;
            while(currentNode != NULL){
                totalTime += currentNode->songLength;
                currentNode = GetNextPlaylistNode(currentNode);
            }
            printf("Total time: %d seconds\n\n",totalTime);
        break;

        case 'O':
        case 'o':
            printf("%s - OUTPUT FULL PLAYLIST\n\n", playlistTitle);
            nodeNum = 1;
            currentNode = headNode;
            if (tailNode == NULL) {
                printf("Playlist is empty\n\n");
            } else {
                while (currentNode != NULL) {
                     printf("%d.\n", nodeNum);
                    PrintPlaylistNode(currentNode);
                    currentNode = GetNextPlaylistNode(currentNode);
                    NewlineTrim(playlistTitle);
                    nodeNum++;
                }
            }
        break;

        case 'Q':
        case 'q':
            printf(">_< Good Bye\n\n");
        break;
         
        /* Propmt user to enter a vaild option again if user entered invalid selection */
        default:
            printf("Invalid selection!\n\n");
        break;
      }
   }
   /* menu of options will be visible again if user input any option but 'q'*/
   while (selectionMenu != 'q');
   /* Cleanup the nodes in the list */
    currentNode = headNode;
    PlaylistNode * nextNode;
    while(currentNode != NULL){
        nextNode = GetNextPlaylistNode(currentNode);
        DestroyPlaylistNode(currentNode);
        currentNode = nextNode;
    }
}

int main(void) {
    char playlistTitle [50] = "";
    printf("Enter playlist's title: \n");
    fgets(playlistTitle, 50, stdin);
    NewlineTrim(playlistTitle);
    printf("\n");

    PrintMenu(playlistTitle);

}

void BufferPurge(void) {
   char c = getchar();
   while(c != '\n' && c != EOF) {
      c = getchar();
   }
}

/* NewlineTrim: Remove the trailing newline
 *   character from strings returned from fgets.
 * line - NULL terminiated string
 */
void NewlineTrim(char* line) {
   size_t lineLength;

   /* Validate Parameter */
   if (line == NULL) {
      return;
   }
   lineLength = strlen(line);
   if (line[lineLength - 1] == '\n') {
       line[lineLength - 1] = '\0';
   }
}