#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "ShoppingCart.h"

ShoppingCart AddItem(ItemToPurchase item, ShoppingCart cart) {
    /* Declare variables */
    int capacityCheck = 10;
    /* Checking the capacity of the cart before adding new item*/
    if (cart.cartSize == capacityCheck) {
        printf("\nThe item was not added because the ShoppingCart is full.\n");
    } else {
        /* Adding new item */
        cart.cartItems[cart.cartSize] = item;
        cart.cartSize++;
    }
    return cart;
}

ShoppingCart RemoveItem(char name[], ShoppingCart cart) {
    /* Declare variables */
    int i = 0;
    int index = 0;
    while (i < cart.cartSize) {
        /* serching in the ShoppingCart for item that matches the name of the specified item.*/
        if(strcmp(name, cart.cartItems[i].itemName) == 0) {
            index = 1;
            /* break out of the loob */
            break;
        }
        i++;
    }
    if (index == 0) {
        /* Prompt user with this message of no matching item found in the cart */
        printf("\nNo matching items were found. No changes made. \n");
    } else {
        for(int j = i; j < cart.cartSize - 1; j++) {
            cart.cartItems[j] = cart.cartItems[j + 1];
        }
        cart.cartSize--;
    }
    return cart;
}

ShoppingCart ModifyItem(ItemToPurchase item, ShoppingCart cart) {
    /* Declare variables */
    int i = 0;
    int index = 0;
    while (i < cart.cartSize) {
        /* serching in the ShoppingCart for item that matches the name of the specified item.*/
        if(strcmp(item.itemName, cart.cartItems[i].itemName) == 0) {
            index = 1;
            /* break out of the loob */
            break;
        }
        i++;
    }
    if (index == 0) {
        /* Prompt user with this message of no matching item found in the cart */
        printf("\nNo matching items were found. No changes made. \n");
        } else {
            /* Update the itemQuantity */
            if (item.itemQuantity != 0) {
                cart.cartItems[i].itemQuantity = item.itemQuantity;
            /* Update the itemPrice */
            } else if ((item.itemPrice != 0)) {
                cart.cartItems[i].itemPrice = item.itemPrice;
            /* Update the itemDescription */
            } else if (strcmp(item.itemDescription, "") != 0) {
                strcpy(cart.cartItems[i].itemDescription, item.itemDescription);
            }
        }
    return cart;
}

int GetNumItemsInCart(ShoppingCart cart) {
    /* Declare variables */
    int NumItemsInCart = 0;

    /* Calculate the total number of items in the shopping cart */
    for(int i = 0; i < cart.cartSize; i++) {
        NumItemsInCart = NumItemsInCart + cart.cartItems[i].itemQuantity;
    }
    /* Return the total number of item in the cart */
    return NumItemsInCart;
}

int GetCostOfCart(ShoppingCart cart) {
    /* Declare variables */
    int CostOfCart = 0;

    /* Calculate the total cost of all items in the specified ShoppingCart */
    for(int i = 0; i < cart.cartSize; i++) {
        CostOfCart = CostOfCart + 
        (cart.cartItems[i].itemPrice * 
         cart.cartItems[i].itemQuantity);
    }
    /* return the total cost of items in the cart */
    return CostOfCart;
}

void PrintInvoice(ShoppingCart cart) {
    /* Display the ShoppingCart details, icluding input customerName and  input currentDate */
    printf("%s's Shopping Cart - %s\n", cart.customerName, cart.currentDate);
    printf("Number of items: %d\n", GetNumItemsInCart(cart));
    printf("\n");

    for (int i = 0; i < cart.cartSize; i++) {
        PrintItemCost(cart.cartItems[i]);
    }

    printf("\nTotal: $%d\n", GetCostOfCart(cart));
}

void PrintDescriptions(ShoppingCart cart) {
    /* Display all items discripation that were stored in the cart */
    printf("%s's Shopping Cart - %s\n", cart.customerName, cart.currentDate);
    printf("\n");
    printf("Item Description\n");

    for (int i = 0; i < cart.cartSize; i++) {
        PrintItemDescription(cart.cartItems[i]);
    }
}