#pragma once
// THIS FILE SHOULD ONLY BE INCLUDED IN GSECURITY, NO WHERE ELSE!! <<< ignore this.

typedef struct User_Info
{
	int Id;
	int Is_Superuser;
	char* Password;
	char* User_Name;
} User_Info;

