#pragma once
#include "Text_Editor.h"
#include "../Globals.c"
#include "../MyRandom.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <io.h>
#define F_OK 0
#define access _access

long Get_File_Size(FILE* file)
{
	long prev = ftell(file);
	fseek(file, 0L, SEEK_END);
	long file_Size = ftell(file);
	fseek(file, prev, SEEK_SET);

	return file_Size;
}

size_t Get_Largest_Line(FILE* file)
{
	size_t largest = 0;
	size_t current = 0;
	int ch;

	if (file)
	{
		while ((ch = fgetc(file)) != EOF)
		{
			if (ch == '\n')
			{
				if (current > largest) largest = current;
				current = 0;
			}else
			{
				current++;
			}
		}

		if (current > largest) largest = current;
	}

	return largest;
}

int File_Exists(const char* fname)
{
	if (access(fname, F_OK) == 0)
	{
		// File exists.
		return 1;
	}else
	{
		// File does not exist.
		return 0;
	}
}

void Edit_Text_File(FILE* text_File, int max_Line_Number, char* buffer, long buffer_Size)
{
	printf("\nEnter a line number to edit that line.\n");
	printf("Line number: ");
	Clear_User_Input();
	fgets(&G_User_Input, MAX_INPUT_SIZE, stdin);

	const int len = strlen(G_User_Input);

	for (int i = 0; i < len; i++)
	{
		if (!isdigit(G_User_Input[i]) || atoi(G_User_Input) > max_Line_Number)
		{
			printf("\n\n\n");
			printf("Please make sure your input is a line number listed in the text file.\n");
			Edit_Text_File(text_File, max_Line_Number, buffer, buffer_Size);
			return;
		}
	}
	

	int line_Number = 0;
	while (fgets(buffer, buffer_Size, text_File) != NULL)
	{
		if (atoi(G_User_Input) == line_Number)
		{

		}else if (atoi(G_User_Input) > max_Line_Number)
		{

		}

		line_Number++;

	}

	if (strcmp(G_User_Input, "a\n") == 0)
	{

	}

	fclose(text_File);
}

void Open_Text_File_()
{
	Clear_User_Input();
	printf("File Name: ");
	fgets(&G_User_Input, MAX_INPUT_SIZE, stdin);
	G_User_Input[MAX_INPUT_SIZE - 1] = '\0';

	char text_File_Path[19 + MAX_INPUT_SIZE] = "programs\\text-files\\";

	strncat_s(text_File_Path, 19 + MAX_INPUT_SIZE, G_User_Input, MAX_INPUT_SIZE);

	text_File_Path[strcspn(text_File_Path, "\n")] = 0;

	FILE* text_File;
	fopen_s(&text_File, text_File_Path, "r");

	if (!text_File)
	{
		printf("ERROR: unable to open text file: %s!!\n", text_File_Path);
	}else
	{
		long buffer_Size = Get_File_Size(text_File);
		char* buffer = malloc(buffer_Size * sizeof(char));

		if (buffer == NULL)
		{
			printf("ERROR: Memory was not allocated for printing a text file!!.\n");
			return;
		}

		int line_Number = 0;
		while (fgets(buffer, buffer_Size, text_File) != NULL)
		{
			line_Number++;
			printf("%d. ", line_Number);
			printf("%s", buffer);
		}

		printf("\n\n");

		//Edit_Text_File(text_File, line_Number, buffer, buffer_Size);
		free(buffer);
	}

	if (text_File)
	{
		fclose(text_File);
	}
}

FILE* Create_New_Text_File()
{
	int file_Was_Created = 0;
	char text_File_Path[19 + MAX_INPUT_SIZE] = "programs\\text-files\\";
	File_Exists(text_File_Path);
	while (file_Was_Created == 0)
	{
		Clear_User_Input();
		printf("\nNew File Name: ");
		fgets(&G_User_Input, MAX_INPUT_SIZE, stdin);
		G_User_Input[MAX_INPUT_SIZE - 1] = '\0';

		memset(text_File_Path, '\0', sizeof(text_File_Path));
		strcpy_s(text_File_Path, sizeof(text_File_Path), "programs\\text-files\\");
		strncat_s(text_File_Path, 19 + MAX_INPUT_SIZE, G_User_Input, MAX_INPUT_SIZE);

		text_File_Path[strcspn(text_File_Path, "\n")] = 0;

		if (File_Exists(text_File_Path) == 1)
		{
			printf("A file named '%s' Already exists!!", text_File_Path);
		}else
		{
			file_Was_Created = 1;
			break;
		}
	}

	G_User_Input[strcspn(G_User_Input, "\n")] = 0;

	FILE* new_File;
	fopen_s(&new_File, text_File_Path, "a");

	if (!new_File)
	{
		printf("ERROR: new file could not be created!!\n");
		return;
	}

	fclose(new_File);
	fopen_s(&new_File, text_File_Path, "r+");

	if (!new_File)
	{
		printf("ERROR: new file could not be opened!!\n");
		return;
	}

	for (int i = 0; i < 200; i++)
	{
		fprintf(new_File, "%d\n", IRandom(1000000, 9999999));
	}

	fclose(new_File);
	printf("The file '%s' was created at path '%s'!\n", G_User_Input, text_File_Path);
}

FILE* Create_New_Text_File_Old(char* new_File_Name)
{
	char* new_File_Name_Path = "programs\\text-files\\";
	const int FILE_NAME_PATH_SIZE = 21;
	new_File_Name_Path = malloc( ((strlen(new_File_Name) + 100) - FILE_NAME_PATH_SIZE) * sizeof(char));

	strncat_s(new_File_Name_Path, strlen(new_File_Name) + 100, new_File_Name, strlen(new_File_Name));

	const int SCORE_STRING_SIZE = 2;

	int file_Was_Created = 0;
	FILE* file = NULL;

	while (file_Was_Created == 0)
	{
		if (File_Exists(new_File_Name_Path) == 1)
		{
			strncat_s(new_File_Name_Path, strlen(new_File_Name) + 100, "_", SCORE_STRING_SIZE);
		}else
		{
			file_Was_Created = 1;
			fopen_s(file, new_File_Name_Path, "r+");
		}
	}

	return file;
	free(new_File_Name_Path);
}