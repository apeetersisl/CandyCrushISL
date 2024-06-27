#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "Matrice.h"

int Get(struct etQueue *Queue)
{
	int x = 0;
	if (strcmp(Queue->stEvent[Queue->Top].stAction, "Initialisation") == 0)
	{
		x = 1;
		
	}
	if (strcmp(Queue->stEvent[Queue->Top].stAction, "Calcul") == 0)
	{
		x = 2;

	}
	if (strcmp(Queue->stEvent[Queue->Top].stAction, "Suppression-H") == 0)
	{
		x = 3;

	}
	if (strcmp(Queue->stEvent[Queue->Top].stAction, "Suppression-V") == 0)
	{
		x = 4;

	}
	if (strcmp(Queue->stEvent[Queue->Top].stAction, "Mouvement") == 0)
	{
		x = 5;

	}
	if (strcmp(Queue->stEvent[Queue->Top].stAction, "Affichage") == 0)
	{
		x = 6;

	}
	if (strcmp(Queue->stEvent[Queue->Top].stAction, "Gagne") == 0)
	{
		x = 7;

	}
	
	printf("%s", Queue->stEvent[Queue->Top].stAction);
	
	

	return x;
}









void InitQueue(struct etQueue* Queue)
{
	int i;
	for ( i = 0; i < (Queue->Fin)+1; i++)
	{
		Queue->stEvent[i].stAction[0] = '\0';
		Queue->stEvent[i].stPositions.stPion1x = 0;
		Queue->stEvent[i].stPositions.stPion1y = 0;
		Queue->stEvent[i].stPositions.stPion2x = 0;
		Queue->stEvent[i].stPositions.stPion2y = 0;
	}
	return;
}


void Add(struct etQueue* Queue, char* Action)
{
	strcpy_s(Queue->stEvent[Queue->Next].stAction, Action);

	if (Queue->Next == Queue->Fin)
	{
		Queue->Next = Queue->Debut;
	}
	else
	{
		Queue->Next = (Queue->Next)+1;
	}
	return;

}