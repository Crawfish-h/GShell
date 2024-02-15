// Need to add the letter 'G' to the start of 'Security' or else a another file named 'security' 
// will start generating weird errors that have nothing to do with this program.
#include "GSecurity.h" 
#include <stdio.h>
#include <stdlib.h>
#include "../Globals.c"
#include "../User_Info.h"
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
//	if (strcmp(user_Input, "0\n") == 0)
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
//	else if (strcmp(user_Input, "1\n") == 0)
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
//	else if (strcmp(user_Input, "2\n") == 0)
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
//	else if (strcmp(user_Input, "3\n") == 0)
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

int Set_Password_Path(User_Info* user_Info, char* path_To_Passwords, int sign_Out, char* user_Input)
{
	if (strcmp(user_Input, "0\n") == 0)
	{
		strncpy_s(path_To_Passwords, SIZE_PASSWORD_PATH_INFO, "programs\\home\\security\\passwords\\user_password_0.txt\0", SIZE_PASSWORD_PATH_INFO);
		if (user_Info->Id == 0 && sign_Out == TRUE)
		{
			printf("Signed out of user 0.");
			user_Info->Id = -1;
			user_Info->Password = "";
			user_Info->User_Name = "";
		}
	}else if (strcmp(user_Input, "1\n") == 0)
	{
		strncpy_s(path_To_Passwords, SIZE_PASSWORD_PATH_INFO, "programs\\home\\security\\passwords\\user_password_1.txt\0", SIZE_PASSWORD_PATH_INFO);
		if (user_Info->Id == 1 && sign_Out == TRUE)
		{
			printf("Signed out of user 1.");
			user_Info->Id = -1;
			user_Info->Password = "";
			user_Info->User_Name = "";
		}
	}else if (strcmp(user_Input, "2\n") == 0)
	{
		strncpy_s(path_To_Passwords, SIZE_PASSWORD_PATH_INFO, "programs\\home\\security\\passwords\\user_password_2.txt\0", SIZE_PASSWORD_PATH_INFO);
		if (user_Info->Id == 2 && sign_Out == TRUE)
		{
			printf("Signed out of user 2.");
			user_Info->Id = -1;
			user_Info->Password = "";
			user_Info->User_Name = "";
		}
	}else if (strcmp(user_Input, "3\n") == 0)
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

int Set_Username_Path(User_Info* user_Info, char* path_To_Usernames, int sign_Out, char* user_Input)
{
	if (strcmp(user_Input, "0\n") == 0)
	{
		strncpy_s(path_To_Usernames, SIZE_USERNAME_PATH_INFO, "programs\\home\\security\\usernames\\username_0.txt\0", SIZE_USERNAME_PATH_INFO);
		if (user_Info->Id == 0 && sign_Out == TRUE)
		{
			printf("Signed out of user 0.");
			user_Info->Id = -1;
			user_Info->Password = "";
			user_Info->User_Name = "";
		}
	}else if (strcmp(user_Input, "1\n") == 0)
	{
		strncpy_s(path_To_Usernames, SIZE_USERNAME_PATH_INFO, "programs\\home\\security\\usernames\\username_1.txt\0", SIZE_USERNAME_PATH_INFO);
		if (user_Info->Id == 1 && sign_Out == TRUE)
		{
			printf("Signed out of user 1.");
			user_Info->Id = -1;
			user_Info->Password = "";
			user_Info->User_Name = "";
		}
	}else if (strcmp(user_Input, "2\n") == 0)
	{
		strncpy_s(path_To_Usernames, SIZE_USERNAME_PATH_INFO, "programs\\home\\security\\usernames\\username_2.txt\0", SIZE_USERNAME_PATH_INFO);
		if (user_Info->Id == 2 && sign_Out == TRUE)
		{
			printf("Signed out of user 2.");
			user_Info->Id = -1;
			user_Info->Password = "";
			user_Info->User_Name = "";
		}
	}else if (strcmp(user_Input, "3\n") == 0)
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

void Security_New_Password(User_Info* user_Info, char* user_Input)
{
	if (user_Info->Is_Superuser == TRUE)
	{
		Clear_User_Input(user_Input);
		printf("Select user by ID: ");
		fgets(user_Input, MAX_INPUT_SIZE, stdin);

		FILE* passwords_File;
		char path_To_Passwords[SIZE_PASSWORD_PATH_INFO] = "programs\\home\\security\\passwords\\user_password_0.txt\0";

		if (Set_Password_Path(user_Info, path_To_Passwords, TRUE, user_Input) == 1)
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

		Clear_User_Input(user_Input);
		printf("New password: ");
		fgets(user_Input, MAX_INPUT_SIZE, stdin);

		user_Input[strcspn(user_Input, "\n")] = 0;

		fprintf(passwords_File, "%s", user_Input);

		printf("Added new password.\n");

		fclose(passwords_File);
	}else
	{
		printf("Need to be a Superuser in order to change passwords.\n");
	}
}

void Security_New_Username(User_Info* user_Info, char* user_Input)
{
	if (user_Info->Is_Superuser == TRUE)
	{
		Clear_User_Input(user_Input);
		printf("Select user by ID: ");
		fgets(user_Input, MAX_INPUT_SIZE, stdin);

		FILE* usernames_File;
		char path_To_Usernames[SIZE_USERNAME_PATH_INFO] = "programs\\home\\security\\usernames\\username_0.txt\0";

		if (Set_Username_Path(user_Info, path_To_Usernames, TRUE, user_Input) == 1)
		{
			return;
		}


		fopen_s(&usernames_File, path_To_Usernames, "w+");

		if (!usernames_File)
		{
			printf("ERROR: usernames file could not be opened!!\n");
			return;
		}

		Clear_User_Input(user_Input);
		printf("New username: ");
		fgets(user_Input, MAX_INPUT_SIZE, stdin);

		user_Input[strcspn(user_Input, "\n")] = 0;

		fprintf(usernames_File, "%s", user_Input);

		printf("Changed username.\n");

		fclose(usernames_File);
	}else
	{
		printf("Need to be a Superuser in order to change usernames.\n");
	}
}

int Check_Username(User_Info* user_Info, char* path_To_Username, char* user_Input)
{
	Clear_User_Input(user_Input);
	printf("Type in username: ");
	fgets(user_Input, MAX_INPUT_SIZE, stdin);

	FILE* username_File;
	char username_Str[MAX_INPUT_SIZE] = "";

	fopen_s(&username_File, path_To_Username, "r+");

	if (!username_File)
	{
		printf("ERROR: username file could not be opened!!\n");
		return FALSE;
	}

	fgets(username_Str, MAX_INPUT_SIZE, username_File);

	user_Input[strcspn(user_Input, "\n")] = 0;

	fclose(username_File);

	if (strcmp(user_Input, username_Str) == 0)
	{
		//temp_User->User_Name = username_Str;
		// 
		if (user_Info->User_Name != NULL) free(user_Info->User_Name);
		user_Info->User_Name = malloc(MAX_INPUT_SIZE); 


		if (user_Info->User_Name == NULL)
		{
			printf("ERROR: could not get username!!\n");
			return FALSE;
		}
		strcpy(user_Info->User_Name, username_Str);

		
		return TRUE;
	}else
	{
		printf("Incorrect username!\n");
		return FALSE;
	}
}

int Check_Password(User_Info* user_Info, char* path_To_Password, char* user_Input)
{
	Clear_User_Input(user_Input);
	printf("Type in password: ");
	fgets(user_Input, MAX_INPUT_SIZE, stdin);

	FILE* password_File;
	char password_Str[MAX_INPUT_SIZE] = "";

	fopen_s(&password_File, path_To_Password, "r+");

	if (!password_File)
	{
		printf("ERROR: password file could not be opened!!\n");
		return FALSE;
	}

	fgets(password_Str, MAX_INPUT_SIZE, password_File);

	user_Input[strcspn(user_Input, "\n")] = 0;

	fclose(password_File);

	if (strcmp(user_Input, password_Str) == 0)
	{
		// THIS IS BAD. MAKE A FUNCTION THAT SETS temp_User->User_Name. USE PRIVATE "MAGIC" TO HIDE temp_User->User_Name!!!!
		// In the past, I used a simpler method for assigning the value of 'password_Str' to 'user_Info->Password' but it caused another variable to have its value set to
		// 'password_Str', which forced me to use malloc, strcpy, and free. I think this strange copy error ocurred because of the nature of pointers.
		if (user_Info->Password != NULL) free(user_Info->Password);
		user_Info->Password = malloc(MAX_INPUT_SIZE);
		if (user_Info->Password == NULL)
		{
			printf("ERROR: could not get username!!\n");
			return FALSE;
		}
		strcpy(user_Info->Password, password_Str);
		//temp_User->Password = password_Str;

		return TRUE;
	}else
	{
		printf("Incorrect password!\n");
		return FALSE;
	}
}

void Set_User(User_Info* user_Info, const User_Info* temp_User, int user_Id, char* user_Input)
{
	user_Info->Id = user_Id;
	user_Info->Password = temp_User->Password;
	user_Info->User_Name = temp_User->User_Name;
	printf("passwordd: %s\n", temp_User->Password);
	printf("username: %s\n", temp_User->User_Name);
	printf("Signed into User %d: %s\n", user_Info->Id, user_Info->User_Name);
}

int Security_Login(User_Info* user_Info, char* user_Input)
{
	Clear_User_Input(user_Input);
	printf("Select user by ID: ");
	fgets(user_Input, MAX_INPUT_SIZE, stdin);


	if (strcmp(user_Input, "0\n") == 0)
	{
		if (Check_Username(user_Info, "programs\\home\\security\\usernames\\username_0.txt\0", user_Input) == FALSE) { return FALSE; }
		if (Check_Password(user_Info, "programs\\home\\security\\passwords\\user_password_0.txt\0", user_Input) == FALSE) { return FALSE; }
		user_Info->Id = 0;
	}else if (strcmp(user_Input, "1\n") == 0)
	{
		if (Check_Username(user_Info, "programs\\home\\security\\usernames\\username_1.txt\0", user_Input) == FALSE) { return FALSE; }
		if (Check_Password(user_Info, "programs\\home\\security\\passwords\\user_password_1.txt\0", user_Input) == FALSE) { return FALSE; }
		user_Info->Id = 1;
	}else if (strcmp(user_Input, "2\n") == 0)
	{
		if (Check_Username(user_Info, "programs\\home\\security\\usernames\\username_2.txt\0", user_Input) == FALSE) { return FALSE; }
		if (Check_Password(user_Info, "programs\\home\\security\\passwords\\user_password_2.txt\0", user_Input) == FALSE) { return FALSE; }
		user_Info->Id = 2;
	}else if (strcmp(user_Input, "3\n") == 0)
	{
		if (Check_Username(user_Info, "programs\\home\\security\\usernames\\username_3.txt\0", user_Input) == FALSE) { return FALSE; }
		if (Check_Password(user_Info, "programs\\home\\security\\passwords\\user_password_3.txt\0", user_Input) == FALSE) { return FALSE; }
		user_Info->Id = 3;
	}else
	{
		printf("ERROR: Input does not match a user's id which can be from 0 to 3!!\n");
		return FALSE;
	}

	printf("Signed into User %d: %s\n", user_Info->Id, user_Info->User_Name);
	return TRUE;
}

int Check_Login(User_Info* user_Info, char* user_Input)
{
	User_Info temp_User = { .Id = -1, .Password = "", .User_Name = "" };

	switch (user_Info->Id)
	{
	case 0:
		if (Check_Username(&temp_User, "programs\\home\\security\\usernames\\username_0.txt\0", user_Input) == FALSE) { return FALSE; }
		if (Check_Password(&temp_User, "programs\\home\\security\\passwords\\user_password_0.txt\0", user_Input) == FALSE) { return FALSE; }
		break;
	case 1:
		if (Check_Username(&temp_User, "programs\\home\\security\\usernames\\username_1.txt\0", user_Input) == FALSE) { return FALSE; }
		if (Check_Password(&temp_User, "programs\\home\\security\\passwords\\user_password_1.txt\0", user_Input) == FALSE) { return FALSE; }
		break;
	case 2:
		if (Check_Username(&temp_User, "programs\\home\\security\\usernames\\username_1.txt\0", user_Input) == FALSE) { return FALSE; }
		if (Check_Password(&temp_User, "programs\\home\\security\\passwords\\user_password_1.txt\0", user_Input) == FALSE) { return FALSE; }
		break;
	case 3:
		if (Check_Username(&temp_User, "programs\\home\\security\\usernames\\username_1.txt\0", user_Input) == FALSE) { return FALSE; }
		if (Check_Password(&temp_User, "programs\\home\\security\\passwords\\user_password_1.txt\0", user_Input) == FALSE) { return FALSE; }
		break;
	default:
		return FALSE;
		break;
	}

	return TRUE;
}

void Print_Login(User_Info* user_Info, char* user_Input)
{
	if (Check_Login(user_Info, user_Input) == TRUE)
	{
		printf("User ID: %d\n", user_Info->Id);
		printf("Username: %s\n", user_Info->User_Name);
		printf("Password: %s\n\n", user_Info->Password);
	}else
	{
		printf("Login information invalid!\n");
	}
}

void Sign_Into_Guest(User_Info* user_Info, char* user_Input)
{
	if (user_Info->Id != -1)
	{
		user_Info->Id = -1;
		user_Info->Is_Superuser = FALSE;
		user_Info->Password = NULL;
		user_Info->User_Name = NULL;
	}else
	{
		printf("Already a guest!\n");
	}
}

int Sign_Into_Superuser(User_Info* user_Info, char* user_Input)
{
	if (Security_Login(user_Info, user_Input) == TRUE)
	{
		user_Info->Is_Superuser = TRUE;
		printf("Signed in as Superuser.\n");
		return TRUE;
	}else
	{
		return FALSE;
		printf("Login information invalid!\n");
	}
}

int Secure_File(User_Info* user_Info, char* current_Directory, char* user_Input)
{
	if (user_Info->Is_Superuser == TRUE)
	{
		user_Input[strcspn(user_Input, "\n")] = '\0';
		Remove_Sub_Str(user_Input, "sf ");

		char file_Path[FINAL_INPUT_SIZE];
		char secure_File_Path[FINAL_INPUT_SIZE];
		memset(file_Path, '\0', sizeof(char) * FINAL_INPUT_SIZE);
		memset(secure_File_Path, '\0', sizeof(char) * FINAL_INPUT_SIZE);

		sprintf(file_Path, "%s\\%s", current_Directory, user_Input);
		sprintf(secure_File_Path, "%s\\%s", SECURED_FILES_PATH, user_Input);

		if (File_Exists(file_Path) == FALSE)
		{
			printf("Could not find entered file.\n");
			return FALSE;
		}

		FILE* new_File;
		fopen_s(&new_File, secure_File_Path, "a");

		if (!new_File)
		{
			printf("ERROR: new file could not be created!!\n");
			return FALSE;
		}

		fclose(new_File);
		return TRUE;
	}else
	{
		printf("Not logged in as Superuser, cannot make file/folder secure.\n");
		return FALSE;
	}
}

int Unsecure_File(User_Info* user_Info, char* current_Directory, char* user_Input)
{
	if (user_Info->Is_Superuser == TRUE)
	{
		Clear_User_Input(user_Input);
		printf("File/Folder name: ");
		fgets(user_Input, MAX_INPUT_SIZE, stdin);

		user_Input[strcspn(user_Input, "\n")] = 0;

		char file_Path[FINAL_INPUT_SIZE];
		char secure_File_Path[FINAL_INPUT_SIZE];
		memset(file_Path, '\0', sizeof(char) * FINAL_INPUT_SIZE);
		memset(secure_File_Path, '\0', sizeof(char) * FINAL_INPUT_SIZE);

		sprintf(file_Path, "%s\\%s", current_Directory, user_Input);
		sprintf(secure_File_Path, "%s\\%s", SECURED_FILES_PATH, user_Input);

		if (File_Exists(file_Path) == FALSE)
		{
			printf("Could not find entered file.\n");
			return FALSE;
		}

		if (File_Exists(secure_File_Path) == FALSE)
		{
			printf("File is not secured. Cannot unsecure file.\n");
			return FALSE;
		}

		remove(secure_File_Path);

		return TRUE;
	}else
	{
		printf("Not logged in as Superuser, cannot make file/folder unsecure.\n");
		return FALSE;
	}
}
