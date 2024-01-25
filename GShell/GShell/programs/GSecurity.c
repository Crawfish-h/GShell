// Need to add the letter 'G' to the start of 'Security' or else a another file named 'security' 
// will start generating weird errors that have nothing to do with this program.
#include "GSecurity.h" 
#include <stdio.h>
#include "../Globals.c"
#include "../user_Info.h"
#define SIZE_PASSWORD_PATH_INFO 55
#define SIZE_USERNAME_PATH_INFO 49

//void Set_Path_To_User_Info(User_Info* user_Info, char* path_To_User_Info, int use_Password_Paths)
//{
//	char info_Path_Center[24] = "passwords\\user_password";
//	//"user_names\\user_name__0"
//	if (use_Password_Paths != 0)
//	{
//		strncpy_s(info_Path_Center, 24, "passwords\\user_password", 24);
//	}else
//	{
//		strncpy_s(info_Path_Center, 24, "user_names\\user_name___", 24);
//	}
//
//	if (strcmp(G_User_Input, "0\n") == 0)
//	{
//		strncpy_s(path_To_User_Info, SIZE_PASSWORD_PATH_INFO, "programs\\home\\security\\\0", 25);
//		strcat_s(path_To_User_Info, 24, info_Path_Center);
//		strcat_s(path_To_User_Info, 24, info_Path_Center);
//		if (user_Info->Id == 0)
//		{
//			printf("Signed out of user 0.");
//			user_Info->Id = -1;
//			user_Info->Password = "";
//			user_Info->User_Name = "";
//		}
//	}
//	else if (strcmp(G_User_Input, "1\n") == 0)
//	{
//		strncpy_s(path_To_User_Info, SIZE_PASSWORD_PATH_INFO, "programs\\home\\security\\passwords\\user_password_1.txt\0", SIZE_PASSWORD_PATH_INFO);
//		if (user_Info->Id == 1)
//		{
//			printf("Signed out of user 1.");
//			user_Info->Id = -1;
//			user_Info->Password = "";
//			user_Info->User_Name = "";
//		}
//	}
//	else if (strcmp(G_User_Input, "2\n") == 0)
//	{
//		strncpy_s(path_To_User_Info, SIZE_PASSWORD_PATH_INFO, "programs\\home\\security\\passwords\\user_password_2.txt\0", SIZE_PASSWORD_PATH_INFO);
//		if (user_Info->Id == 2)
//		{
//			printf("Signed out of user 2.");
//			user_Info->Id = -1;
//			user_Info->Password = "";
//			user_Info->User_Name = "";
//		}
//	}
//	else if (strcmp(G_User_Input, "3\n") == 0)
//	{
//		strncpy_s(path_To_User_Info, SIZE_PASSWORD_PATH_INFO, "programs\\home\\security\\passwords\\user_password_3.txt\0", SIZE_PASSWORD_PATH_INFO);
//		if (user_Info->Id == 3)
//		{
//			printf("Signed out of user 3.");
//			user_Info->Id = -1;
//			user_Info->Password = "";
//			user_Info->User_Name = "";
//		}
//	}
//	else
//	{
//		printf("ERROR: Input does not match a user's id which can be from 0 to 3!!\n");
//		return;
//	}
//}

int Set_Password_Path(User_Info* user_Info, char* path_To_Passwords, int sign_Out)
{
	if (strcmp(G_User_Input, "0\n") == 0)
	{
		strncpy_s(path_To_Passwords, SIZE_PASSWORD_PATH_INFO, "programs\\home\\security\\passwords\\user_password_0.txt\0", SIZE_PASSWORD_PATH_INFO);
		if (user_Info->Id == 0 && sign_Out == TRUE)
		{
			printf("Signed out of user 0.");
			user_Info->Id = -1;
			user_Info->Password = "";
			user_Info->User_Name = "";
		}
	}else if (strcmp(G_User_Input, "1\n") == 0)
	{
		strncpy_s(path_To_Passwords, SIZE_PASSWORD_PATH_INFO, "programs\\home\\security\\passwords\\user_password_1.txt\0", SIZE_PASSWORD_PATH_INFO);
		if (user_Info->Id == 1 && sign_Out == TRUE)
		{
			printf("Signed out of user 1.");
			user_Info->Id = -1;
			user_Info->Password = "";
			user_Info->User_Name = "";
		}
	}else if (strcmp(G_User_Input, "2\n") == 0)
	{
		strncpy_s(path_To_Passwords, SIZE_PASSWORD_PATH_INFO, "programs\\home\\security\\passwords\\user_password_2.txt\0", SIZE_PASSWORD_PATH_INFO);
		if (user_Info->Id == 2 && sign_Out == TRUE)
		{
			printf("Signed out of user 2.");
			user_Info->Id = -1;
			user_Info->Password = "";
			user_Info->User_Name = "";
		}
	}else if (strcmp(G_User_Input, "3\n") == 0)
	{
		strncpy_s(path_To_Passwords, SIZE_PASSWORD_PATH_INFO, "programs\\home\\security\\passwords\\user_password_3.txt\0", SIZE_PASSWORD_PATH_INFO);
		if (user_Info->Id == 3 && sign_Out == TRUE)
		{
			printf("Signed out of user 3.");
			user_Info->Id = -1;
			user_Info->Password = "";
			user_Info->User_Name = "";
		}
	}else
	{
		printf("ERROR: Input does not match a user's id which can be from 0 to 3!!\n");
		return 1;
	}

	return 0;
}

int Set_Username_Path(User_Info* user_Info, char* path_To_Usernames, int sign_Out)
{
	if (strcmp(G_User_Input, "0\n") == 0)
	{
		strncpy_s(path_To_Usernames, SIZE_USERNAME_PATH_INFO, "programs\\home\\security\\usernames\\username_0.txt\0", SIZE_USERNAME_PATH_INFO);
		if (user_Info->Id == 0 && sign_Out == TRUE)
		{
			printf("Signed out of user 0.");
			user_Info->Id = -1;
			user_Info->Password = "";
			user_Info->User_Name = "";
		}
	}else if (strcmp(G_User_Input, "1\n") == 0)
	{
		strncpy_s(path_To_Usernames, SIZE_USERNAME_PATH_INFO, "programs\\home\\security\\usernames\\username_1.txt\0", SIZE_USERNAME_PATH_INFO);
		if (user_Info->Id == 1 && sign_Out == TRUE)
		{
			printf("Signed out of user 1.");
			user_Info->Id = -1;
			user_Info->Password = "";
			user_Info->User_Name = "";
		}
	}else if (strcmp(G_User_Input, "2\n") == 0)
	{
		strncpy_s(path_To_Usernames, SIZE_USERNAME_PATH_INFO, "programs\\home\\security\\usernames\\username_2.txt\0", SIZE_USERNAME_PATH_INFO);
		if (user_Info->Id == 2 && sign_Out == TRUE)
		{
			printf("Signed out of user 2.");
			user_Info->Id = -1;
			user_Info->Password = "";
			user_Info->User_Name = "";
		}
	}else if (strcmp(G_User_Input, "3\n") == 0)
	{
		strncpy_s(path_To_Usernames, SIZE_USERNAME_PATH_INFO, "programs\\home\\security\\usernames\\username_3.txt\0", SIZE_USERNAME_PATH_INFO);
		if (user_Info->Id == 3 && sign_Out == TRUE)
		{
			printf("Signed out of user 3.");
			user_Info->Id = -1;
			user_Info->Password = "";
			user_Info->User_Name = "";
		}
	}else
	{
		printf("ERROR: Input does not match a user's id which can be from 0 to 3!!\n");
		return 1;
	}

	return 0;
}

void Security_New_Password(User_Info* user_Info)
{
	Clear_User_Input();
	printf("Select user by ID: ");
	fgets(&G_User_Input, MAX_INPUT_SIZE, stdin);

	FILE* passwords_File;
	char path_To_Passwords[SIZE_PASSWORD_PATH_INFO] = "programs\\home\\security\\passwords\\user_password_0.txt\0";

	if (Set_Password_Path(user_Info, path_To_Passwords, TRUE) == 1)
	{
		return;
	}

	/*switch (user_Info->Id)
	{
	case 0:
		strncpy_s(path_To_Passwords, SIZE_PASSWORD_PATH_INFO, "programs\\home\\security\\user_password_0.txt\0", SIZE_PASSWORD_PATH_INFO);
		if (user_Id == 0)
		{
			printf("Signed out of user 0.");
		}
	case 1:
		strncpy_s(path_To_Passwords, SIZE_PASSWORD_PATH_INFO, "programs\\home\\security\\user_password_1.txt\0", SIZE_PASSWORD_PATH_INFO);
		if (user_Id == 1)
		{
			printf("Signed out of user 1.");
		}
	case 2:
		strncpy_s(path_To_Passwords, SIZE_PASSWORD_PATH_INFO, "programs\\home\\security\\user_password_2.txt\0", SIZE_PASSWORD_PATH_INFO);
	case 3:
		strncpy_s(path_To_Passwords, SIZE_PASSWORD_PATH_INFO, "programs\\home\\security\\user_password_3.txt\0", SIZE_PASSWORD_PATH_INFO);
	default:

		break;
	}*/


	fopen_s(&passwords_File, path_To_Passwords, "w+");

	if (!passwords_File)
	{
		printf("ERROR: passwords file could not be opened!!\n");
		return;
	}

	Clear_User_Input();
	printf("New password: ");
	fgets(&G_User_Input, MAX_INPUT_SIZE, stdin);

	G_User_Input[strcspn(G_User_Input, "\n")] = 0;

	fprintf(passwords_File, "%s", G_User_Input);

	printf("Added new password.\n");

	fclose(passwords_File);
}

void Security_New_Username(User_Info* user_Info)
{
	Clear_User_Input();
	printf("Select user by ID: ");
	fgets(&G_User_Input, MAX_INPUT_SIZE, stdin);

	FILE* usernames_File;
	char path_To_Usernames[SIZE_USERNAME_PATH_INFO] = "programs\\home\\security\\usernames\\username_0.txt\0";

	if (Set_Username_Path(user_Info, path_To_Usernames, TRUE) == 1)
	{
		return;
	}


	fopen_s(&usernames_File, path_To_Usernames, "w+");

	if (!usernames_File)
	{
		printf("ERROR: usernames file could not be opened!!\n");
		return;
	}

	Clear_User_Input();
	printf("New username: ");
	fgets(&G_User_Input, MAX_INPUT_SIZE, stdin);

	G_User_Input[strcspn(G_User_Input, "\n")] = 0;

	fprintf(usernames_File, "%s", G_User_Input);

	printf("Changed username.\n");

	fclose(usernames_File);
}

int Check_Username(User_Info* temp_User, char* path_To_Username)
{
	Clear_User_Input();
	printf("Type in username: ");
	fgets(&G_User_Input, MAX_INPUT_SIZE, stdin);

	FILE* username_File;
	char username_Str[MAX_INPUT_SIZE] = "";

	fopen_s(&username_File, path_To_Username, "r+");

	if (!username_File)
	{
		printf("ERROR: username file could not be opened!!\n");
		return;
	}

	fgets(username_Str, MAX_INPUT_SIZE, username_File);

	G_User_Input[strcspn(G_User_Input, "\n")] = 0;

	if (strcmp(G_User_Input, username_Str) == 0)
	{
		temp_User->User_Name = username_Str;
		return TRUE;
	}else
	{
		printf("Incorrect username!\n");
		return FALSE;
	}

	fclose(username_File);
}

int Check_Password(User_Info* temp_User, char* path_To_Password)
{
	Clear_User_Input();
	printf("Type in password: ");
	fgets(&G_User_Input, MAX_INPUT_SIZE, stdin);

	FILE* password_File;
	char password_Str[MAX_INPUT_SIZE] = "";

	fopen_s(&password_File, path_To_Password, "r+");

	if (!password_File)
	{
		printf("ERROR: password file could not be opened!!\n");
		return;
	}

	fgets(password_Str, MAX_INPUT_SIZE, password_File);

	G_User_Input[strcspn(G_User_Input, "\n")] = 0;

	if (strcmp(G_User_Input, password_Str) == 0)
	{
		temp_User->Password = password_Str;
		return TRUE;
	}else
	{
		printf("Incorrect password!\n");
		return FALSE;
	}

	fclose(password_File);
}

void Set_User(User_Info* user_Info, const User_Info* temp_User, int user_Id)
{
	user_Info->Id = user_Id;
	user_Info->Password = temp_User->Password;
	user_Info->User_Name = temp_User->User_Name;
	printf("Signed into User %d: %s\n", user_Info->Id, user_Info->User_Name);
}

void Security_Login(User_Info* user_Info)
{
	Clear_User_Input();
	printf("Select user by ID: ");
	fgets(&G_User_Input, MAX_INPUT_SIZE, stdin);

	User_Info temp_User = { .Id = -1, .Password = "", .User_Name = "" };

	if (strcmp(G_User_Input, "0\n") == 0)
	{
		if (Check_Username(&temp_User, "programs\\home\\security\\usernames\\username_0.txt\0") == FALSE) { return; }
		if (Check_Password(&temp_User, "programs\\home\\security\\passwords\\user_password_0.txt\0") == FALSE) { return; }
		Set_User(user_Info, &temp_User, 0);
	}else if (strcmp(G_User_Input, "1\n") == 0)
	{
		if (Check_Username(&temp_User, "programs\\home\\security\\usernames\\username_1.txt\0") == FALSE) { return; }
		if (Check_Password(&temp_User, "programs\\home\\security\\passwords\\user_password_1.txt\0") == FALSE) { return; }
		Set_User(user_Info, &temp_User, 1);
	}else if (strcmp(G_User_Input, "2\n") == 0)
	{
		if (Check_Username(&temp_User, "programs\\home\\security\\usernames\\username_2.txt\0") == FALSE) { return; }
		if (Check_Password(&temp_User, "programs\\home\\security\\passwords\\user_password_2.txt\0") == FALSE) { return; }
		Set_User(user_Info, &temp_User, 2);
	}else if (strcmp(G_User_Input, "3\n") == 0)
	{
		if (Check_Username(&temp_User, "programs\\home\\security\\usernames\\username_3.txt\0") == FALSE) { return; }
		if (Check_Password(&temp_User, "programs\\home\\security\\passwords\\user_password_3.txt\0") == FALSE) { return; }
		Set_User(user_Info, &temp_User, 3);
	}else
	{
		printf("ERROR: Input does not match a user's id which can be from 0 to 3!!\n");
		return;
	}
}

int Check_Login(User_Info* user_Info)
{
	User_Info temp_User = { .Id = -1, .Password = "", .User_Name = "" };

	switch (user_Info->Id)
	{
	case 0:
		if (Check_Username(&temp_User, "programs\\home\\security\\usernames\\username_0.txt\0") == FALSE) { return FALSE; }
		if (Check_Password(&temp_User, "programs\\home\\security\\passwords\\user_password_0.txt\0") == FALSE) { return FALSE; }
		break;
	case 1:
		if (Check_Username(&temp_User, "programs\\home\\security\\usernames\\username_1.txt\0") == FALSE) { return FALSE; }
		if (Check_Password(&temp_User, "programs\\home\\security\\passwords\\user_password_1.txt\0") == FALSE) { return FALSE; }
		break;
	case 2:
		if (Check_Username(&temp_User, "programs\\home\\security\\usernames\\username_1.txt\0") == FALSE) { return FALSE; }
		if (Check_Password(&temp_User, "programs\\home\\security\\passwords\\user_password_1.txt\0") == FALSE) { return FALSE; }
		break;
	case 3:
		if (Check_Username(&temp_User, "programs\\home\\security\\usernames\\username_1.txt\0") == FALSE) { return FALSE; }
		if (Check_Password(&temp_User, "programs\\home\\security\\passwords\\user_password_1.txt\0") == FALSE) { return FALSE; }
		break;
	default:
		return TRUE;
		break;
	}
}