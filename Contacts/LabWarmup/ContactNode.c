#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "ContactNode.h"

ContactNode* CreateContactNode(char name[], char phoneNum[]) {

    ContactNode* thisNode = (ContactNode *) malloc(sizeof(ContactNode));

    if(thisNode == NULL) {
        return NULL;
    }

    strncpy(thisNode->contactName, name, CONTACT_FIELD_SIZE);
    strncpy(thisNode->contactPhoneNum, phoneNum, CONTACT_FIELD_SIZE);
    thisNode->nextNodePtr = NULL;

    return thisNode;
}

int InsertContactAfter(ContactNode* nodeInList, ContactNode* newNode) {
    ContactNode* tmpNext = NULL;

    /* Validate parameters */
    if (nodeInList == NULL || newNode == NULL) {
        return -1;
    }

    tmpNext = nodeInList->nextNodePtr;
    nodeInList->nextNodePtr = newNode;
    newNode->nextNodePtr = tmpNext;

    return 0;

}

ContactNode* GetNextContact(ContactNode* nodeInList) {
    /* Validate parameters */
    if (nodeInList == NULL) {
        return NULL;
    }
    return nodeInList->nextNodePtr;

}

void PrintContactNode(ContactNode* thisNode) {
    /* Validate parameters */
    if (thisNode == NULL) {
        return;
    }

    printf("Name: %s", thisNode->contactName);
    printf("Phone number: %s", thisNode->contactPhoneNum);

    return;

}

void DestroyContactNode(ContactNode* thisNode) {
    /* Validate parameters */
    if (thisNode == NULL) {
        return;
    }
    free(thisNode);
   
}