#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
	char *username;
	char *email;
	
	char *password;
	
	int isLoggedIn;
	int line;
}user;



int signIn(user *loginuser);

int signUp(user *newuser);

int editPassword(user *loginptr);
