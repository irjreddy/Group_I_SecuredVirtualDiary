#include <stdio.h>

 typedef struct User
{
	char *name;
	char *email;
	
	char *password;
	
	int isLoggedIn;
}user;
typedef struct 
{
	user *creator;
	char *subject;
	char *data;
	int day;
	int month;
	int year;
}post;

void addRecord();
int deleteRecord();
int viewRecord();