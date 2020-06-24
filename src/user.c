/**
 * @file user.c
 *
 * @brief This is the file where all the user related auth, sign, sign up will be handled here
 * 
 * @author Akhil Dama - akhildama@cmail.carleton.ca
 * @author Meher Vishnu Kyatham - mehervishnukyatham@cmail.carleton.ca
 * @author Naveen Billapati- naveenbillapati@cmail.carleton.ca
 * @author Rajeshwar Reddy Keesara- rajeshwarreddykeesar@cmail.carleton.ca
 */
#include "../include/user.h"
#include "../include/ui_design.h"


int isuser( const char *username,const char *password,user *loginuser);

int signIn(user *loginuser){

	char username[20], password[20];
	loginuser->username = malloc(20*sizeof(char));
	loginuser->password = malloc(20*sizeof(char));
	
	red();
	printf("Username : ");reset();
	scanf("%s", username);
	getchar();
	red();
	printf("Password : ");reset();
	scanf("%s", password);  
    


	getchar();
	printf("\n\n\n\n");
	
	if(isuser(username, password,loginuser)){
		strcpy(loginuser->username, username);
		strcpy(loginuser->password, password);
		loginuser->isLoggedIn = 1;

		return 1;
	}

	else return 0;


return 0;
}

int isuser(const char* username, const char* password, user *loginuser){ //Check if the user exists 


	char fileusername[20], filepass[20];
    int count =0;

	FILE* usersfile = fopen("users.txt", "r");
	char filemail[20];

    if(usersfile== NULL)
    {
        //printf("No Users Found, Sign UP First!");
        return 0;
    }

	while(!feof(usersfile)){
		fscanf(usersfile, "%s %s %s", fileusername, filepass,filemail);
		if(strcmp(username, fileusername) == 0 && strcmp(password, filepass) == 0){
            loginuser->line = count;
			fclose(usersfile);
			return 1;
		}
	}

	fclose(usersfile);
	return 0;
}



int availableuser(const char *username){ //Check if username already exists
    char taken[20],  takenpass[20], fileusername[20];

    
    FILE* usersfile = fopen("users.txt", "r");

	if(usersfile != NULL){

	while(!feof(usersfile)){
        fscanf(usersfile, "%s %s %s", taken, takenpass, fileusername);
        
        if(strcmp(username, taken) == 0){
            fclose(usersfile);
            return 0;
        }
    }

	}

    

    fclose(usersfile);
    return 1;
}


void createuser(user *newuser){ //Create a new user

    newuser->username = (char *)malloc(20*sizeof(char));
    newuser->email = (char *)malloc(20*sizeof(char));
    newuser->password = (char *)malloc(20*sizeof(char));
    newuser->line = (int )malloc(20*sizeof(int));
    

    char confirm[20];

    printf("\n");
    printf("Sign up : \n");


    
    printf("Name : ");
    scanf("%s", newuser->username);
    getchar();
    
	 FILE* usersfile = fopen("users.txt", "r");
	 if(usersfile != NULL)
	 {
		while(!availableuser(newuser->username)){
				printf("Username is taken\nPick another one : ");
				scanf("%s", newuser->username);
				getchar();
			}
	 }

   
    
	    printf("Email : ");
    scanf("%s", newuser->email);
    getchar();


    printf("Password : ");
    scanf("%s", newuser->password);
    getchar();
while(strlen(newuser->password)<8)
    {
        printf("Password should be more than 8 characters! \n");
        red();
	    printf("Password : ");reset();
	    scanf("%s", newuser->password);  
    }

    printf("Confirm password : ");
    scanf("%s", confirm);
    

    while(strcmp(newuser->password, confirm) != 0){
        printf("The passwords should match\nPlease try again \nPassword : ");
        scanf("%s", newuser->password);
        getchar();
        printf("Confirm : \n");
        scanf("%s", confirm);
        getchar();
    }
}



void registeruser(user *newuser){ //register a new user
	
    FILE *usersfile = fopen("users.txt", "a");
	if(usersfile == NULL)
	{
		printf("Cloud not create an user");
	}
	else{
fprintf(usersfile, "%s %s %s \n", newuser->username, newuser->password, newuser->email);
	}


    

	fclose(usersfile);
}   




int signUp(user *newuser){

    createuser(newuser);
    registeruser(newuser);
    newuser->isLoggedIn = 1;

return 0;
}





int check_password(char *check_pass)

{

    int j;

    printf("For Security, Enter your old password");

    printf("** ONLY THREE TRIALS ARE ALLOWED **");

    for(j=0; j<3; j++)

    {

        

        printf("\n\n\tENTER THE PASSWORD:");


	
	char  password[20];
	
	scanf("%s", password);
	getchar();
	printf("\n");
	
	

        
        if(strcmp(password,check_pass)==0)

        {

            printf("\n\n\tACCESS GRANTED...\n");

            return 0;

        }

        else

        {

            printf("\n\n\tWRONG PASSWORD..\n\n\tACCESS DENIED...\n");


        }

    }

    printf("\n\n\t::YOU ENTERED WRONG PASSWORD::YOU ARE NOT ALLOWED TO ACCESS ANY FILE::\n\n\tPRESS ANY KEY TO GO BACK...");

    getchar();

    return 1;

}

int editPassword(user *loginuserptr)

{

   

    printf("\n");

    char confirm[15]= {0};

    int choice,check;

    FILE *fp;

    fp=fopen("users.txt","rb");

    if(fp==NULL)

    {

        fp=fopen("users.txt","wb");

        if(fp==NULL)

        {

            printf("SYSTEM ERROR...");

            getchar();

            return 0 ;

        }

        fclose(fp);

        printf("\n Could not find ther users file, system error ...\nYOUR PASSWORD IS 'ENTER'\n PRESS ENTER TO CHANGE PASSWORD\n\n");

        getchar();

    }

    fclose(fp);

    check=check_password(loginuserptr->password);

    if(check==1)

    {

        return 0;

    }

    do

    {

        if(check==0)

        {

            

            choice=0;
			char  password[20];

            printf("\n\n\tENTER THE NEW PASSWORD:");

            fflush(stdin);

           
	scanf("%s", password);
	getchar();
	printf("\n");

          

            i=0;

            printf("\n\tCONFIRM PASSWORD:");

            scanf("%s", confirm);
	getchar();
	printf("\n");

           
            if(strcmp(password,confirm)==0)

            {

                fp=fopen("users.txt","r+");

                if(fp==NULL)

                {

                    printf("\n\t\tSYSTEM ERROR");
                    fclose(fp);
                    getchar();

                    return 0;

                }

                i=0;
				fclose(fp);
                char fileusername[20], filepass[20], fileemail[20];
                int count =0;

	            FILE* usersfile = fopen("users.txt", "r");
                FILE* backupfile = fopen("temp.txt", "w");
    
   
    



    while( !feof(usersfile)){
	fscanf(usersfile, "%s %s %s ", fileusername, filepass, fileemail);
   
        count++;
       

		if(strcmp(loginuserptr->username, fileusername) == 0 && strcmp(loginuserptr->password, filepass) == 0){
            fprintf(backupfile,"%s %s %s \n",fileusername, password, fileemail);
            loginuserptr->password = password;
		 }
        else{
           // fputs(buffer,backupfile);
             fprintf(backupfile,"%s %s %s \n",fileusername, filepass, fileemail);
        }
	}
    
	fclose(usersfile);
      fclose(fp);
      fclose(backupfile);
      if(remove("users.txt")==-1 || rename("temp.txt","users.txt")==-1)
      {
          printf("System Error: Password change failed, restart the application to resolve");
            getchar();
	        return 0;
      }

            }

            else

            {

                printf("\n\tTHE NEW PASSWORD DOES NOT MATCH.");

                choice=1;

            }

        }

    }
    while(choice==1);

    printf("\n\n\tPASSWORD CHANGED...\n\n\tPRESS ANY KEY TO GO BACK...");

    getchar();
	return 0;

}
