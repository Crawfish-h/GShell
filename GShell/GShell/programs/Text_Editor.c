#pragma once
#include "Text_Editor.h"
#include "../Globals.c"
#include "../MyRandom.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "../User_Info.h"

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

void Edit_Text_File(FILE* text_File, int max_Line_Number, char* buffer, long buffer_Size, char* user_Input)
{
	printf("\nEnter a line number to edit that line.\n");
	printf("Line number: ");
	Clear_User_Input(user_Input);
	fgets(user_Input, MAX_INPUT_SIZE, stdin);

	const int len = strlen(user_Input);

	for (int i = 0; i < len; i++)
	{
		if (!isdigit(user_Input[i]) || atoi(user_Input) > max_Line_Number)
		{
			printf("\n\n\n");
			printf("Please make sure your input is a line number listed in the text file.\n");
			Edit_Text_File(text_File, max_Line_Number, buffer, buffer_Size, user_Input);
			return;
		}
	}
	

	int line_Number = 0;
	while (fgets(buffer, buffer_Size, text_File) != NULL)
	{
		if (atoi(user_Input) == line_Number)
		{

		}else if (atoi(user_Input) > max_Line_Number)
		{

		}

		line_Number++;

	}

	if (strcmp(user_Input, "a\n") == 0)
	{

	}

	fclose(text_File);
}

int Open_Text_File_(const User_Info* user_Info, char* current_Directory, char* user_Input)
{
	char new_File_Path[FINAL_INPUT_SIZE];
	memset(new_File_Path, '\0', sizeof(char) * FINAL_INPUT_SIZE);

	user_Input[strcspn(user_Input, "\n")] = 0;
	Remove_Sub_Str(user_Input, "texteditor -o ");

	user_Input[strcspn(user_Input, "\n")] = 0;

	sprintf(new_File_Path, "%s\\%s", current_Directory, user_Input);

	FILE* text_File;
	fopen_s(&text_File, new_File_Path, "r");

	if (!text_File)
	{
		printf("ERROR: unable to open text file: %s!!\n", new_File_Path);
		return FALSE;
	}else
	{
		if (Secure_File_Check(user_Info, user_Input) == FALSE)
		{
			fclose(text_File);
			return FALSE;
		}

		long buffer_Size = Get_File_Size(text_File);
		char* buffer = malloc(buffer_Size * sizeof(char));

		if (buffer == NULL)
		{
			printf("ERROR: Memory was not allocated for printing a text file!!.\n");
			return FALSE;
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

	return TRUE;
}

int Create_New_Text_File(char* current_Directory, char* user_Input)
{
	int file_Was_Created = 0;
	char new_File_Path[FINAL_INPUT_SIZE];
	memset(new_File_Path, '\0', sizeof(char) * FINAL_INPUT_SIZE);
	while (file_Was_Created == 0)
	{
		Clear_User_Input(user_Input);
		printf("File name: ");
		fgets(user_Input, MAX_INPUT_SIZE, stdin);

		user_Input[strcspn(user_Input, "\n")] = 0;

		
		sprintf(new_File_Path, "%s\\%s.txt", current_Directory, user_Input);

		if (File_Exists(new_File_Path) == TRUE)
		{
			printf("A file named '%s' Already exists!!\n", user_Input);
		}else
		{
			file_Was_Created = 1;
			break;
		}
	}

	user_Input[strcspn(user_Input, "\n")] = 0;

	FILE* new_File;
	fopen_s(&new_File, new_File_Path, "a");

	if (!new_File)
	{
		printf("ERROR: new file could not be created!!\n");
		return FALSE;
	}

	fclose(new_File);
	fopen_s(&new_File, new_File_Path, "r+");

	if (!new_File)
	{
		printf("ERROR: new file could not be opened!!\n");
		return FALSE;
	}

	for (int i = 0; i < 200; i++)
	{
		fprintf(new_File, "%d\n", IRandom(1000000, 9999999));
	}

	fclose(new_File);
	printf("The file '%s' was created at path '%s'!\n", user_Input, new_File_Path);
	return TRUE;
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