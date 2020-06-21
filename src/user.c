#include "../include/user.h"


int signIn(user *loginuser){

	char username[20], password[20];
	loginuser->username = malloc(20*sizeof(char));
	loginuser->password = malloc(20*sizeof(char));
	

	printf("Username : ");
	scanf("%s", username);
	getchar();
	printf("Password : ");
	scanf("%s", password);
	getchar();
	printf("\n\n\n\n");
	
	if(isuser(username, password)){
		strcpy(loginuser->username, username);
		strcpy(loginuser->password, password);
		loginuser->isLoggedIn = 1;

		return 1;
	}

	else return 0;


return 0;
}

int isuser(const char* username, const char* password){ //Check if the user exists 


	char fileusername[20], filepass[20];

	FILE* usersfile = fopen("users.txt", "r");

	while(!feof(usersfile)){
		fscanf(usersfile, "%s %s", fileusername, filepass);
		if(strcmp(username, fileusername) == 0 && strcmp(password, filepass) == 0){
			fclose(usersfile);
			return 1;
		}
	}

	fclose(usersfile);
	return 0;
}

