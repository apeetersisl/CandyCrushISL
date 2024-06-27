#include "Matrice.h"
#include "structures.h"
#include <stdio.h>
#include <stdlib.h>


void Mouvement(struct etMatrice* Matrice)
{
	int x1;
	int y1;
	int x2;
	int y2;

	printf("\nEntrez la colonne du premier pion a deplacer :");
	scanf_s("%d", &y1);

	printf("Entrez la ligne du premier pion a deplacer :");
	scanf_s("%d", &x1);

	printf("Entrez la colonne du deuxième pion a deplacer :");
	scanf_s("%d", &y2);

	printf("Entrez la ligne du deuxième pion a deplacer :");
	scanf_s("%d", &x2);

	while (y1>=Taille2 || y2 >= Taille2 || x1 >= Taille1 || x2 >= Taille1)
	{
		printf("Veuillez choisir des colones et des lignes dans les limites du tableau. \n");
		printf("Entrez la colonne du premier pion a deplacer :");
		scanf_s("%d", &y1);

		printf("Entrez la ligne du premier pion a deplacer :");
		scanf_s("%d", &x1);

		printf("Entrez la colonne du deuxième pion a deplacer :");
		scanf_s("%d", &y2);

		printf("Entrez la ligne du deuxième pion a deplacer :");
		scanf_s("%d", &x2);
	}

	while (abs(y1 - y2) + abs(x1 - x2) > 1)
	{
		printf("Veuillez choisir deux pions dans des lignes et colonnes adjacentes \n");
		printf("Entrez la colonne du premier pion a deplacer :");
		scanf_s("%d", &y1);

		printf("Entrez la ligne du premier pion a deplacer :");
		scanf_s("%d", &x1);

		printf("Entrez la colonne du deuxième pion a deplacer :");
		scanf_s("%d", &y2);

		printf("Entrez la ligne du deuxième pion a deplacer :");
		scanf_s("%d", &x2);

	}

	while (y1 == y2 && x1 == x2)
	{
		printf("Veuillez choisir deux pions différents \n");
		printf("Entrez la colonne du premier pion a deplacer :");
		scanf_s("%d", &y1);

		printf("Entrez la ligne du premier pion a deplacer :");
		scanf_s("%d", &x1);

		printf("Entrez la colonne du deuxième pion a deplacer :");
		scanf_s("%d", &y2);

		printf("Entrez la ligne du deuxième pion a deplacer :");
		scanf_s("%d", &x2);
	}

	int Color1 = Matrice->tMatrice[x1][y1].enCouleur;
	int Color2 = Matrice->tMatrice[x2][y2].enCouleur;
	
	//Mouvement a proprement dit des pions

	Matrice->tMatrice[x1][y1].enCouleur = (etCouleurCase) Color2;
	Matrice->tMatrice[x2][y2].enCouleur = (etCouleurCase) Color1;

	//Affichage pour DEBUG => Enlever le clear dans la fonction AFFICHAGE pour le voir

	Affichage(Matrice);
	

	return;
}