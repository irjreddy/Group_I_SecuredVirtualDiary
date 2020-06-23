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




int main(int argc, char* argv[])
{
	int opt;
	while ((opt = getopt(argc, argv, "t")) != -1) {
        switch (opt) {
        case 't':
            /* Run automated unit testing */
			red();
            printf("Running automated unit testing\n");
			reset();
          //  start_automated_testing();
		  red();
            printf("Automated testing has completed\n");
			reset();
            return 1;
            break;
		default:
			red();
            printf("Executable file of appplication will be placed here ");reset();
            break;
		}
	}
	user loginuser;
	user* loginuserptr = NULL;
	

		loading();
		CLEAR
		welcome_screen(); // show welcome page
		sleep(3);
		CLEAR
		red();
		fflush(stdin);
		printf("********   Welcome To your Secured Virtual Diary   ********\n");
		reset();
		
		do {

			 loginuserptr = authUser(&loginuser);
			

			
		}while(loginuserptr == NULL);  //user == NULL

		do {
			int choice = userMenu();
			execUserMenuChoice(choice,loginuserptr);
		}while(1);
		

	return 0;
}
