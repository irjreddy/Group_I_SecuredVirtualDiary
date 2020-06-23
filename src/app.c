#include<stdio.h>
#include "../include/app.h"
#include "../include/ui_design.h"

#include "../include/calendar.h"

#ifdef _WIN32	//If in windows
	#define CLEAR system("cls");
#else 
	#define CLEAR system("clear");	//If linux/Mac
#endif


user* authUser(user *loginuser){ 

	
		int choice=0;
		red();
		printf(" Please Select an option from the Main Menu\n");

	printf("1. Sign in\n2. Sign up\n\nChoice : ");
	reset();
	while(scanf("%d", &choice) != 1 || choice < 1 || choice > 2){
		getchar(); 
		red();
		printf("Wrong Choice \nPlease choose option between 1 and 2 \nChoice : ");reset();
		
	}
	getchar();
	
	if(choice == 1){
		printf("\n");
		int login = signIn(loginuser);

		if(login){ //--> if(login == 1)
			red();
	 		printf(" === Welcome %s ! ===\n\n", loginuser->username);reset();
		} 
		else {
	 		printf("Can't login \n Would you like to create an Account?\n");
	 		return NULL;
	 	}
	}
	else signUp(loginuser);

	return loginuser;
}

int userMenu(){ // displays User Menu, then returns the selected option
	int option;

	
printf("Please Select an option from the User menu\n");
	printf("\t[1] Add Todays Record \n"); // SHOULD LINK RECORD.C ADDRECORD() FUNCTION LATER ON

	printf("\t[2] View Previous Records\n");
	printf("\t[3] Edit Records\n");
	printf("\t[4] Delete Records\n");  // should link delete function when switch case is ready
	printf("\t[5] Monthly CalenderView \n");
	printf("\t[6] Edit Password \n");
	printf("\t[7] Exit \n"); // this option will be available in release 2

	printf("Please Enter your Choice : ");

	
	
	//if user enter something that is not the option, we show error
	while(scanf("%d", &option) !=1 || option<1 || option >7)
	{
		getchar();
		printf("Sorry, Please select a valid choice from the above!");
		fflush(stdin);
	}

	return option;
}


void execUserMenuChoice(int choice, user *loginptr){

	switch(choice)
	{
		case 1:
		addRecord(loginptr);
		break;

		case 2:
		viewRecord(loginptr);
		break;

		case 3:
		editRecord(loginptr);
		break;

		case 4:
		deleteRecord(loginptr);
		break;

		case 5:
		runCalendar(loginptr);
				CLEAR
		break;

		case 6:
		editPassword(loginptr);
		break;

		case 7:
		exit(0);
		break;
		

		
	}
}


