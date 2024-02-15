#pragma once
#include "Capitalize.h"
#include "../Globals.c"
#include <stdio.h>
#include <ctype.h>

void Capitalize(char* user_Input)
{
	user_Input[strcspn(user_Input, "\n")] = '\0';
	Remove_Sub_Str(user_Input, "capitalize");
	int len = strlen(user_Input);
	printf("Output: ");
	for (int i = 0; i < len; i++)
	{
		printf("%c", toupper(user_Input[i]));
	}

	printf("\n");
}