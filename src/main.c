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
	int opt;
	while ((opt = getopt(argc, argv, "t")) != -1) {
        switch (opt) {
        case 't':
            /* Run automated unit testing */
            printf("Running automated unit testing\n");
            start_automated_testing();
            printf("Automated testing has completed\n");
            return 1;
            break;
		default:
            printf("Executable file of appplication will be placed here ");
            break;
		}
	}
	user loginuser;
	user* loginuserptr = NULL;
	char c;

		loading();
		CLEAR
		welcome_screen(); // show welcome page
		sleep(3);
		CLEAR
		printf("********   Welcome To your Secured Virtual Diary   ********\n");
		int user=0;
		do {

			 loginuserptr = authUser(&loginuser);
			

			
		}while(loginuserptr == NULL);  //user == NULL

		do {
			int choice = userMenu();
			execUserMenuChoice(choice);
		}while(1);
		

	return 0;
}
