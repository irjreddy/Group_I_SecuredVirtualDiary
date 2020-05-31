#include <stdio.h>
#include <ctype.h>
#include <unistd.h>



#ifdef _WIN32	//If in windows
	#define CLEAR system("cls");
#else 
	#define CLEAR system("clear");	//If linux/Mac
#endif

int userMenu(){ // displays User Menu, then returns the selected option
	int option;

	printf("\t[1] Add Todays Record \n");
	printf("\t[2] View Previous Records\n");
	printf("\t[2] Edit Records\n");
	printf("\t[2] Delete Records\n");
	printf("\t[2] Search Records \n");
	printf("\t[2] Monthly CalenderView \n");
	printf("\t[2] Edit Password \n"); // this option will be available in release 2

	printf("Please Enter your Choice : ");

	option = scanf("%d", &option);

	return option;
}

void welcome_screen(){
	
}

int main()
{
	
	
	
		CLEAR
		welcome_screen(); // show welcome page

		printf("********   Welcome To your Secured Virtual Diary   ********\n");

	
		printf(" Please Select an option from the User menu\n");
		int option = menu();
printf(" You Have Selected option %d \n",option);

	return 0;
}
