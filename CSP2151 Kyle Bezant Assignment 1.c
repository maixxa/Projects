#include<stdio.h>
int main() 
{
	float m, v, d, f; /* Establishes the float variables in the code */

	printf("Enter a number for mass, velocity and stopping distance to find the force"); /* Displays the message requesting values for the float variables*/
	scanf("%f %f %f", &m, &v, &d); /* Enables entering of 3 values and stores them in each of the variables */
	
	if (m > 0 && v > 0 && d > 0) { /* IF statement checking that all of the float values provided are above 0*/

		f = 0.5 * m; /* First calculation of the equation*/
		f = f * (v * v); /* second calculation of the equation*/
		f = f / d; /* third calculation of the equation*/

		printf("During a collision, if the vehicle is of %f kg, moving at a speed of %f km/h, and is stopped in %f m after hitting the obstacle, the overal impact of force acting on the vehicle would be %f Newtons.\n", m, v, d, f); /*Prints all values and the product in a sentence*/

	}	else { /*Else statement when one of the values was 0 or less*/
		printf("Enter a values greater than 0."); /*Message to tell the user they have entered a value less than 1 and they need to use values over 1 */
	}

	return 0;
}

