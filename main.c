#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

#include "app.h"

#ifdef _WIN32	//If in windows
	#define CLEAR system("cls");
#else 
	#define CLEAR system("clear");	//If linux/Mac
#endif


void welcome_screen(){
	
}

int main()
{
	
	
	
		CLEAR
		welcome_screen(); // show welcome page

		printf("********   Welcome To your Secured Virtual Diary   ********\n");

	
		int choice = userMenu();
		execChoice(choice);

	return 0;
}
