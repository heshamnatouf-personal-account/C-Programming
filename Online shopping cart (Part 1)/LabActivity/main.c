#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

void BufferPurge(void) {
   char c = getchar();
   while(c != '\n' && c != EOF) {
      c = getchar();
   }
}

void PrintMenu(ShoppingCart cart, ItemToPurchase item) {
   /* Declare variables */
   char selectionMenu;
   char removeItem[80];
   char selectedItem[80];
   int newQunatity;
   ItemToPurchase updateItem;

  do { 
      /* PROGRAM MENU */
      printf("PROGRAM MENU\n");
      printf("a - Add item to cart\n");
      printf("r - Remove item from cart\n");
      printf("c - Change item quantity\n");
      printf("i - Output items' descriptions\n");
      printf("o - Output shopping cart\n");
      printf("q - Quit\n\n");

      printf("Choose an option: ");
      scanf(" %c", &selectionMenu);
      printf("\n");

      switch(selectionMenu){
         /* Add item to cart if user input 'a' or 'A' */
         case 'A':
         case 'a':
         printf("ADD ITEM TO CART\n");
         /* Prompt user to enter new item name */
         BufferPurge();
         printf("Enter the item name: \n");
         scanf("%79[^\n]s", item.itemName);
         BufferPurge();

         /* Prompt user to enter new item description */
         printf("Enter the item description: \n");
         scanf("%79[^\n]s", item.itemDescription);
         BufferPurge();

         /* Prompt user to enter new item price */
         printf("Enter the item price: \n");
         scanf("%d", &item.itemPrice);
         BufferPurge();

         /* Prompt user to enter new item quantity */
         printf("Enter the item quantity: \n");
         scanf("%d", &item.itemQuantity);
         BufferPurge();

         /* Add new item to cart */
         cart = AddItem(item, cart);
         printf("\n");
            break;

         /* Remove item from cart if user input 'r' or 'R' */
         case 'R':
         case 'r':
         /* Prompt user to enter new item name to remove */
         BufferPurge();
         printf("Enter name of item to remove: \n");
         scanf("%79[^\n]s", removeItem);
         BufferPurge();

         /* remove selected item from cart */
         cart = RemoveItem(removeItem, cart);
         printf("\n");
            break;
         
         /* Change item quantity if user input 'c' or 'C' */
         case 'C':
         case 'c':
         /* Initialize items */
         MakeItemBlank(&item);

         /* Prompt user to enter item name to cahnge quantity */
         BufferPurge();
         printf("Enter the item name: \n");
         scanf("%79[^\n]s", selectedItem);
         BufferPurge();

         /* Prompt user to enter new quantity for the selected item */
         printf("Enter the new quantity: \n");
         scanf("%d", &newQunatity);
         BufferPurge();

         strcpy(updateItem.itemName, selectedItem);
         updateItem.itemQuantity = newQunatity;

         /* Modify the selected item quantity */
         cart = ModifyItem(updateItem, cart);
         printf("\n");
            break;
            
         /* Output items' descriptions if user input 'i' or 'I' */
         case 'I':
         case 'i':
         PrintDescriptions(cart);
         printf("\n");
            break;

         /* Output shopping cart if user input 'o' or 'O' */
         case 'O':
         case 'o':
         PrintInvoice(cart);
         printf("\n");
            break;

         /* Program exit when user input 'q' or 'Q' */
         case 'Q':
         case 'q':
            printf(">_< Good Bye\n\n");
            break;
         
         /* Propmt user to enter a vaild option again if user entered invalid selection */
         default:
            printf("Invalid selection!\n\n");
            break;
      }
   } 
   /* menu of options will be visible again if user input any option but 'q'*/
   while (selectionMenu != 'q');
}

int main(void) {
   /* Declare variables */
   ShoppingCart cart;
   ItemToPurchase item;


   /* setup customer's name and today's date */
   printf("Enter Customer's Name: \n");
   scanf("%49[^\n]s", cart.customerName);
   BufferPurge();
   printf("Enter Today's date: \n");
   scanf("%49[^\n]s", cart.currentDate);
   BufferPurge();

   /* set the cart size to 0 */
   cart.cartSize = 0;
   printf("\n");

   /* Display the user input 'Customer Name' and user input 'Today's Date' */
   printf("Customer Name: %s\n", cart.customerName);
   printf("Today's Date: %s\n\n", cart.currentDate);

   /* Display the Program Menu */
   PrintMenu(cart, item);

   return 0;
    
}