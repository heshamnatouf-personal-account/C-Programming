/*
* Author: Hesham Natouf
* Date: Wednesday 10 Frbruary 2021 08:40:02 PM PDT
* Description: using loops to draw a tringle 
*/
#include <stdio.h>

int main(void) {
   char triangleChar = 0;
   int triangleHeight = 0; 
   int rc = 0;

   printf("Enter a character:\n");
   scanf("%c", &triangleChar);
   
   printf("Enter triangle height:\n");
   rc = scanf("%d", &triangleHeight);
   printf("\n");

   if (rc == 0) {
      printf("Error: Unrecognized input, please enter only integer values.\n");
      return 1;
   }

   for(int i = 0; i < triangleHeight; i++) {
      for(int j = 0; j < i + 1; j++) {
         printf("%c ",triangleChar);
      }
      printf("\n");
   }

   return 0;
}