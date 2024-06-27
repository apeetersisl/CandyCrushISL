#include <stdio.h>
#include <string.h>
#include "Matrice.h"
#include "structures.h"

void Calcul(struct etMatrice* Matrice, struct etQueue* Queue)
{
	int x;
	int y;
	char Action[20];
	
	
	//Vérification verticale=> si 3 pions alignés, on envoie les coord du premier et dernier pion ainsi que le nom de l'action a effectuer.
	// SI PLUS DE 3 PIONS ALLIGNES =>> 
	//SUPPH et SUPPV le détectent et font la suppression
	
	
	
	for (y = 0; y < Taille2; y++)
	{
		for (x = 0; x < Taille1 - 2; x++)
		{
			if (Matrice->tMatrice[x][y].enCouleur == Matrice->tMatrice[x + 1][y].enCouleur && Matrice->tMatrice[x][y].enCouleur == Matrice->tMatrice[x + 2][y].enCouleur)
			{
				strcpy_s(Action,"Suppression-V");
				
				Queue->stEvent[Queue->Next].stPositions.stPion1x = x;
				Queue->stEvent[Queue->Next].stPositions.stPion2x = x + 2;
				Queue->stEvent[Queue->Next].stPositions.stPion1y = y;
				Queue->stEvent[Queue->Next].stPositions.stPion2y = y;
				Add(Queue, Action);
				return;
			}
		}
	}

	//Vérification Horizontale => si 3 pions alignés, on envoie les coord du premier et dernier pion DANS LA QUEUE POUR L'ACTION CORRESPONDANTE 
	// Ainsi que le nom de l'action a effectuer.
	// SI PLUS DE 3 PIONS ALLIGNES =>> 
	//SUPPH et SUPPV le détectent et font la suppression
	
	
	for (x = 0; x < Taille1; x++)
	{
		for (y = 0; y < Taille2 - 2; y++)
		{
			if (Matrice->tMatrice[x][y].enCouleur == Matrice->tMatrice[x][y + 1].enCouleur && Matrice->tMatrice[x][y].enCouleur == Matrice->tMatrice[x][y + 2].enCouleur)
			{
				strcpy_s(Action, "Suppression-H");
				
				Queue->stEvent[Queue->Next].stPositions.stPion1x = x;
				Queue->stEvent[Queue->Next].stPositions.stPion2x = x;
				Queue->stEvent[Queue->Next].stPositions.stPion1y = y;
				Queue->stEvent[Queue->Next].stPositions.stPion2y = (y + 2);
				
				Add(Queue, Action);
				return;
			}

		}
	}
	

	//Vérification de la présence de gélatine dans le tableau---> Si pas de gélatine==>Fin du jeu 
	
	
	int Vict = 0;
	for ( x = 0; x < Taille1; x++)
	{
		for (y = 0; y < Taille2; y++)
		{
			if (Matrice->tMatrice[x][y].Gelatine== 1)
			{
				Vict = Vict++;

			}
		}
	}
	if (Vict==0)
	{
		strcpy_s(Action, "Gagne");
		Add(Queue, Action);
		return;
	}
	

	//Si rien a supprimer ==> Affiche la nouvelle grille puis demande le mouvement

	
	strcpy_s(Action, "Affichage");
	Add(Queue, Action);

	strcpy_s(Action, "Mouvement");
	Add(Queue, Action);

	return;







}