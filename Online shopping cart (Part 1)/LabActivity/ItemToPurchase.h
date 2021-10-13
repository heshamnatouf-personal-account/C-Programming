#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#define MAX_ITEM_NAME_SIZE 80

/* Define itemtopurchase struct */
struct itemtopurchase {
    char itemName [MAX_ITEM_NAME_SIZE];         // 80 bytes
    char itemDescription [MAX_ITEM_NAME_SIZE];  // 80 bytes
    int itemPrice;                              //  4 bytes
    int itemQuantity;                           //  4 bytes

};

/* Define ItemToPurchase type */
typedef struct itemtopurchase ItemToPurchase;

/* MakeItemBlank: Intialize the field in the 
 *     spectified ItemToPurchase struct
 * item - pointer to ItemToPurchase object
 * return - 0 on success. -1 on error 
 */
int MakeItemBlank(ItemToPurchase * itemPtr);



/* PrintItemCost: Display item cost
 *     by printing to stdout
 * item - ItemToPurchase object to be displayed
 */
void PrintItemCost(ItemToPurchase item);


/* PrintItemCost: Display item Description
 * item - ItemToPurchase object to be displayed
 */
void PrintItemDescription(ItemToPurchase item);

#endif