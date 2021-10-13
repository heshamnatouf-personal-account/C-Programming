#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "ContactNode.h"

void NewlineTrim(char* line);

int main(void) {
   char fullName [50] = "";
   char phoneNum [50] = "";
   int rc;
   const int NUM_CONTACTS = 3;


   ContactNode * headNode = NULL;
   ContactNode * tailNode = NULL;
   ContactNode * currentNode = NULL;

   /* Contact entry loop */
   for (int i = 0; i < NUM_CONTACTS; i++) {

      printf("Person %d\n", (i + 1));
      printf("Enter name: \n");
      fgets(fullName, 50, stdin);
      NewlineTrim(fullName);

      printf("Enter phone number: \n");
      fgets(phoneNum, 50, stdin);
      NewlineTrim(phoneNum);

      printf("You entered: %s, %s\n\n", fullName, phoneNum);

      /* Create contactNode and vertify */
      currentNode = CreateContactNode(fullName, phoneNum);
      if (currentNode == NULL) {
         printf("Error: Unable to create node...\n");
         printf("Name: %s\n", fullName);
         printf("Phone Number: %s\n", phoneNum);
         exit(1);
      }

      /* Check if this is the first node in the list */
      if (headNode == NULL) {
         headNode = currentNode;
         tailNode = currentNode;
      } else {
         /* Insert ContactNode after tailNode and vertify */
         rc = InsertContactAfter(tailNode, currentNode);
         if (rc < 0) {
            printf("Error: Unable to insert node into list...\n");
            PrintContactNode(currentNode);
            exit(1);
         }
         tailNode = currentNode;
      }
   
   }

   // print contact list
   printf("CONTACT LIST\n");
   currentNode = headNode;
   while (currentNode != NULL) {
      PrintContactNode(currentNode);
      currentNode = GetNextContact(currentNode);
      printf("\n");

   }

   /* Cleanup the nodes in the list */
   currentNode = headNode;
   ContactNode * nextNode;
   while (currentNode != NULL) {
      nextNode = GetNextContact(currentNode);
      DestroyContactNode(currentNode);
      currentNode = nextNode;
   }

   return 0;
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
      line[lineLength - 1] = '\n';
   }
}
