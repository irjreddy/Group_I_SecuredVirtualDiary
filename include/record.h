#include <stdio.h>


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