/*
* Author: Hesham Natouf
* Date: Thursday 18 Frbruary 2021 011:02:28 PM PDT
* Description: This Lab Warmup is a program that will Prompt the user being five numbers being people's weights. 
* Store the numbers in an array of doubles. Output the array's numbers on one line, each number followed by one space.
*/
#include <stdio.h>

const int TEAM_SIZE = 5;

int main(void) {

double totalWeight = 0.0;
double maxWeight = 0.0;
/* Declare array of 5 doubles */
double teamWeights[TEAM_SIZE];

/* Read weights and store in array */
for (int i = 0; i < TEAM_SIZE; i++) {
   int rc = 0;
   while (rc == 0) {
   printf("Enter weight %d: \n",(i + 1));
   rc = scanf("%lf", &(teamWeights[i]));
   
   /* Consume all remaining characters is input buffer */ 
   while( getchar() != '\n');
   }
}

/* Display weights on a single line */
printf("You entered: ");
for (int i = 0; i < TEAM_SIZE; i++) {
   printf("%0.2lf ", teamWeights[i]);
}
printf("\n\n");

/* Display the total weight */
for (int i = 0; i < TEAM_SIZE; i++) {
   totalWeight += teamWeights[i];
}
printf("Total weight: %0.2lf\n", totalWeight);
/* Display the average of the array's elements */
printf("Average weight: %0.2lf\n", totalWeight / TEAM_SIZE);

/* Display max array element */
 maxWeight = teamWeights[0];
for (int i = 0; i < TEAM_SIZE; ++i) {
   if (teamWeights[i] > maxWeight) {
      maxWeight = teamWeights[i];
   }
}
printf("Max weight: %0.2lf\n", maxWeight);

return 0;
}