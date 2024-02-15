#pragma once

typedef struct User_Info User_Info;
void Print_Marker(const User_Info* user_Info, char* current_Directory);
void Go_Up_Directory(char* current_Directory);
int Create_Folder(const User_Info* user_Info, char* current_Directory, char* user_Input);
int Change_Directory(const User_Info* user_Info, char* current_Directory, char* user_Input);

typedef unsigned short wchar_t;
int ListDirectoryContents(const char* sDir, int print_Sub_Files);