#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include"Matrice.h"

void InitMat(struct etMatrice* Matrice)
{
	int x;
	int y;
	int random;
	int gel;


	for (x = 0; x < Taille1; x++)
	{
		for (y = 0; y < Taille2; y++)
		{
			
			random = rand() % 5;
			gel = rand() % 2;
			if (gel == 1)
			{
				Matrice->tMatrice[x][y].Gelatine = 1;
			}
			else
			{
				Matrice->tMatrice[x][y].Gelatine = 0;
			}

			if (random == 0)
			{
				Matrice->tMatrice[x][y].enCouleur = Jaune;
			}
			if (random == 1)
			{
				Matrice->tMatrice[x][y].enCouleur = Vert;
			}
			if (random == 2)
			{
				Matrice->tMatrice[x][y].enCouleur = Mauve;
			}
			if (random == 3)
			{
				Matrice->tMatrice[x][y].enCouleur = Rouge;
			}
			if (random == 4)
			{
				Matrice->tMatrice[x][y].enCouleur = Bleu;
			}

		}
	}

	return;



}