#pragma once

#include "structures.h"
#define Taille1 10
#define Taille2 10


enum etCouleurCase
{
	Jaune,
	Vert,
	Mauve,
	Rouge,
	Bleu,
	LIBRE
};

struct etCase
{
	enum etCouleurCase enCouleur;
	int Gelatine;
};

struct etMatrice
{
	struct etCase tMatrice[Taille1][Taille2];
};

void InitMat(struct etMatrice* Matrice);
void Affichage(struct etMatrice* Matrice);
void Calcul(struct etMatrice* Matrice, struct etQueue *Queue);
void Mouvement(struct etMatrice* Matrice);
void SuppV(struct etMatrice* Matrice, struct etQueue* Queue);
void SuppH(struct etMatrice* Matrice, struct etQueue* Queue);