#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "ItemToPurchase.h"

/*
 * BufferPurge: Remove all remaining characters
 *    from the input buffer
 */
void BufferPurge(void) {
   char c = getchar();
   while(c != '\n' && c != EOF) {
      c = getchar();
   }
}

int main(void) {
   /* Declare variables */
   int rc = 0;
   ItemToPurchase item1, item2;
   int totalCost = 0;
   
   /* Initialize items */
   rc = MakeItemBlank(&item1);
   if (rc < 0) {
      printf("Error: Unable to initialize item1\n");
      exit(1);
   }

      rc = MakeItemBlank(&item2);
   if (rc < 0) {
      printf("Error: Unable to initialize item2\n");
      exit(1);
   }

   /* setup first item */
   printf("Item 1\n");
   printf("Enter the item name: \n");
   scanf("%79[^\n]s", item1.itemName);
   BufferPurge();
   printf("Enter the item price: \n");
   while (scanf("%d", &item1.itemPrice) < 1){
      printf("Please enter an integar value:\n");
      BufferPurge();
   }
   BufferPurge();
   printf("Enter the item quantity: \n");
   while (scanf("%d", &item1.itemQuantity) < 1) {
      printf("Please enter an integar value:\n");
      BufferPurge();
   }
   BufferPurge();

   /* setup second item */
   printf("\nItem 2\n");
   printf("Enter the item name: \n");
   scanf("%79[^\n]s", item2.itemName);
   BufferPurge();
   printf("Enter the item price: \n");
   /* Read price and validate user respance */
   while (scanf("%d", &item2.itemPrice) < 1) {
      printf("Please enter an integar value:\n");
      BufferPurge();
   }
   BufferPurge();
   printf("Enter the item quantity: \n");
   while (scanf("%d", &item2.itemQuantity) < 1){
      printf("Please enter an integar value:\n");
      BufferPurge();
   }
   BufferPurge();
   printf("\n");

   /* Calculate total cost */
   totalCost += item1.itemQuantity * item1.itemPrice;
   totalCost += item2.itemQuantity * item2.itemPrice;

   printf("\nTOTAL COST\n");
   /* Display the first item */
   PrintItemCost(item1);

   /* Display the second item */
   PrintItemCost(item2);

   /* Display the total of item1 and item2 */
   printf("\nTotal: $%d\n", totalCost);

   
   return 0;
}