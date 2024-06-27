#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"Matrice.h"
#include"structures.h"



void SuppV(struct etMatrice* Matrice, struct etQueue* Queue)
{

	int x;

	int xt, xt2, yt;
	etCouleurCase couleur;
	//Récupération coord

	xt = Queue->stEvent[Queue->Top].stPositions.stPion1x;
	xt2 = Queue->stEvent[Queue->Top].stPositions.stPion2x;
	yt= Queue->stEvent[Queue->Top].stPositions.stPion1y;


	//Check si + de 3 pions de couleurs
	couleur = Matrice->tMatrice[xt2][yt].enCouleur;
	while (xt2<Taille1-1 && Matrice->tMatrice[xt2+1][yt].enCouleur==couleur)
	{
		++xt2;
	}
	
	//Suppression des pions en les marquant LIBRES et supprime la gélatine
	for (x = xt; x <= xt2; x++)
	{
		Matrice->tMatrice[x][yt].enCouleur = LIBRE;
		Matrice->tMatrice[x][yt].Gelatine = 0;
	}
	//Descente des pions au dessus s'il le faut
	

	
	for (x = xt2; x >= xt2-xt+1; x--)
	{
		Matrice->tMatrice[x][yt].enCouleur = Matrice->tMatrice[x-(xt2 - xt + 1)][yt].enCouleur;
	}

	//Regénération de pions dans les cases vides.
	
	for (x = 0; x < xt2 - xt + 1; x++)
	{
		
		int random = rand() % 5;
		if (random == 0)
		{
			Matrice->tMatrice[x][yt].enCouleur = Jaune;
		}
		if (random == 1)
		{
			Matrice->tMatrice[x][yt].enCouleur = Vert;
		}
		if (random == 2)
		{
			Matrice->tMatrice[x][yt].enCouleur = Mauve;
		}
		if (random == 3)
		{
			Matrice->tMatrice[x][yt].enCouleur = Rouge;
		}
		if (random == 4)
		{
			Matrice->tMatrice[x][yt].enCouleur = Bleu;
		}
	}
	
	Affichage(Matrice);
	return;

}

void SuppH(struct etMatrice* Matrice, struct etQueue* Queue)
{
	etCouleurCase couleur;
	int y;
	int x;
	int xt, yt, yt2;

	//Recup Coord
	xt = Queue->stEvent[Queue->Top].stPositions.stPion1x;
	yt= Queue->stEvent[Queue->Top].stPositions.stPion1y;
	yt2= Queue->stEvent[Queue->Top].stPositions.stPion2y;
	
	//Check si + de 3 pions de couleurs
	couleur = Matrice->tMatrice[xt][yt2].enCouleur;
	while (yt2 < Taille2 - 1 && Matrice->tMatrice[xt][yt2+1].enCouleur == couleur)
	{
		++yt2;
	}

	//Suppression des pions et de la gélatine
	for (y = yt; y <= yt2; y++)
	{
		Matrice->tMatrice[xt][y].enCouleur = LIBRE;
		Matrice->tMatrice[xt][y].Gelatine = 0;
	}
	
	
	//Descente des pions au dessus s'il le faut 

	for (x = xt; x > 0; x--)
	{

		for (y = 0; y < yt2 -yt +1; y++)
		{

			
			int random = rand() % 5;
			Matrice->tMatrice[x][yt + y].enCouleur = Matrice->tMatrice[x - 1][yt + y].enCouleur;
			
			
			
		}
	}
	
	//REGENERATION
	for ( y = 0; y < 3; y++)
	{
		int random = rand() % 5;
		
		if (random == 0)
		{
			Matrice->tMatrice[0][yt + y].enCouleur = Jaune;
		}
		if (random == 1)
		{
			Matrice->tMatrice[0][yt + y].enCouleur = Vert;
		}
		if (random == 2)
		{
			Matrice->tMatrice[0][yt + y].enCouleur = Mauve;
		}
		if (random == 3)
		{
			Matrice->tMatrice[0][yt + y].enCouleur = Rouge;
		}
		if (random == 4)
		{
			Matrice->tMatrice[0][yt + y].enCouleur = Bleu;
		}
	}

	Affichage(Matrice);
	return;
}