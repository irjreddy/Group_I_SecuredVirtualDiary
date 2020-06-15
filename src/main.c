#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

#include "../include/app.h"
#include "../include/ui_design.h"

#ifdef _WIN32	//If in windows
	#define CLEAR system("cls");
#else 
	#define CLEAR system("clear");	//If linux/Mac
#endif




int main()
{
	

		loading();
		CLEAR
		welcome_screen(); // show welcome page
		sleep(3);
		CLEAR
		printf("********   Welcome To your Secured Virtual Diary   ********\n");

		do {
			int choice = userMenu();
			execChoice(choice);
		}while(1);
		

	return 0;
}
