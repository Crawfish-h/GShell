#pragma once
#define MAX_INPUT_SIZE 1000
#include <string.h>

static char G_User_Input[MAX_INPUT_SIZE];
#define TRUE 1
#define FALSE 0

static void Clear_User_Input()
{
	char* temp = "\n";
	strcpy_s(G_User_Input, MAX_INPUT_SIZE, temp);
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