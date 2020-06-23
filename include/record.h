#include <stdio.h>
#include "../include/user.h"

typedef struct 
{
	user *creator;
	char *subject;
	char *data;
	int day;
	int month;
	int year;
}post;

void addRecord(user *loginptr);
int deleteRecord(user *loginptr);
int viewRecord(user *loginptr);
int editRecord(user *loginptr);