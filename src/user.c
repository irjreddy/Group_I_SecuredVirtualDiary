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



int availableuser(const char *username){ //Check if pseudo already exists
    char taken[20],  takenpass[20], fileusername[20];

    int age;
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
    newuser->line = (int *)malloc(20*sizeof(int));
    

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
    
	    printf("Email : ");
    scanf("%s", newuser->email);
    getchar();


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
    FILE *usersfile = fopen("users.txt", "a+");

    fprintf(usersfile, "%s %s %s\n", newuser->username, newuser->password, newuser->email);

char fileusername[20], filepass[20];
int count = 0;
rewind(usersfile);

	while(!feof(usersfile)){
		fscanf(usersfile, "%s %s", fileusername, filepass);
        count++;
		if(strcmp(newuser->username, fileusername) == 0 && strcmp(newuser->password, filepass) == 0){
			fclose(usersfile);
			newuser->line = count;
            break;
		}
	}

    

	fclose(usersfile);
}   




int signUp(user *newuser){

    createuser(newuser);
    registeruser(newuser);
    newuser->isLoggedIn = 1;

return 0;
}





int password(char *check_pass)

{

    char pass[15]= {0},check[15]= {0},ch;

    FILE *fpp;

    int i=0,j;

    printf("For Security, Enter your old password");

    printf("** ONLY THREE TRIALS ARE ALLOWED **");

    for(j=0; j<3; j++)

    {

        i=0;

        printf("\n\n\tENTER THE PASSWORD:");

        pass[0]=getch();

        while(pass[i]!='\r')

        {

            if(pass[i]=='\b')

            {

                i--;

                printf("\b");

                printf(" ");

                printf("\b");

                pass[i]=getch();

            }

            else

            {

                printf("*");

                i++;

                pass[i]=getch();

            }

        }

        pass[i]='\0';

        

//         if (fpp==NULL)

//         {
// fclose(fpp);
//             printf("\n System error, file missing\n");

//             getch();
            

//             return 1;

//         }

//         else

//             i=0;

     

        if(strcmp(pass,check_pass)==0)

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

    getch();

    return 1;

}

int editPassword(user *loginuserptr)

{

   

    printf("\n");

    char pass[15]= {0},confirm[15]= {0},ch;

    int choice,i,check;

    FILE *fp;

    fp=fopen("users.txt","rb");

    if(fp==NULL)

    {

        fp=fopen("users.txt","wb");

        if(fp==NULL)

        {

            printf("SYSTEM ERROR...");

            getch();

            return ;

        }

        fclose(fp);

        printf("\n Could not find ther users file, system error ...\nYOUR PASSWORD IS 'ENTER'\n PRESS ENTER TO CHANGE PASSWORD\n\n");

        getch();

    }

    fclose(fp);

    check=password(loginuserptr->password);

    if(check==1)

    {

        return ;

    }

    do

    {

        if(check==0)

        {

            i=0;

            choice=0;

            printf("\n\n\tENTER THE NEW PASSWORD:");

            fflush(stdin);

            pass[0]=getch();

            while(pass[i]!='\r')

            {

                if(pass[i]=='\b')

                {

                    i--;

                    printf("\b");

                    printf(" ");

                    printf("\b");

                    pass[i]=getch();

                }

                else

                {

                    printf("*");

                    i++;

                    pass[i]=getch();

                }

            }

            pass[i]='\0';

            i=0;

            printf("\n\tCONFIRM PASSWORD:");

            confirm[0]=getch();

            while(confirm[i]!='\r')

            {

                if(confirm[i]=='\b')

                {

                    i--;

                    printf("\b");

                    printf(" ");

                    printf("\b");

                    confirm[i]=getch();

                }

                else

                {

                    printf("*");

                    i++;

                    confirm[i]=getch();

                }

            }

            confirm[i]='\0';

            if(strcmp(pass,confirm)==0)

            {

                fp=fopen("users.txt","r+");

                if(fp==NULL)

                {

                    printf("\n\t\tSYSTEM ERROR");
                    fclose(fp);
                    getch();

                    return ;

                }

                i=0;
fclose(fp);
                char fileusername[20], filepass[20], fileemail[20];
                int count =0;

	            FILE* usersfile = fopen("users.txt", "r");
                FILE* backupfile = fopen("temp.txt", "w");
    
    char buffer[50];
    char bb[1000];



    while( !feof(usersfile)){
	fscanf(usersfile, "%s %s %s ", fileusername, filepass, fileemail);
   
        count++;
        //fprintf(backupfile,"%s %s %s",fileusername, filepass, fileemail);
       
        // if(count== loginuserptr->line)
        // {
            
        //      sprintf(buffer,"%s %s %s",loginuserptr->username,pass,loginuserptr->email);
        //     fputs(buffer,backupfile);
        // }

		if(strcmp(loginuserptr->username, fileusername) == 0 && strcmp(loginuserptr->password, filepass) == 0){
            fprintf(backupfile,"%s %s %s \n",fileusername, pass, fileemail);

		 }
        else{
           // fputs(buffer,backupfile);
             fprintf(backupfile,"%s %s %s \n",fileusername, filepass, fileemail);
        }
	}
    
	

    //      while ((fgets(buffer, 1000, usersfile)) != NULL)
    // {
    //     count++;

    //     snprintf(bb, 1000, "%s %s %s", loginuserptr->username, pass, loginuserptr->email);

    //     /* If current line is line to replace */
    //     if (count == loginuserptr->line)
    //         fputs(bb, backupfile);
    //     else
    //         fputs(buffer, backupfile);
    // }
	

	fclose(usersfile);
      fclose(fp);
      fclose(backupfile);
      
    printf("removing file %d",remove("users.txt"));
    
    
    rename("temp.txt","users.txt");
              

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

    getch();

}
