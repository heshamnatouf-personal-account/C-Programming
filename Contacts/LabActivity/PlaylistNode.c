#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "PlaylistNode.h"

PlaylistNode* CreatePlaylistNode(char id[], char songName[], char artistName[], int songLength) {

    PlaylistNode* thisNode = (PlaylistNode *) malloc(sizeof(PlaylistNode));

    if(thisNode == NULL) {
        return NULL;
    }

    strncpy(thisNode->uniqueID, id, 50);
    strncpy(thisNode->songName, songName, 50);
    strncpy(thisNode->artistName, artistName, 50);
    thisNode->songLength = songLength;
    thisNode->nextNodePtr = NULL;

    return thisNode;
}

int InsertPlaylistNodeAfter(PlaylistNode* nodeInList, PlaylistNode* newNode) {
    PlaylistNode* tmpNext = NULL;

    /* Validate parameters */
    if (nodeInList == NULL || newNode == NULL) {
        return -1;
    }

    tmpNext = nodeInList->nextNodePtr;
    nodeInList->nextNodePtr = newNode;
    newNode->nextNodePtr = tmpNext;

    return 0;


}

int SetNextPlaylistNode(PlaylistNode* nodeInList, PlaylistNode* newNode) {
    /* Validate parameters */
    if (nodeInList == NULL || newNode == NULL) {
        return -1;
    }

    nodeInList->nextNodePtr = newNode;

    return 0;

}

PlaylistNode* GetNextPlaylistNode(PlaylistNode* nodeInList) {
    /* Validate parameters */
    if (nodeInList == NULL) {
        return NULL;
    }
    return nodeInList->nextNodePtr;

}

void PrintPlaylistNode(PlaylistNode* thisNode) {
    /* Validate parameters */
    if (thisNode == NULL) {
        return;
    }

    printf("Unique ID: %s\n", thisNode->uniqueID);
    printf("Song Name: %s\n", thisNode->songName);
    printf("Artist Name: %s\n", thisNode->artistName);
    printf("Song Length (in seconds): %d\n\n", thisNode->songLength);

    return;
}

void DestroyPlaylistNode(PlaylistNode* thisNode) {
    /* Validate parameters */
    if (thisNode == NULL) {
        return;
    }
    free(thisNode);
}