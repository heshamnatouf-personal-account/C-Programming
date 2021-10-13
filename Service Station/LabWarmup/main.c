/*
* Author: Hesham Natouf
* Date: Thu 4 Feb 2021 11:17:52 PM PDT
* Description: This Lab warmup is about a program that allows the user to check on different auto service prices.
*/
#include <stdio.h>
#include <string.h>

int main(void) {

   const int MAX_WORD_LENGTH = 40;
   char  service [MAX_WORD_LENGTH + 1];


   /* Part 1 - get service from user */
   printf("Enter desired auto service: ");
   scanf("%40[^\n]", service);
   printf("You entered: %s\n", service);

   /* Part 2 - output price of the requasted service */
   if (strcmp(service,"Oil change") == 0) {
      printf("Cost of Oil change: $35\n");
   } else if (strcmp(service,"Tire rotation") == 0) {
      printf("Cost of Tire rotation: $19\n");
   } else if (strcmp(service,"Car wash") == 0) {
      printf("Cost of Car wash : $7\n");
   } else {
      printf("Requested service is not recognized\n");
      return 254;
   }
   return 0;
}
