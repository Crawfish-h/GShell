#pragma once
#include "../Globals.c"
#include <stdio.h>

static void Json_Read()
{
	FILE* json_File = fopen("json-files/json.txt", "r");

	char buffer[255];

	while (fgets(buffer, 255, json_File) != NULL)
	{
		printf("%s", buffer);
	}

	fclose(json_File);
}