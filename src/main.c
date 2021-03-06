/**
 * @file main.c
 *
 * @brief Implementation of the main portion of the application.
 * 
 * @author Akhil Dama - akhildama@cmail.carleton.ca
 * @author Meher Vishnu Kyatham - mehervishnukyatham@cmail.carleton.ca
 * @author Naveen Billapati- naveenbillapati@cmail.carleton.ca
 * @author Rajeshwar Reddy Keesara- rajeshwarreddykeesar@cmail.carleton.ca
 */

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

#include "../include/app.h"
#include "../include/ui_design.h"
#include "../test/include/test.h"

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
           start_automated_testing();
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
		log:
		do {

			 loginuserptr = authUser(&loginuser);
			
			
			
		}while(loginuserptr == NULL || loginuserptr->isLoggedIn==0);  //user == NULL

		do {
						int choice = userMenu();
						execUserMenuChoice(choice,loginuserptr);
					}while(loginuserptr->isLoggedIn==1);
					loginuserptr = NULL;
		goto log;

	return 0;
}
