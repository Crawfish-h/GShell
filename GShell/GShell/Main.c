#pragma once
#define STB_DS_IMPLEMENTATION
#include <stdbool.h>
#include "programs/Capitalize.h"
#include "programs/Text_Editor.h"
#include "programs/GSecurity.h"
#include "Globals.c"
#include "User_Info.h"

int main(int argc, char* argv[])
{
	User_Info user_Info = { .Id = -1, .Password = "", .User_Name = "" };
	user_Info.Id = -1;
	user_Info.Password = "";
	user_Info.User_Name = "";

	while (true)
	{
		Clear_User_Input();
		printf(">>>");
		fgets(&G_User_Input, MAX_INPUT_SIZE, stdin);
		G_User_Input[MAX_INPUT_SIZE - 1] = '\0';

		if (strcmp(G_User_Input, "capitalize\n") == 0 || strcmp(G_User_Input, "cap\n") == 0)
		{
			Capitalize();
		}else if (strcmp(G_User_Input, "texteditor -o\n") == 0)// texteditor -o
		{
			Open_Text_File_();
		}else if (strcmp(G_User_Input, "texteditor -c\n") == 0)// texteditor -o
		{
			Create_New_Text_File();
		}else if (strcmp(G_User_Input, "security -np\n") == 0)// np: new password.
		{
			Security_New_Password(&user_Info);
		}else if (strcmp(G_User_Input, "security -nu\n") == 0)// np: new username.
		{
			Security_New_Username(&user_Info);
		}else if (strcmp(G_User_Input, "security -li\n") == 0)// li: login.
		{
			Security_Login(&user_Info);
		}else if (strcmp(G_User_Input, "security -pl\n") == 0)// pl: print login (information).
		{
			Security_Login(&user_Info);
		}
		else if (strcmp(G_User_Input, "quit\n") == 0)
		{
			break;
		}else
		{
			printf("ERROR: Input does not match a program's name!!\n");
		}
	}

	return 0;
}