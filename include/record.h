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

void addRecord();
int deleteRecord();
int viewRecord();
int editRecord();