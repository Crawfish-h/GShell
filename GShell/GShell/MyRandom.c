#include "MyRandom.h"
#include <stdio.h> 
#include <stdlib.h> 

int IRandom(int Min, int Max)
{
	return (rand() % (Max - Min + 1)) + Min;
}