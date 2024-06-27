#pragma once
struct etPositions
{
	int stPion1x;
	int stPion1y;
	int stPion2x;
	int stPion2y;
};

struct etAction
{
	char stAction[50] ;
	struct etPositions stPositions;
};

struct etQueue
{
	struct etAction stEvent[1000];
	int Debut = 0;
	int Fin = 999;
	int Next = 0;
	int Top = 0;
};

void InitQueue(struct etQueue* Queue);
int Get(struct etQueue* Queue);
void Add(struct etQueue* Queue, char* Action);