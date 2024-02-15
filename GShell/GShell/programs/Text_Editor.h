#pragma once
#include <stdio.h>

typedef struct User_Info User_Info;

long Get_File_Size(FILE* file);
size_t Get_Largest_Line(FILE* file);
int File_Exists(const char* fname);
void Edit_Text_File(FILE* text_File, int max_Line_Number, char* buffer, long buffer_Size, char* user_Input);
int Open_Text_File_(const User_Info* user_Info, char* current_Directory, char* user_Input);
int Create_New_Text_File(char* current_Directory, char* user_Input);
FILE* Create_New_Text_File_Old(char* new_File_Name);