/*
* Author: Hesham Natouf
* Date: Wednesday 10 Frbruary 2021 08:40:02 PM PDT
* Description: This Lab activity is a program that allows 
* the user to half an arrow based on the height and width that the user chooses.
*/
#include <stdio.h>

int main(void) {
   int arrowBaseHeight = 0;
   int arrowBaseWidth = 0;
   int arrowHeadWidth = 0;
   int rc = 0;

   printf("Enter arrow base height:\n");
   rc = scanf("%d", &arrowBaseHeight);
   if (rc == 0) {
      printf("Error: Unrecognized input, please enter only integer values.\n");
      return 1;
   }
   printf("Enter arrow base width:\n");
   rc = scanf("%d", &arrowBaseWidth);
   if (rc == 0) {
      printf("Error: Unrecognized input, please enter only integer values.\n");
      return 1;
   }
   printf("Enter arrow head width:\n");
   rc = scanf("%d", &arrowHeadWidth);
   printf("\n");
   if (rc == 0) {
      printf("Error: Unrecognized input, please enter only integer values.\n");
      return 1;
   }

   while (arrowHeadWidth <= arrowBaseWidth) {
      printf("Please enter a valid arrow head width value:\n");
      scanf("%d", &arrowHeadWidth);
      printf("\n");
   }

   for (int i = 0; i <= arrowBaseHeight - 1; i++) {
      for (int j = 0; j <= arrowBaseWidth - 1; j++) {
         printf("*");
      }
         printf("\n");
   }
   for (int i = arrowHeadWidth; i > 0; i--) {
      for (int j = 0; j <= i - 1; j++) {
         printf("*");
      }
         printf("\n");
   }
   
   return 0;
}