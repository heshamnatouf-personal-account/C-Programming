/* 
 * Author: Heashm Natouf
 * Date: Sun Mar 21 03:54:50 PM MDT 2021
 * Description: Lab Activity M.A.S.H Game
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#include "DataNode.h"

void NewlineTrim(char* line);

int main(void) {
   char userName [50] = "";
   int rc = 0;

   DataNode * database     [6];
   DataNode * headNode     = NULL;
   DataNode * tailNode     = NULL;
   DataNode * currentNode  = NULL;

   srand(time(0));


   enum dataType {HOME_LIST, FEMALE_SPOUSE_LIST, MALE_SPOUSE_LIST, OCCUPATION_LIST, TRANSPORTATION_LIST, HOMETOWN_LIST};

   char* homeList [] = {"mansion", "apartment", "shack", "house", "Condos"};
   char* femaleSpouseList[] = {"Robin", "Lily", "Nora", "Patrice", "Zoey", "Quinn"};
   char* maleSpouseList [] = {"Ted", "Marshall", "Barney", "Ranjit", "Carl", "Linus",};
   char* occupationList [] = {"teacher", "architect", "lawyer", "newscaster", "undercover agent"};
   char* transportationList [] = {"walk", "ride the train", "ride a bus", "fly an airplane", "carpool"};
   char* hometownList [] = {"Cleveland", "Queens", "The Bronx", "Brooklyn", "Manhattan", "Staten Island"};

   database [HOME_LIST] = BuildDataList(homeList, 5);
   database [FEMALE_SPOUSE_LIST] = BuildDataList(femaleSpouseList, 6);
   database [MALE_SPOUSE_LIST] = BuildDataList(maleSpouseList, 5);
   database [OCCUPATION_LIST] = BuildDataList(occupationList, 5);
   database [TRANSPORTATION_LIST] = BuildDataList(transportationList, 5);
   database [HOMETOWN_LIST] = BuildDataList(hometownList, 5);

   printf("\n--------------------- Future Possibilities Database ------------------------\n");
   printf("Home List: ");
   PrintDataList(database [HOME_LIST]);
   printf("\n");
   printf("Female Spouse List: ");
   PrintDataList(database [FEMALE_SPOUSE_LIST]);
   printf("\n");
   printf("Male Spouse List: ");
   PrintDataList(database [MALE_SPOUSE_LIST]);
   printf("\n");
   printf("Occupation List: ");
   PrintDataList(database [OCCUPATION_LIST]);
   printf("\n");
   printf("Transportation List: ");
   PrintDataList(database [TRANSPORTATION_LIST]);
   printf("\n");
   printf("Hometown List: ");
   PrintDataList(database [HOMETOWN_LIST]);
   printf("\n");
   printf("----------------------------------------------------------------------------\n\n");

   printf("Please enter your name: ");
   fgets(userName, 50, stdin);
   NewlineTrim(userName);

   currentNode = CreateDataNode(userName);
      if (currentNode == NULL) {
         printf("Error: Unable to create node...\n");
         exit(1);
      }

   if (headNode == NULL) {
      headNode = currentNode;
      tailNode = currentNode;
   } else {
      /* Insert ContactNode after tailNode and vertify */
         rc = InsertDataNodeAfter(tailNode, currentNode);
         if (rc < 0) {
            printf("Error: Unable to insert node into list...\n");
            PrintDataNode(currentNode);
            exit(1);
         }
         tailNode = currentNode;
   }

   currentNode = headNode;
   while (currentNode != NULL) {
      currentNode = GetNextDataNode(currentNode);
      printf("\n");

   }

   currentNode = headNode;
   DataNode * nextNode;
   while (currentNode != NULL) {
      nextNode = GetNextDataNode(currentNode);
      DestroyDataNode(currentNode);
      currentNode = nextNode;
   }

   printf("\n\n");

   printf("Welcome %s, this is your future... \n", userName);
   printf("You will marry ");
   int genderType = rand() % 2;
   if (genderType == 0) {
   PrintDataNode(GetRandomDataNode(database [MALE_SPOUSE_LIST]));
   } else {
      PrintDataNode(GetRandomDataNode(database [FEMALE_SPOUSE_LIST]));
   }
   printf(" and live in a ");
   PrintDataNode(GetRandomDataNode(database [HOME_LIST]));
   printf(".\n");
   int randNum = (rand() % 10) + 1;
   printf("After %d years of marriage, you will finally get your dream job of being a ", randNum);
   PrintDataNode(GetRandomDataNode(database [OCCUPATION_LIST]));
   printf(".\n");
   printf("Your family will move to a ");
   PrintDataNode(GetRandomDataNode(database [HOME_LIST]));
   printf(" in ");
   PrintDataNode(GetRandomDataNode(database [HOMETOWN_LIST]));
   printf(" where you will ");
   PrintDataNode(GetRandomDataNode(database [TRANSPORTATION_LIST]));
   printf(" to work each day.\n");


   DestroyDataList(database [HOME_LIST]);
   DestroyDataList(database [FEMALE_SPOUSE_LIST]);
   DestroyDataList(database [MALE_SPOUSE_LIST]);
   DestroyDataList(database [OCCUPATION_LIST]);
   DestroyDataList(database [TRANSPORTATION_LIST]);
   DestroyDataList(database [HOMETOWN_LIST]);
   
   return 0;
}

void BufferPurge(void) {
   char c = getchar();
   while(c != '\n' && c != EOF) {
      c = getchar();
   }
}

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