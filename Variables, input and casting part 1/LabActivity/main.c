/*
*
* Author: Hesham Natouf
* Date: Tuesday 26 January 2021 08:08:41 AM
* Description: This is a program that allows the user to calculate the area of a wall,
* the gallons needed to paint the wall and the number of gallons cans needed to paint that wall.
*
*/

#include <stdio.h>
#include <math.h>                  // Note: Needed for math functions in part (3)

int main(void) {
   double wallHeight;
   double wallWidth;
   double wallArea;
   double cansNeeded;

   printf("Enter wall height (feet):\n");
   scanf("%lf", &wallHeight);

   printf("Enter wall Width (feet):\n");
   scanf("%lf", &wallWidth);                                            // FIXME (1): Prompt user to input wall's width
   
   // Calculate and output wall area
   wallArea = wallHeight * wallWidth;                                   // FIXME (1): Calculate the wall's area
   printf("Wall area: %0.2lf square feet\n", wallArea);                 // FIXME (1): Finish the output statement
   
   // FIXME (2): Calculate and output the amount of paint in gallons needed to paint the wall
   printf("Paint needed: %0.2lf gallons\n", wallArea / 350);

   // FIXME (3): Calculate and output the number of 1 gallon cans needed to paint the wall, rounded up to nearest integer
   cansNeeded = round(wallArea / 350);
   printf("Cans needed: %0.0lf can(s)\n", cansNeeded);

   return 0;
}