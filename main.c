#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

#include "app.h"
#include "ui_design.h"

#ifdef _WIN32	//If in windows
	#define CLEAR system("cls");
#else 
	#define CLEAR system("clear");	//If linux/Mac
#endif




int main()
{
	
	
	
		CLEAR
		loading();
		CLEAR
		welcome_screen(); // show welcome page
		
		CLEAR
		printf("********   Welcome To your Secured Virtual Diary   ********\n");

	
		int choice = userMenu();
		execChoice(choice);

	return 0;
}
