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


double calcule_monnaie(double temp, double userVal)
{
	double amtReturn;

	amtReturn= userVal- temp;
	return amtReturn;
}

int main()
{
	double temp=0;
	double userVal;
	double monnaie=0;
	srand(time(NULL));

	temp=generateRand();

	double billets[7]={2000,1000,500,200,100,50,25};
	double pieces[7]={20,10,5,1,0.50,0.20,0.05};

	printf("La somme  totale est de : %.2f Rs\n",temp);
	printf("Veuillez entrer la somme due : ");
	scanf("%lf",&userVal);


	while((checkAmount(temp,userVal))==1)
	{
		printf("La somme entree n'est pas valide,La somme a payer est de  %.2f Rs",temp); 
		printf(",veuillez entrer une valeur  superieur.\n");
		printf("veuillez entrer la somme due : ");
	        scanf("%lf",&userVal);
	}



	monnaie = calcule_monnaie(temp,userVal);
        printf("Monnaie à  rendre: %.2lf Rs\n",monnaie);
        printf("Monnaie  retourner,");
        while(monnaie>=0.05)
        {

                if(monnaie >= 25.00)
                {
                	for(int i=0;i<7;i++)
                  	{
                        	if(monnaie>=billets[i])
                        	{
                                	printf(" %.2fRs", billets[i]);
                                	monnaie= monnaie - billets[i];
                        	}
                  	}
                }

                if(monnaie <25.00)
                {
                	for(int j=0;j<7;j++)
                	{
                        	if(monnaie>=pieces[j])
                        	{
                                	printf(" %.2fRs",pieces[j]);
                                	monnaie= monnaie - pieces[j];
                        	}
                  	}
                }
        }
	printf("\n");

	return 0;
}
