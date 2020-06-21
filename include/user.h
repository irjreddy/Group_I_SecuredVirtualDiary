#include <stdio.h>

 typedef struct User
{
	char *username;
	char *email;
	
	char *password;
	
	int isLoggedIn;
}user;

int signIn(user *loginuser);

int signUp(user *newuser);