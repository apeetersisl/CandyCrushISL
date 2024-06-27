
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include<time.h>
#include <Windows.h>
#include "Matrice.h"
#include "structures.h"
#include <Windows.h>

int main()
{
	srand(time(NULL));

	struct etQueue Queue;
	struct etMatrice Matrice;
	int Gaction;
	char Action[30];

	InitQueue(&Queue);
	

	strcpy_s(Action, "Initialisation");
	Add(&Queue, Action);
	Gaction = Get(&Queue);

	while (Gaction != 7)
	{
		/*
		Sert a voir le numéro d'action en cours et l'action prochaine dans la queue si elle a déjà été mise dedans		
		printf("\n ---------%d-------- \n", Gaction);
		printf("\n ---%s--- \n",Queue.stEvent[(Queue.Top)+1].stAction);
		Gaction = 1 ===> Initialisation
		Gaction = 2 ===> Calcul
		Gaction = 3 ===> Suppression-H
		Gaction = 4 ===> Suppression-V
		Gaction = 5 ===> Mouvement
		Gaction = 6 ===> Affichage
		Gaction = 7 ===> Gagne
		*/


		//Initialisation

		if (Gaction == 1)
		{
			InitMat(&Matrice);
		
			strcpy_s(Action, "Affichage");
			Add(&Queue, Action);
			strcpy_s(Action , "Calcul");
			Add(&Queue, Action);
		
		}

		//Calcul

		if (Gaction==2)
		{
			Calcul(&Matrice, &Queue);
			
		}

		//Affichage

		 if (Gaction == 6)
		{
			Affichage(&Matrice);
		
		}

		 //Mouvement

		if (Gaction==5)
		{
			Mouvement(&Matrice);
			strcpy_s(Action, "Calcul");
			Add(&Queue, Action);

		}

		//SuppV

		if (Gaction==4)
		{
			SuppV(&Matrice, &Queue);
			strcpy_s(Action, "Calcul");
			Add(&Queue, Action);

		}

		//SuppH

		if (Gaction==3)
		{
			SuppH(&Matrice, &Queue);
			strcpy_s(Action, "Calcul");
			Add(&Queue, Action);
			
		}

		Queue.stEvent[Queue.Top].stAction[0] = '\0';

		Queue.Top = (Queue.Top) + 1;
		if (Queue.Top > Queue.Fin)
		{
			Queue.Top = Queue.Debut;
		}


		Gaction = Get(&Queue);
	
	}
	
	//PERMET DE NE PAS SURCHARGER LA CONSOLE

	system("cls");
	
	
	
	printf("Bravo, vous avez gagne !");
}

