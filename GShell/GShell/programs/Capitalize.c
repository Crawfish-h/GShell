#pragma once
#include "Capitalize.h"
#include "../Globals.c"
#include <stdio.h>
#include <ctype.h>

void Capitalize()
{
	Clear_User_Input();
	printf("Input: ");
	fgets(&G_User_Input, MAX_INPUT_SIZE, stdin);
	G_User_Input[MAX_INPUT_SIZE - 1] = '\0';
	int len = strlen(G_User_Input);
	printf("Output: ");
	for (int i = 0; i < len; i++)
	{
		printf("%c", toupper(G_User_Input[i]));
	}
}