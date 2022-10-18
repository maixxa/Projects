#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	struct Vehicle { /*this creates a structure called 'Vehicle'*/


		int Vehicle_Number; /*first variable is an integer for vehicle position in the list*/
		char Vehicle_Name[50]; /*same as above for the name rather than manufacturer*/
		int First_Manufactured;  /*integer that holds the date the vehicle was manufactured*/
		float Top_Speed;  /*a float that holds the top speed figure*/
		float Mass;  /*a float to hold the mass figure*/
		int Number_Of_Seats;  /*integer that will hold the number of seats.*/
	
	};

	struct Obstacle { /*this creates a structure called 'Vehicle'*/


		int Obstacle_number;
		char Obstacle_Name;
		int Stopping_distance;
	
	};

	int v_Num;
	char v_Name[500];
	int f_Man;
	float t_Speed;
	float m;
	int n_Seats;
	
int main ()
{
	int i = 0, b;
	char line[500];
	char search [500];
	int ch=0;
	char thing[] = "";
	char every[] = "all";
	struct Vehicle vStruct;
	int no_of_vehicles=0;

	
	
	printf("Please select an operation below\n Enter 1 to search for a vehicle\n 2 to search for an obstacle\n 3 Input/update a vehicle\n 4 Input/update an obstacle\n 5 to Calculate the force of impact using the currently stored vehicles and obstacles");
	scanf("%d", &i);
	
	if (i == 1){
		
		FILE* vehicleFile = fopen ("Vehicle.txt","r");
		
	
		if (vehicleFile == NULL){ 
			printf("Error %d \n", errno);/*printf("Could not open file vehicleFile\n");
			exit(1);*/
		} 
		
	
		no_of_vehicles=b;
		
		printf("Enter a word to search for a vehicle or use 'All' to show all vehicles.");
		scanf(" %c", &thing);
		b=0;
		while(fscanf(vehicleFile, "%d, %s, %d, %f, %f, %d", &v_Num, v_Name, &f_Man, &t_Speed, &m, &n_Seats)==6)
			{
			vStruct.Vehicle_Number = v_Num;
			strcpy(vStruct.Vehicle_Name, v_Name);
			vStruct.First_Manufactured = f_Man;
			vStruct.Top_Speed = t_Speed;
			vStruct.Mass = m;
			vStruct.Number_Of_Seats = n_Seats;
			b++;
			}
			
		if (strcmp(thing,every)){
			
			for (b=0; b< no_of_vehicles; b++)
			{ /*while(fgets(line, 128, vehicleFile) !=NULL){*/
				printf("%d, %s, %d, %f, %f, %d", vStruct.Vehicle_Number, vStruct.Vehicle_Name, v_Name, vStruct.First_Manufactured, vStruct.Top_Speed, vStruct.Mass, vStruct.Number_Of_Seats);
				fclose(vehicleFile);
			}
		}

		else {
		fclose(vehicleFile);
		}
		
		fclose(vehicleFile);

		return 0;
	}
		
	if (i == 2){
		FILE* obstacleFile = fopen ("Obstacle.txt","r");
		while(fgets(line, 128, obstacleFile) !=NULL){
			printf("%c",line); 
		fclose(obstacleFile);  
		return 0;
	}
	}
	if (i == 3){
		
		FILE* vehicleFile = fopen ("Vehicle.txt","r");
		
		if (vehicleFile == NULL)
		{
			printf("Error %d \n", errno);
			/*printf("Could not open file vehicleFile\n");
			exit(1);*/
		}
		
		printf("Enter 1 to update a current vehicle and 2 to add a new vehicle: ");
		scanf("%d", &ch);
	
	
		
		if (ch == 1){
			printf ("Enter the vehicle number of the vehicle you would like to update");
		
		}
		else if (ch == 2){
			printf ("First provide a name for the vehicle, followed by the first year of manufacture, the top speed and finally number of seats the vehicle has");
			scanf ( "%c, %d, %f, %f, %d", v_Name, &f_Man, &t_Speed, &m, &n_Seats);
			fprintf(vehicleFile, "%s, %d, %f, %f, %d", vStruct.Vehicle_Name, vStruct.First_Manufactured, vStruct.Top_Speed, vStruct.Mass, vStruct.Number_Of_Seats);
			return 0;
		}
		return 0;
		fclose(vehicleFile);
	}
	return 0;
}

