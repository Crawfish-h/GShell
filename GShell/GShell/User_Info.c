#include "User_Info.h"
// THIS FILE SHOULD BE INCLUDED NOWHERE!!

//typedef struct User_Info
//{
//	int Id;
//	char* Password;
//	char* User_Name;
//} User_Data;

//struct User_Info
//{
//	// OUTSIDE OF USER FUNCTIONS: DO NOT TOUCH THIS VARIABLE, DO NOT LOOK AT IT, DO NOT CHANGE IT.
//	void* _Data;
//};
//
//void Init(User_Info* user_Info, int id, char* password, char* user_Name)
//{
//	User_Data* user_Data = (User_Data*)user_Info->_Data;
//
//	user_Data->Id = id;
//	user_Data->Password = password;
//	user_Data->User_Name = user_Name;
//}
//
//void User_Set_Id(User_Info* user_Info, int id)
//{
//	User_Data* user_Data = (User_Data*)user_Info->_Data;
//	user_Info->_Data.Id = id;
//}
//
//void User_Set_Password(User_Info* user_Info, int password)
//{
//	user_Info->_Data.Password = password;
//}
//
//void User_Set_Name(User_Info* user_Info, int user_Name)
//{
//	user_Info->_Data.User_Name = user_Name;
//}