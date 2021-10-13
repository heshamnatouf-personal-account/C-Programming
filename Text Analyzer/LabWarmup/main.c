/*
* Author: Hesham Natouf
* Date: Tue Feb 23 08:37:57 PM MST 2021
* Description: Lab 07 Warmup Activity.
*/

#include<stdio.h>
#include <string.h>

/* Output string to stdout without whitespace chatacters
 * usrStr - null terminated string
 */
void OutputWithoutWhitespace( const char usrStr[]) {
   for (size_t i = 0; i < strlen(usrStr); i++) {
      if (usrStr[i] != ' ' && usrStr[i] != '\t') {
      printf("%c", usrStr[i]);
      }
   }
   printf("\n");
}
/* Returns the number of characters in usrStr
 * usrStr - null terminated string
 * returns - number of characters in string 
 */
int GetNumOfCharacters(const char usrStr[]) {
   int i = 0;
   while (usrStr[i] != '\0') {
      i++;
   }

   return i;
}

int main(void) {

   /* Declare variable */
   const int MAX_INPUT_LENGTH = 50;
   char userString[MAX_INPUT_LENGTH];
   int charCount = 0;
   char * inputRC;

   /* Prompt user for String */
   printf("Enter a sentence or phrase:\n");
   inputRC = fgets(userString, MAX_INPUT_LENGTH, stdin);
   if (inputRC == NULL) {
      printf("AN error occurred while processing user input!\n");
      return 1;
   }

   /* Remove trailing newline character */
   //userString[strlen(userString) - 1] = '\0';

   printf("\n");
   /* Output the string */
   printf("You entered: %s\n", userString);

   /* Output the number of characters */
   charCount = GetNumOfCharacters(userString);
   printf("Number of characters: %d\n", charCount);

   /* Output the string without whiltespace characters */
   printf("String with no whitespace: ");
   OutputWithoutWhitespace(userString);


   return 0;
}