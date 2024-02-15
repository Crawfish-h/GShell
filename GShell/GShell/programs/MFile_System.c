#pragma once
#include "MFile_System.h"

#include <windows.h>
//#include <tchar.h> 
//#include <stdio.h>
#include "../User_Info.h"
#include "../Globals.c"
#include <direct.h>

void Print_Marker(const User_Info* user_Info, char* current_Directory)
{
    if (user_Info->User_Name == NULL)
    {
        printf("Guest: %s>>>", current_Directory);
    }else
    {
        printf("%s: %s>>>", user_Info->User_Name, current_Directory);
    }
    
}

void Go_Up_Directory(char* current_Directory)
{
    char home_Str[5] = "****";
    home_Str[4] = '\0';
    int j = 3;
    for (int i = strlen(current_Directory) - 1; j > -1; i--)
    {
        home_Str[j] = current_Directory[i];
        j--;
    }

    if (strcmp(home_Str, "home") != 0)
    {
        for (int i = strlen(current_Directory); i > 0; i--)
        {
            if (current_Directory[i] == '\\')
            {
                current_Directory[i] = '\0';
                return;
            }
            current_Directory[i] = '\0';
        }
    }
}

int Create_Folder(const User_Info* user_Info, char* current_Directory, char* user_Input)
{
    user_Input[strcspn(user_Input, "\n")] = '\0';
    Remove_Sub_Str(user_Input, "mkdir ");

    user_Input[strcspn(user_Input, "\n")] = 0;

    char new_Folder_Path[FINAL_INPUT_SIZE];
    memset(new_Folder_Path, '\0', sizeof(char) * FINAL_INPUT_SIZE);
    sprintf(new_Folder_Path, "%s\\%s", current_Directory, user_Input);

    if (_mkdir(new_Folder_Path) != 0)
    {
        printf("ERROR: folder could not be created!!\n");
        return FALSE;
    }

    return TRUE;
}

int Change_Directory(const User_Info* user_Info, char* current_Directory, char* user_Input)
{
    user_Input[strcspn(user_Input, "\n")] = '\0';
    Remove_Sub_Str(user_Input, "cd ");

    WIN32_FIND_DATA fd_File;
    HANDLE h_Find = NULL;

    char new_Path[FINAL_INPUT_SIZE];
    memset(new_Path, '\0', sizeof(char) * FINAL_INPUT_SIZE);

    user_Input[strcspn(user_Input, "\n")] = 0;
    sprintf(new_Path, "%s\\%s", current_Directory, user_Input);

    if ((h_Find = FindFirstFileA(new_Path, &fd_File)) == INVALID_HANDLE_VALUE)
    {
        printf("ERROR: Did not input a folder name!\n");
        return FALSE;
    }else
    {
        if (Secure_File_Check(user_Info, user_Input) == FALSE)
        {
            FindClose(h_Find);
            return FALSE;
        }

        strcpy(current_Directory, new_Path);
    }

    FindClose(h_Find);
    return TRUE;
}



// This function was gotten from online. The if statment with 'print_Sub_Files' was added by me. 
// I also converted this function from using wide chars to normal chars.
int ListDirectoryContents(const char* sDir, int print_Sub_Files)
{
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;

    char sPath[FINAL_INPUT_SIZE];

    //Specify a file mask. *.* = We want everything! 
    sprintf(sPath, "%s\\*.*", sDir);

    if ((hFind = FindFirstFileA(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
    {
        printf("Path not found: [%s]\n", sDir);
        return FALSE;
    }

    do
    {
        //Find first file will always return "."
        //    and ".." as the first two directories. 
        if (wcscmp(fdFile.cFileName, L".") != 0
            && wcscmp(fdFile.cFileName, L"..") != 0)
        {
            char file_Name[MAX_PATH];
            size_t str_Size;
            wcstombs_s(&str_Size, file_Name, MAX_PATH, fdFile.cFileName, MAX_PATH);

            //Build up our file path using the passed in 
            //  [sDir] and the file/foldername we just found: 
            sprintf(sPath, "%s\\%s", sDir, file_Name);

            //Is the entity a File or Folder? 
            if (fdFile.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                // This is a bad fix. 
                // Should actually fix the fact that an empty directory is printed rather than use a bad bandaid.
                if (strcmp(file_Name, "") != 0)
                {
                    printf("Directory: %s\n", file_Name);
                }

                if (print_Sub_Files)
                {
                    ListDirectoryContents(sPath, TRUE); //Recursion, I love it! 
                }
            }
            else {
                printf("File: %s\n", file_Name);
            }
        }
    } while (FindNextFile(hFind, &fdFile)); //Find the next file. 

    FindClose(hFind); //Always, Always, clean things up! 

    return TRUE;
}