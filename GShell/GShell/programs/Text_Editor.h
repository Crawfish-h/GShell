#pragma once
#include <stdio.h>

long Get_File_Size(FILE* file);
size_t Get_Largest_Line(FILE* file);
int File_Exists(const char* fname);
void Edit_Text_File(FILE* text_File, int max_Line_Number, char* buffer, long buffer_Size);
void Open_Text_File_();
FILE* Create_New_Text_File();
FILE* Create_New_Text_File_Old(char* new_File_Name);