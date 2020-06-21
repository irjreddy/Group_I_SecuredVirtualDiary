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



int availableuser(const char *username){ //Check if pseudo already exists
    char taken[20],  takenpass[20], username[20];

    int age;
    FILE* usersfile = fopen("users.txt", "r");

    while(!feof(usersfile)){
        fscanf(usersfile, "%s %s %s", taken, takenpass, username);
        
        if(strcmp(username, taken) == 0){
            fclose(usersfile);
            return 0;
        }
    }

    fclose(usersfile);
    return 1;
}


void createuser(user *newuser){ //Create a new user

    newuser->username = (char *)malloc(20*sizeof(char));
    newuser->email = (char *)malloc(20*sizeof(char));
    newuser->password = (char *)malloc(20*sizeof(char));
    

    char confirm[20];

    printf("\n");
    printf("Sign up : \n");


    
    printf("Name : ");
    scanf("%s", newuser->username);
    getchar();
    

    while(!availableuser(newuser->username)){
        printf("Username is taken\n pick another one : ");
        scanf("%s", newuser->username);
        getchar();
    }
    
    printf("Password : ");
    scanf("%s", newuser->password);
    getchar();
    printf("Confirm password : ");
    scanf("%s", &confirm);
    confirm[strlen(confirm)] = '\0';

    while(strcmp(newuser->password, confirm) != 0){
        printf("The passwords should match\n Please try again \nPassword : ");
        scanf("%s", newuser->password);
        getchar();
        printf("Confirm : \n");
        scanf("%s", confirm);
        getchar();
    }
}



void registeruser(user *newuser){ //register a new user
    FILE *pseudo = fopen("users.txt", "a+");

    fprintf(pseudo, "%s %s %s\n", newuser->username, newuser->password, newuser->email);
    fclose(pseudo);
}   




int signUp(user *newuser){

    createuser(newuser);
    registeruser(newuser);
    newuser->isLoggedIn = 1;

return 0;
}