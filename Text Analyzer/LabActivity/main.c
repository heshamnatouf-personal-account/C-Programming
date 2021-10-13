/*
* Author: Hesham Natouf
* Date: Mon Mar 1 03:05:36 PM MST 2021
* Description: Lab 07 Activity.
*/

#include<stdio.h>
#include <string.h>

/* Returns the number of characters in usrStr without white space
 * returns - number of characters in string 
 */

int GetNumOfNonWSCharacters(const char usrStr[]) {
   int charactersNum = 0;
   for (int i = 0; usrStr[i] != '\0'; i++) {
      if (usrStr[i] != ' ') {
         charactersNum++;
      }
   }
   return charactersNum;
   printf("\n");
}
/* Returns the number of words in usrStr
 * returns - number of characters in string 
 */

int GetNumOfWords(const char usrStr[]) {
   int wordsNum = 0;
   for (int i = 0; usrStr[i] != '\0'; i++) {
      if(usrStr[i] != ' ') {
         while(usrStr[i] != '\0' && usrStr[i] != ' ') {
            i++;
         }
      wordsNum++;
      }
   }
   return wordsNum;
   printf("\n");
}
/* Fix capitalizon in usrStr
 * return - edited text
 */

void FixCapitalization(char usrStr[]) {
   int fixCapitalization = 0;
   if (usrStr[0] >= 97 && usrStr[0] <= 122) {
      usrStr[0] = usrStr[0] - 32;
   }
   for (int i = 0; usrStr[i] != '\0';i++) {
      if (fixCapitalization == 1 && usrStr[i] != ' ') {
         if (usrStr[i] >= 97 && usrStr[i] <= 122) {
            usrStr[i] = usrStr[i] - 32;
         }
         fixCapitalization = 0;
      }
      if (usrStr[i] == '.') {
         fixCapitalization = 1;
      }
   }
   printf("\n");
}
/* Replace exclmation mark with dot
 * returns - edited text
 */

void ReplaceExclamation(char usrStr[]) {
   for (int i = 0; usrStr[i] != '\0'; i++) {
      if (usrStr[i] == '!') {
         usrStr[i] ='.';
      }
   }
   printf("\n");
}
/* shorten a space in usrStr
 * returns - edited text 
 */

void ShortenSpace(char usrStr[]) {
   int shortenSpace = 0;
   for (int i = 0; usrStr[i] != '\0';) {
      if (usrStr[i] == ' ' && shortenSpace == 1) {
         int j;
         for(j = i; usrStr[j] != '\0'; j++) {
            usrStr[j] = usrStr[j + 1];
         }
         usrStr[j] = '\0';
      } else if (usrStr[i] == ' ') {
         shortenSpace = 1;
         i++;
      } else if (usrStr[i] != ' ') {
         shortenSpace = 0;
         i++;
      }
   }
   printf("\n");
}
/* Selection menu that represent each one of the function above
 * returns - selection menu
 */

void PrintMenu(char usrStr[]) {
      char selectionMenu;
      int NUM_Count;
      int WORDS_Count;
      do { 
      printf("MENU\n");
      printf("c - Number of non-whitespace characters\n");
      printf("w - Number of words\n");
      printf("f - Fix capitalization\n");
      printf("r - Replace all !'s\n");
      printf("s - Shorten spaces\n");
      printf("q - Quit\n\n");

      printf("Choose an option: ");
      scanf(" %c", &selectionMenu);
      printf("\n");

      switch(selectionMenu){
         case 'C':
         case 'c':
            NUM_Count = GetNumOfNonWSCharacters(usrStr);
            printf("Number of words: %d\n\n", NUM_Count);
            break;
         case 'W':
         case 'w':
            WORDS_Count = GetNumOfWords(usrStr);
            printf("Number of non-whitespace characters: %d\n\n", WORDS_Count);
            break;
         case 'F':
         case 'f':
            FixCapitalization(usrStr);
            printf("Edited text: %s\n\n", usrStr);
            break;
         case 'R':
         case 'r':
            ReplaceExclamation(usrStr);
            printf("Edited text: %s\n\n", usrStr);
            break;
         case 'S':
         case 's':
            ShortenSpace(usrStr);
            printf("Edited text: %s\n\n", usrStr);
            break;
         case 'Q':
         case 'q':
            printf(">_< Good Bye\n\n");
            break;
         default:
            printf("Invalid selection!\n\n");
            break;
      }
   } 
   /* menu of options will be visible again if user input any option but 'q'*/
   while (selectionMenu != 'q');
}  

int main(void) {

   /* Declare variable */
   const int MAX_INPUT_LENGTH = 10000;
   char userString[MAX_INPUT_LENGTH];
   char * inputRC;

   /* Prompt user for String */
   printf("Enter a sample text:\n");
   inputRC = fgets(userString, MAX_INPUT_LENGTH, stdin);
   if (inputRC == NULL) {
      printf("AN error occurred while processing user input!\n");
      return 1;
   }

   /* Remove trailing newline character */
   userString[strlen(userString) - 1] = '\0';

   printf("\n");
   /* Output the string */
   printf("You entered: %s\n", userString);
   printf("\n");

   PrintMenu(userString);

   return 0;
}