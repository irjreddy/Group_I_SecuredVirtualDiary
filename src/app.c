#include<stdio.h>
#include "../include/app.h"
#include "../include/record.h"


#ifdef _WIN32	//If in windows
#include "../include/calendar.h"
#else 
	
#endif


#ifdef _WIN32	//If in windows
	#define CLEAR system("cls");
#else 
	#define CLEAR system("clear");	//If linux/Mac
#endif


int mainMenu(){ // displays User Menu, then returns the selected option
	int option;

	
printf(" Please Select an option from the Main Menu\n");
	printf("\t[1] Sign IN \n"); // SHOULD LINK RECORD.C ADDRECORD() FUNCTION LATER ON

	printf("\t[2] Sign UP \n");
	

	printf("Please Enter your Choice : ");

	
	
	//if user enter something that is not the option, we show error
	while(scanf("%d", &option) !=1 || option<1 || option >2)
	{
		printf(" Sorry, Please select a valid choice from the above!");
	}

	return option;
}

int userMenu(){ // displays User Menu, then returns the selected option
	int option;

	
printf(" Please Select an option from the User menu\n");
	printf("\t[1] Add Todays Record \n"); // SHOULD LINK RECORD.C ADDRECORD() FUNCTION LATER ON

	printf("\t[2] View Previous Records\n");
	printf("\t[3] Edit Records\n");
	printf("\t[4] Delete Records\n");  // should link delete function when switch case is ready
	printf("\t[5] Search Records \n");
	printf("\t[6] Monthly CalenderView \n");
	printf("\t[7] Edit Password \n"); // this option will be available in release 2

	printf("Please Enter your Choice : ");

	
	
	//if user enter something that is not the option, we show error
	while(scanf("%d", &option) !=1 || option<1 || option >7)
	{
		printf(" Sorry, Please select a valid choice from the above!");
	}

	return option;
}



int execMainMenuChoice(int choice){
	switch(choice)
	{
		case 1:
		return signIn();
		break;
		case 2:
		return signUp();
		break;
	}
	return 0;
}

void execUserMenuChoice(int choice){

	switch(choice)
	{
		case 1:
		addRecord();
		break;

		case 2:
		viewRecord();
		break;

		case 3:
		editRecord();
		break;

		case 4:
		deleteRecord();
		break;

		case 5:
		break;

		case 6:
		#ifdef _WIN32	//If in windows
			
		#else 
			//runCalendar();
				CLEAR
		#endif
		
		break;

		case 7:
		break;

		
	}
}


