#pragma once
typedef struct User_Info User_Info;

void Security_New_Password(User_Info* user_Info, char* user_Input);
void Security_New_Username(User_Info* user_Info, char* user_Input);
int Security_Login(User_Info* user_Info, char* user_Input);
void Print_Login(User_Info* user_Info, char* user_Input);
void Sign_Into_Guest(User_Info* user_Info, char* user_Input);
int Sign_Into_Superuser(User_Info* user_Info, char* user_Input);
int Secure_File(User_Info* user_Info, char* current_Directory, char* user_Input);
int Unsecure_File(User_Info* user_Info, char* current_Directory, char* user_Input);