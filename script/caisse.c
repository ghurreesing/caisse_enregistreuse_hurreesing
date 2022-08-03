#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


double generateRand ()
{
	double min=0;
	double max =9000;
	double randDecimal = ((double) rand()) / RAND_MAX;
	double range = (max-min) * randDecimal;
	double randNumber = min + range;
	return randNumber;
}

bool checkAmount (double temp, double userVal)
{

	if(userVal>=temp)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}


int main()
{
	double temp=0;
	double userVal;
	srand(time(NULL));

	temp=generateRand();

	printf("Amount to be paid is: %.2f rs\n",temp);
	printf("Please enter a value to pay: ");
	scanf("%lf",&userVal);


	while((checkAmount(temp,userVal))==1)
	{
		printf("Amount entered is invalid, value to be paid is %.2f",temp); 
		printf(", please enter a higher amount.\n");
		printf("Please enter a value to pay: ");
	        scanf("%lf",&userVal);

	}

	return 0;
}
