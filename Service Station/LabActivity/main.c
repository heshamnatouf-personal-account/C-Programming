/*
* Author: Hesham Natouf
* Date: Thursday 4 Frbruary 2021 11:21:59 PM PDT
* Description: This Lab activity is a program that allows the user to check on different auto service bundle prices.
*/
#include <stdio.h>
#include <string.h>

int main(void) {

   const int MAX_WORD_LENGTH = 40;
   char  service1 [MAX_WORD_LENGTH + 1];
   char  service2 [MAX_WORD_LENGTH + 1];

   /* Part one: Output a menu of automotive services and the corresponding cost of each service. */
   printf("Davy's auto shop services\n");
   printf("Oil change -- $35\n");
   printf("Tire rotation -- $19\n");
   printf("Car wash -- $7\n");
   printf("Car wax -- $12\n\n");

   /* Part two: Prompt the user for two services. Each service type is composed of two strings. */
   printf("Select first service: \n");
   scanf(" %40[^\n]", service1);
   printf("Select second service: \n");
   scanf(" %40[^\n]", service2);

   /* Part three: Output an invoice for the services selected. Output the cost for each service and the total cost. */
   if ( (strcmp(service1,"Oil change") == 0) && (strcmp(service2,"Tire rotation") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: Oil change, $35\n");
      printf("Service 2: Tire rotation, $19\n\n");
      printf("Total: $54\n");

   } else if ( (strcmp(service1,"Oil change") == 0) && (strcmp(service2,"Car wash") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: Oil change, $35\n");
      printf("Service 2: Car wash, $7\n\n");
      printf("Total: $42\n");

   } else if ( (strcmp(service1,"Oil change") == 0) && (strcmp(service2,"Car wax") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: Oil change, $35\n");
      printf("Service 2: Car wax, $12\n\n");
      printf("Total: $47\n");

   } else if ( (strcmp(service1,"Oil change") == 0) && (strcmp(service2,"Oil change") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: Oil change, $35\n");
      printf("Service 2: Oil change, $35\n\n");
      printf("Total: $70\n");

   } else if ( (strcmp(service1,"Tire rotation") == 0) && (strcmp(service2,"Tire rotation") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: Tire rotation, $19\n");
      printf("Service 2: Tire rotation, $19\n\n");
      printf("Total: $38\n");

   } else if ( (strcmp(service1,"Tire rotation") == 0) && (strcmp(service2,"Oil change") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: Tire rotation, $19\n");
      printf("Service 2: Oil change, $35\n\n");
      printf("Total: $54\n");

   } else if ( (strcmp(service1,"Tire rotation") == 0) && (strcmp(service2,"Car wash") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: Tire rotation, $19\n");
      printf("Service 2: Car wash, $7\n\n");
      printf("Total: $26\n");

   } else if ( (strcmp(service1,"Tire rotation") == 0) && (strcmp(service2,"Car wax") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: Tire rotation, $19\n");
      printf("Service 2: Car wax, $12\n\n");
      printf("Total: $31\n");

   } else if ( (strcmp(service1,"Car wash") == 0) && (strcmp(service2,"Car wash") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: Car wash, $7\n");
      printf("Service 2: Car wash, $7\n\n");
      printf("Total: $14\n");

   } else if ( (strcmp(service1,"Car wash") == 0) && (strcmp(service2,"Oil change") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: Car wash, $7\n");
      printf("Service 2: Oil change, $35\n\n");
      printf("Total: $42\n");

   } else if ( (strcmp(service1,"Car wash") == 0) && (strcmp(service2,"Tire rotation") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: Car wash, $7\n");
      printf("Service 2: Tire rotation, $19\n\n");
      printf("Total: $26\n");

   } else if ( (strcmp(service1,"Car wash") == 0) && (strcmp(service2,"Car wax") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: Car wash, $7\n");
      printf("Service 2: Car wax, $12\n\n");
      printf("Total: $19\n");

   } else if ( (strcmp(service1,"Car wax") == 0) && (strcmp(service2,"Car wax") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: Car wax, $12\n");
      printf("Service 2: Car wax, $12\n\n");
      printf("Total: $0\n");

   } else if ( (strcmp(service1,"Car wax") == 0) && (strcmp(service2,"Oil change") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: Car wax, $12\n");
      printf("Service 2: Oil change, $35\n\n");
      printf("Total: $47\n");

   } else if ( (strcmp(service1,"Car wax") == 0) && (strcmp(service2,"Tire rotation") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: Car wax, $12\n");
      printf("Service 2: Tire rotation, $19\n\n");
      printf("Total: $31\n");

   } else if ( (strcmp(service1,"Car wax") == 0) && (strcmp(service2,"Car wash") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: Car wax, $12\n");
      printf("Service 2: Car wash, $7\n\n");
      printf("Total: $19\n");
   /* Part four: Extend the program to allow the user to enter a dash (-), which indicates no service. */
   } else if ( (strcmp(service1,"Oil change") == 0) && (strcmp(service2,"-") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: Oil change, $35\n");
      printf("Service 2: No service\n\n");
      printf("Total: $35\n");

   }  else if ( (strcmp(service1,"Tire rotation") == 0) && (strcmp(service2,"-") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: Tire rotation, $19\n");
      printf("Service 2: No service\n\n");
      printf("Total: $19\n");

   } else if ( (strcmp(service1,"Car wash") == 0) && (strcmp(service2,"-") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: Car wash, $7\n");
      printf("Service 2: No service\n\n");
      printf("Total: $7\n");

   } else if ( (strcmp(service1,"Car wax") == 0) && (strcmp(service2,"-") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: Car wax, $12\n");
      printf("Service 2: No service\n\n");
      printf("Total: $12\n");

   } else if ( (strcmp(service1,"-") == 0) && (strcmp(service2,"Oil change") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: No service\n");
      printf("Service 2: Oil change, $35\n\n");
      printf("Total: $35\n");

   }  else if ( (strcmp(service1,"-") == 0) && (strcmp(service2,"Tire rotation") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: No service\n");
      printf("Service 2: Tire rotation, $19\n\n");
      printf("Total: $19\n");

   } else if ( (strcmp(service1,"-") == 0) && (strcmp(service2,"Car wash") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: No service\n");
      printf("Service 2: Car wash, $7\n\n");
      printf("Total: $7\n");

   } else if ( (strcmp(service1,"-") == 0) && (strcmp(service2,"Car wax") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: No service\n");
      printf("Service 2: Car wax, $12\n\n");
      printf("Total: $12\n");

   } else if ( (strcmp(service1,"-") == 0) && (strcmp(service2,"-") == 0)) {
      printf("\nDavy's auto shop invoice\n\n");
      printf("Service 1: No service\n");
      printf("Service 2: No service\n\n");
      printf("Total: $0\n");

   } else {
      printf("Requested service is not recognized\n");
   }
   return 0; 
}
