#pragma once
typedef struct User_Info User_Info;

void Security_New_Password(User_Info* user_Info);
void Security_New_Username(User_Info* user_Info);
void Security_Login(User_Info* user_Info);