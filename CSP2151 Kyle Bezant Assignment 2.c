#include<stdio.h> /* loads a module*/
int main() /*Main function created */
{
	float m, minv, maxv, d, f, conv, maxconv, maxf; /* Establishes the float variables in the code */

	printf("Enter a number for mass, minimum velocity(km/h), maximum velocity(km/h) and stopping distance to find the force"); /* Displays the message requesting values for the float variables*/
	scanf("%f %f %f %f", &m, &minv, &maxv, &d); /* Enables entering of 3 values and stores them in each of the variables */
	
	if (m > 0 && minv > 0 && d > 0 && maxv > 0 && minv < maxv) { /* IF statement checking that all of the float values provided are above 0*/
		conv = minv * 0.277778;  /*repeat of the calcultion in the loop for the first calculation*/
		maxconv = maxv * 0.277778;  /*conversion from km/h to m/s purely for the max velocity.*/
		maxf = 0.5 * m * (maxconv * maxconv) / d;  /*calculation using the max velocity purely for the final calculation*/
		f = 0.5 * m * (conv * conv) / d;  /*repeat of the calcultion in the loop for the first calculation*/
		printf("Calculation of forces of impact for a vehicle %0.2f with stopping distance of %0.2f, and a range of velocities:\n", m, d); /*Prints all values and the product in a sentence*/
		printf("---------------+--------------+------------------\n");  /*prints part of the header*/
		printf("Velocity (km/h)|Velocity (m/s)|Force of Impact(N)\n");  /*prints part of the header*/
		printf("---------------+--------------+------------------\n");  /*prints part of the header*/
		printf("      %0.2f    |     %0.2f     |     %0.2f\n", minv, conv, f); /*prints the first calculation using the minimum which includes 2 decimal points*/

		while (minv < maxv) {  /*loop to generate all calculations when the min is lower than the maximum*/
			conv = floor(minv) * 0.277778;  /*calculation of the conversion of km/h to m/s*/
			f = 0.5 * m * (conv * conv) / d; /* calculates the force drawing from the above variable*/
			printf("         %0.0f    |     %0.2f     |     %0.2f\n", minv, conv, f); /*print of all the calculations including formating*/
			minv = minv + 1;  /*adds 1 to the float minv which holds the minimum velocity, so all the calculations are higher until the max*/
		}
		
		printf("      %0.2f    |     %0.2f     |     %0.2f\n", maxv, maxconv, maxf);  /*prints the final calculation of the max velocity after all between calculations*/
		

	}	else {  /*Else statement when one of the values was less than 0 or the minimum velocity was higher than the maximum*/
		printf("Make sure all values are greater than 0 and the minimum velocity is lower than the maximum velocity.");  /*Message to tell the user they have entered a value less than 1 and they need to use values over 1 */
	}

	return 0;
}

