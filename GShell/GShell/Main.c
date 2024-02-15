#pragma once
#define STB_DS_IMPLEMENTATION
#include <stdbool.h>
#include "programs/Capitalize.h"
#include "programs/Text_Editor.h"
#include "programs/GSecurity.h"
#include "programs/MFile_System.h"
#include "Globals.c"
#include "User_Info.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <direct.h>
#include <assert.h>

int main(int argc, char* argv[])
{
	char user_Input[MAX_INPUT_SIZE];
	char current_Directory[MAX_PATH_LARGE];

	_getcwd(current_Directory, MAX_PATH_LARGE);

	User_Info user_Info;
	user_Info.Password = malloc(MAX_INPUT_SIZE);
	assert(user_Info.Password);
	user_Info.User_Name = malloc(MAX_INPUT_SIZE);
	assert(user_Info.User_Name);
	Sign_Into_Guest(&user_Info, user_Input);

	//strncat_s(buffer, MAX_PATH_LARGE, "\\", 2);

	//printf("Current working directory: %s\n", current_Directory);

	//ListDirectoryContents(current_Directory, FALSE);

	sprintf(current_Directory, "%s\\%s", current_Directory, "programs\\home");

	while (true)
	{
		Clear_User_Input(user_Input);
		Print_Marker(&user_Info, current_Directory);
		fgets(user_Input, MAX_INPUT_SIZE, stdin);
		//user_Input[MAX_INPUT_SIZE - 1] = '\0';
		//strcmp(user_Input, "capitalize\n") == 0
		if (Compare_User_Input(user_Input, "capitalize ") == TRUE)
		{
			Capitalize(user_Input);
		}else if (Compare_User_Input(user_Input, "texteditor -o ") == TRUE) // texteditor -o
		{
			Open_Text_File_(&user_Info, current_Directory, user_Input);
		}else if (strcmp(user_Input, "texteditor -c\n") == 0) // texteditor -c
		{
			Create_New_Text_File(current_Directory, user_Input);
		}else if (strcmp(user_Input, "np\n") == 0) // np: new password.
		{
			Security_New_Password(&user_Info, user_Input);
		}else if (strcmp(user_Input, "nu\n") == 0) // nu: new username.
		{
			Security_New_Username(&user_Info, user_Input);
		}else if (Compare_User_Input(user_Input, "li") == TRUE) // li: login.
		{
			Security_Login(&user_Info, user_Input);
		}else if (Compare_User_Input(user_Input, "pl ") == TRUE) // pl: print login (information).
		{
			Print_Login(&user_Info, user_Input);
		}else if (strcmp(user_Input, "ls\n") == 0) // ls: lists files in current directory.
		{
			ListDirectoryContents(current_Directory, FALSE);
		}else if (Compare_User_Input(user_Input, "cd ") == TRUE && Compare_User_Input(user_Input, "cd ..") == FALSE) // cd: change directory.
		{
			Change_Directory(&user_Info, current_Directory, user_Input);
		}else if (strcmp(user_Input, "cd ..\n") == 0) // cd ..: go up one directory.
		{
			Go_Up_Directory(current_Directory);
		}else if (Compare_User_Input(user_Input, "mkdir ") == TRUE) // mkdir: make/create directory.
		{
			Create_Folder(&user_Info, current_Directory, user_Input);
		}else if (Compare_User_Input(user_Input, "sf ") == TRUE) // sf: secure file/folder.
		{
			Secure_File(&user_Info, current_Directory, user_Input);
		}else if (Compare_User_Input(user_Input, "usf ") == TRUE) // usf: unsecure file/folder.
		{
			Unsecure_File(&user_Info, current_Directory, user_Input);
		}else if (strcmp(user_Input, "su\n") == 0) // su: sign in to superuser.
		{
			Sign_Into_Superuser(&user_Info, user_Input);
		}else if (strcmp(user_Input, "so\n") == 0) // so: sign out.
		{
			Sign_Into_Guest(&user_Info, user_Input);
		}else if (strcmp(user_Input, "quit\n") == 0)
		{
			break;
		}else
		{
			printf("incorrect user input.\n");
		}
	}

	if (user_Info.User_Name != NULL) free(user_Info.User_Name);
	if (user_Info.Password != NULL) free(user_Info.Password);
	return 0;
}