#include <stdio.h>
#include <ctype.h>
#include <unistd.h>



#ifdef _WIN32	//If in windows
	#define CLEAR system("cls");
#else 
	#define CLEAR system("clear");	//If linux/Mac
#endif

int menu(){ //Menu options, returns the selected option
	int option;

	printf("\t[1] Add Todays Record \n");
	printf("\t[2] View Previous Records\n");
	printf("\t[2] Edit Records\n");

	printf("Choice : ");

	option = scanf("%d", &option);

	return option;
}



int main()
{
	
	
	
		CLEAR
		
		printf("********   Welcome To your Secured Virtual Diary   ********\n");

	
		printf(" Please Select an option from menu :)\n");
		int option = menu();
printf(" You Have Selected option %d \n",option);

	return 0;
}
