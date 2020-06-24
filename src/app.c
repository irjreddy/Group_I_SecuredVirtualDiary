/**
 * @file app.c
 *
 * @brief This is the application file which is used to link everything in the project.
 * 
 * @author Akhil Dama - akhildama@cmail.carleton.ca
 * @author Meher Vishnu Kyatham - mehervishnukyatham@cmail.carleton.ca
 * @author Naveen Billapati- naveenbillapati@cmail.carleton.ca
 * @author Rajeshwar Reddy Keesara- rajeshwarreddykeesar@cmail.carleton.ca
 */

#include<stdio.h>
#include "../include/app.h"
#include "../include/ui_design.h"



#ifdef _WIN32	//If in windows
	#define CLEAR system("cls");
#else 
	#define CLEAR system("clear");	//If linux/Mac
#endif


user* authUser(user *loginuser){ 

	
		int choice=0;
		red();
		printf("Please Select an option from the Main Menu\n");

	printf("1. Sign in\n2. Sign up\n3. Admin Login\nChoice : ");
	reset();
	while(scanf("%d", &choice) != 1 || choice < 1 || choice > 3){
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
	}else if(choice == 3)
	{
		
	char username[20], password[20];
	
	
	red();
	printf("Username : ");reset();
	scanf("%s", username);
	getchar();
	red();
	printf("Password : ");reset();
	scanf("%s", password);  
	getchar();
	printf("\n\n\n\n");
	
	if(strcmp(username,"root") ==0 && strcmp(password,"12345678")==0)
	{
			char fileusername[20], filepass[20];
    int count =0;

	FILE* usersfile = fopen("users.txt", "r");
	char filemail[20];

    if(usersfile== NULL)
    {
        printf("No Users Found");
        return NULL;
    }

	while(!feof(usersfile)){
		fscanf(usersfile, "%s %s %s", fileusername, filepass,filemail);
		count++;
		printf("Username: %s     Email: %s \n",fileusername, filemail);
	}
	printf("\n\nYou have %d registered users \n Hit Enter to go back", count);
	getchar();
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
	printf("\t[5] Edit Password \n");
	printf("\t[6] Signout \n");
	printf("\t[7] Exit From Application\n"); // this option will be available in release 2

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
		editPassword(loginptr);
		break;

		case 6:
		loginptr->isLoggedIn =0;
		//signout(loginptr);
		break;

		case 7:
		exit(0);
		break;
		

		
	}
}


