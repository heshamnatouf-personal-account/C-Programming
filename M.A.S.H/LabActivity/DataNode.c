/* 
 * File: DataNode.c
 * Author: Hesham Natouf
 * Date: Fri Mar 19 12:28:36 PM MDT 2021
 * Description: Lab Activity DataNode.c
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "DataNode.h"

DataNode* CreateDataNode(const char data[]) {
    if (data == NULL) {
        return NULL;
    }

    DataNode* newNode = (DataNode*)malloc(sizeof(DataNode));
    
    if (newNode == NULL) {
        return NULL;
    }
    
    newNode->dataSize = strlen(data);
    newNode->dataValue = (char*)malloc(newNode->dataSize + 1 * sizeof(char));
    strcpy(newNode->dataValue, data);
    newNode->nextNodePtr = NULL;

    return newNode;
}

int InsertDataNodeAfter(DataNode* nodeInList, DataNode* newNode) {
    DataNode* tmpNext = NULL;

    /* Validate parameters */
    if (nodeInList == NULL || newNode == NULL) {
        return -1;
    }

    tmpNext = nodeInList->nextNodePtr;
    nodeInList->nextNodePtr = newNode;
    newNode->nextNodePtr = tmpNext;

    return 0;
}

int SetNextDataNode(DataNode* nodeInList, DataNode* newNode) {
    /* Validate parameters */
    if (nodeInList == NULL || newNode == NULL) {
        return -1;
    }

    nodeInList->nextNodePtr = newNode;

    return 0;
}

DataNode* GetNextDataNode(DataNode* nodeInList) {
    /* Validate parameters */
    if (nodeInList == NULL) {
        return NULL;
    }
    return nodeInList->nextNodePtr;
}

void PrintDataNode(DataNode* thisNode) {
    /* Validate parameters */
    if (thisNode == NULL) {
        return;
    }

    printf("%s", thisNode->dataValue);

    return;
}

void DestroyDataNode(DataNode* thisNode) {
    /* Validate parameters */
    if (thisNode == NULL) {
        return;
    }
    free(thisNode->dataValue);
    free(thisNode);
}

DataNode* BuildDataList(char * data[], int numElements) {
    DataNode * currentNode  = NULL;
    DataNode * listHead     = NULL;
    DataNode * listTail     = NULL;

    for (int i = 0; i < numElements; i++) {
        listTail = CreateDataNode(data[i]);

        if(listTail == NULL) {
            DestroyDataList(listHead);
            return NULL;
        }
        
        if (i == 0) {
            listHead = listTail;
            currentNode = listTail;
        } else {
            InsertDataNodeAfter(currentNode, listTail);
            currentNode = listTail;
        }
    }
    return listHead;
}

int GetDataListSize(DataNode* listHead) {
    int dataListSize = 0;
    DataNode* currentNode = listHead;
    
    if (listHead == NULL) {
        return -1;
        }

    while (currentNode != NULL) {
        dataListSize++;
        currentNode = currentNode->nextNodePtr;
    }

    return dataListSize;
}

void PrintDataList(DataNode *listHead) {
    DataNode* currentNode = listHead;
    while(currentNode != NULL) {

        PrintDataNode(currentNode);
        currentNode = currentNode->nextNodePtr;

        if (currentNode == NULL) {
            printf(" ");
        }
        else {
            printf(", ");
        }
    }
}

DataNode* GetRandomDataNode(DataNode *listHead) {
    DataNode* currentNode = NULL;
    int randomDataNode = -1;
    int listSize = GetDataListSize(listHead);

    if (listHead == NULL) {
        return NULL;
    }

    randomDataNode = rand() % listSize;

    if(randomDataNode < 0 || randomDataNode >= listSize) { 
        return NULL;
    }

    if (randomDataNode == 0) { 
        return listHead;
    }

    currentNode = listHead;
    for (int i = 0; i < randomDataNode; i++) {
        currentNode = currentNode->nextNodePtr;
    }
    return currentNode;
}

void DestroyDataList(DataNode* listHead) {
    DataNode* currentNode = listHead;

    while (listHead != NULL) {
        listHead = listHead->nextNodePtr;
        DestroyDataNode(currentNode);
        currentNode = listHead;
    }
}