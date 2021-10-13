/*
* Author: Hesham Natouf
* Date: Thursday 18 Frbruary 2021 011:02:28 PM PDT
* Description: This Lab activity is a program that will store roster and rating information for a soccer team.
*/

#include <stdio.h>

const int NUM_VAL = 5;

int main(void) {

int playerNum[NUM_VAL];
int playerRate[NUM_VAL];
char selectionMenu;
int playerNumber = 0, playerRating = 0;
int newPlayerNum = 0, newPlayerRate = 0;

/* Part 1: Prompt the user to input five pairs of numbers: A player's jersey number (0 - 99) and the player's rating (1 - 9) */
for (int i = 0; i < NUM_VAL; i++) {
   int rc = 0;
   /* player's jersey number (0 - 99) */
   printf("Enter player %d's jersey number:\n",(i + 1));
   rc = scanf("%d", &(playerNum[i]));
      /* Condition check: if user entered unrecognized input, program will exit. */
      if (rc == 0) {
         printf("Error: Unrecognized input, please enter only integer values.\n");
      return 1;
      }
   /* 
   * Condition check: if user entered intgers either less than 0 or more than a 100,
   * user will be asked again to enter a vaild player number.
   */
   while (playerNum[i] > 99 || playerNum[i] < 0) {
      printf("Invalid input, player's jersey number (0 - 99)\n");
      printf("Enter player %d's jersey number:\n",(i + 1));
      scanf("%d", &(playerNum[i]));
   }
   /* player's jersey rating (1 - 9) */
   printf("Enter player %d's rating:\n",(i + 1));
   rc = scanf("%d", &(playerRate[i]));
      /* Condition check: if user entered unrecognized input, program will exit. */
      if (rc == 0) {
         printf("Error: Unrecognized input, please enter only integer values.\n");
      return 1;
      }
   /* 
   * Condition check: if user entered intgers either less than 1 or more than a 9, 
   * user will be asked again to enter a vaild player rate.
   */
   while (playerRate[i] > 9 || playerRate[i] < 1) {
      printf("Invalid input, player's jersey rating (1 - 9)\n");
      printf("Enter player %d's rating:\n",(i + 1));
      scanf("%d", &(playerRate[i]));
   }
   printf("\n");
}
/* Part 2: Output the roster */
printf("ROSTER\n");
for (int i = 0; i < NUM_VAL; i++) {
   printf("Player %d -- Jersey number: %d, Rating: %d\n",(i + 1), playerNum[i], playerRate[i]);
}
printf("\n\n");
/* Part 3: Implement a menu of options for a user to modify the roster. Each option is represented by a single character. */
do { 
   printf("MENU\n");
   printf("u - Update player rating\n");
   printf("a - Output players above a rating\n");
   printf("r - Replace player\n");
   printf("o - Output roster\n");
   printf("q - Quit\n\n");

   printf("Choose an option: ");
   scanf(" %c", &selectionMenu);
   printf("\n");

   switch(selectionMenu){
      /* Implement the "Update player rating" menu option. */
      /*
      * Prompt the user for a player's jersey number. 
      * Prompt again for a new rating for the player, 
      * and then change that player's rating.
      */
      case 'U':
      case 'u':
         printf("Enter a jersey number: \n");
         scanf("%d", &playerNumber);
         printf("Enter a new rating for player: \n");
         scanf("%d", &playerRating);
         for (int i = 0; i < NUM_VAL; i++) {
            if (playerNum[i] == playerNumber) {
               playerRate[i] = playerRating;
            }
         }
         printf("\n");
         break;
      /* Implement the "Output players above a rating" menu option. */
      /*
      * Prompt the user for a rating. 
      * Print the jersey number and rating for all players with 
      * ratings above the entered value.
      */
      case 'A':
      case 'a':
         printf("Enter a rating: \n");
         scanf("%d", &playerRating);
         printf("ABOVE %d\n", playerRating);
         for (int i = 0; i < NUM_VAL; i++) {
            if (playerRating < playerRate[i]) {
               printf("Player %d -- Jersey number: %d, Rating: %d\n", (i + 1), playerNum[i], playerRate[i]);
            }
         }
         printf("\n");
         break;
      /* Implement the "Replace player" menu option. */
      /*
      * Prompt the user for the jersey number of the player to replace. 
      * If the player is in the roster, 
      * then prompt again for a new jersey number and rating. 
      * Update the replaced player's jersey number and rating.
      */
      case 'R':
      case 'r':
         printf("Enter a jersey number: \n");
         scanf("%d", &playerNumber);
         printf("Enter a new jersey number: \n");
         scanf("%d", &newPlayerNum);
         printf("Enter a rating for the new player: \n");
         scanf("%d", &newPlayerRate);
         for (int i = 0; i < NUM_VAL; i++) {
            while ((newPlayerNum == playerNum[i]) & (newPlayerRate == playerRate[i])) {
               printf("\nError: Player already in the roster!!\n");
               printf("Enter a new jersey number: \n");
               scanf("%d", &newPlayerNum);
               printf("Enter a rating for the new player: \n");
               scanf("%d", &newPlayerRate);
            }
         }
         for (int i = 0; i < NUM_VAL; i++) {
            if (playerNum[i] == playerNumber) {
                playerNum[i] = newPlayerNum;
                playerRate[i] = newPlayerRate;
            }
         }
         printf("\n");
         break;
      /* Implement the "Output roster" menu option */
      case 'O':
      case 'o':
         printf("ROSTER\n");
         for (int i = 0; i < NUM_VAL; i++) {
            printf("Player %d -- Jersey number: %d, Rating: %d\n",(i + 1), playerNum[i], playerRate[i]);
         }
         printf("\n");
         break;
      /* Implement the "Quit" menu option */
      case 'Q':
      case 'q':
         printf("GoodBye!\n");
         printf("\n");
         break;
      /* if user entred something that is not in the menu of options */
      default:
         printf("Invalid selection!\n");
         printf("\n");
         break;
   }
   /* menu of options will be visible again if user input any option but 'q'*/
} while (selectionMenu != 'q');

return 0;
}