#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "Matrice.h"
#include "structures.h"


//Attribution des codes couleurs pour les pions 
void Jau()
{
	printf("\033[1;33m");
	return;
}
void Rou()
{
	printf("\033[1;31m");
	return;
}
void Mau()
{
	printf("\033[1;35m");
	return;
}
void Ble()
{
	printf("\033[1;34m");
	return;
}
void Ver()
{
	printf("\033[1;32m"); 
	return;
}
void Reset()
{
	printf("\033[0m"); 
	return;
}




void Affichage(struct etMatrice *Matrice)
{
	int x;
	int y;
	int i;
	system("cls");
	printf("\n");
	printf("     ");
	for ( i = 0; i < Taille2; i++)
	{
		printf("(%d)", i); // Numéros de colonnes 
	}
	printf("\n");
	for (x = 0; x < Taille1; x++)
	{
		printf(" (%d) ", x); //Numéros de lignes
		for (y = 0; y < Taille2; y++)
		{
			if (Matrice->tMatrice[x][y].enCouleur == Jaune)
			{
				
				
				
						//Sert a afficher la présence de gélatine grâce à un fond blanc

				if (Matrice->tMatrice[x][y].Gelatine==1) 
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
					Jau();
					printf(" O");
					Reset();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					printf(" ");
				}
						//Cas général si pas de gélatine
				else
				{
					Jau();
					printf(" O ");
					Reset();

				}
			
			}
			if (Matrice->tMatrice[x][y].enCouleur == Bleu)
			{
				if (Matrice->tMatrice[x][y].Gelatine == 1)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
					Ble();
					printf(" O");
					Reset();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					printf(" ");
				}
				else
				{
					Ble();
					printf(" O ");
					Reset();
				}
			}
			if (Matrice->tMatrice[x][y].enCouleur == Mauve)
			{
				
				if (Matrice->tMatrice[x][y].Gelatine == 1)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
					Mau();
					printf(" O");
					Reset();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					printf(" ");
				}
				else
				{
					Mau();
					printf(" O ");
					Reset();
				}
				

			}
			if (Matrice->tMatrice[x][y].enCouleur == Rouge)
			{
		
				
				if (Matrice->tMatrice[x][y].Gelatine == 1)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
					Rou();
					printf(" O");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					printf(" ");
				}
				else
				{
					Rou();
					printf(" O ");
					Reset();
				}
				
			}
			if (Matrice->tMatrice[x][y].enCouleur == Vert)
			{
				
				
				if (Matrice->tMatrice[x][y].Gelatine == 1) 
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
					Ver();
					printf(" O");
					Reset();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					printf(" ");
				}
				else
				{
					Ver();
					printf(" O ");
					Reset();
				}
			}
		
			if (y == (Taille2 - 1))
			{
				printf("\n");
			}
		}
	}
	

	return;
}