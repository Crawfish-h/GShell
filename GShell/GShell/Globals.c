#pragma once
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <io.h>
#include "User_Info.h"


#define TRUE 1
#define FALSE 0
#define MAX_INPUT_SIZE 1000
#define MAX_PATH_LARGE 2048
#define FINAL_INPUT_SIZE 3048
#define F_OK 0
#define access _access
#define SECURED_FILES_PATH "programs\\home\\security\\secured-files"

//static char G_User_Input[MAX_INPUT_SIZE];

static void Clear_User_Input(char* user_Input)
{
	char* temp = "\0";
	strcpy_s(user_Input, MAX_INPUT_SIZE, temp);
}

static wchar_t* Char_To_WChar(const char* text)
{
	const size_t size = strlen(text) + 1;
	wchar_t* wText = malloc(size);

	if (wText == NULL)
	{
		printf("ERROR: could not convert 'char*' to 'wchar_t*'!!");
		exit(EXIT_FAILURE);
	}

	memset(wText, 0x00, sizeof(wText)*size); // ...?
	mbstowcs(wText, text, size);
	return wText;
}

static char* Final_Input()
{
	char final_Input_Str[FINAL_INPUT_SIZE];
	memset(final_Input_Str, '\0', sizeof(char)*FINAL_INPUT_SIZE);

}

static int File_Exists(const char* fname)
{
	if (access(fname, F_OK) == 0)
	{
		// File exists.
		return TRUE;
	}else
	{
		// File does not exist.
		return FALSE;
	}
}

static int Secure_File_Check(const User_Info* user_Info, const char* user_Input)
{
	char secured_Path[FINAL_INPUT_SIZE];
	memset(secured_Path, '\0', sizeof(char) * FINAL_INPUT_SIZE);

	sprintf(secured_Path, "%s\\%s", SECURED_FILES_PATH, user_Input);
	if (File_Exists(secured_Path) == TRUE && user_Info->Is_Superuser == FALSE)
	{
		printf("Cannot open a secure file/folder without being Superuser.\n");
		return FALSE;
	}

	return TRUE;
}

// This function was gotten online from -
// https://cboard.cprogramming.com/c-programming/143155-simple-removal-string-string-via-strtok.html
static void Remove_Sub_Str(char* string, char* sub) {
	char* match = string;
	int len = strlen(sub);
	while ((match = strstr(match, sub))) {
		*match = '\0';
		strcat(string, match + len);
		match++;
	}
}

// Returns true if 'compare_String' is the first sub string in user_Input.
static int Compare_User_Input(char* user_Input, char* compare_String)
{
	if (strlen(user_Input) >= strlen(compare_String))
	{
		for (int i = 0; i < strlen(compare_String); i++)
		{
			if (user_Input[i] != compare_String[i])
			{
				//printf("Invalid input: string content mismatch.\n");
				return FALSE;
			}
		}
	}else
	{
		//printf("Invalid input: string length mismatch.\n");
		return FALSE;
	}

	return TRUE;
}

//static int Get_Real_User_Input(char* real_Input)
//{
//	int user_Input_Size = 0;
//	for (int i = 0; i < MAX_INPUT_SIZE; i++)
//	{
//		if (G_User_Input[i] != '\n')
//		{
//			user_Input_Size++;
//			
//		}else
//		{
//			break;
//		}
//	}
//
//	for (int i = 0; i < user_Input_Size; i++)
//	{
//		strncat_s(real_Input, user_Input_Size, &G_User_Input[i], 1);
//	}
//
//	return user_Input_Size;
//}