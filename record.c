#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

 typedef struct User
{
	char *name;
	char *email;
	
	char *password;
	
	int isLoggedIn;
}user;
typedef struct 
{
	user *creator;
	char *subject;
	char *data;
	int day;
	int month;
	int year;
}post;

void clean_stdin(){ //clean the buffer
    int c;
 
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
void newRecord(){ //create a new record
	//FILE *postfile = fopen("post.txt", "a+");
	char data[150] = "";
	char finalpost[500] = "";
	char post_subject[50]="";
	post post_creator; 
	post_creator.creator = ""; // should be logged in username
    
    
   
	time_t mtime;                       
	time(&mtime);
	struct tm *lt = localtime(&mtime); //returns  localtime

	post_creator.day = (int)lt->tm_mday;
	post_creator.month = (int)lt->tm_mon+1;
	post_creator.year =  (int)lt->tm_year+1900;

	
	printf("This is your Editor, you can type anything");
	printf("Start writing and press CTRL + X on a new line when finished\n");
	printf("====================================================================\n\n\n");

	

    printf("Enter subject for the post \n");
    fgets(post_subject, sizeof(post_subject),stdin);
	post_creator.subject = post_subject;
    printf("Enter Record Now: \n ");
    clean_stdin();
	while(*data != 24){ //Enable user to write until he types CTRL + X
		fgets(data, sizeof(data), stdin);
		strcat(finalpost, data);
	}
//	post_subject[strlen(post_subject)-1] = "\0";
	 //snprintf(post_subject, sizeof(post_subject), "%s.txt", post_subject);
	char date_str[100];
	snprintf(date_str, sizeof(date_str), "%d-%d-%d.txt", post_creator.day, post_creator.month, post_creator.year);
    printf("Todays date is %s ",date_str);


    FILE *postfile = fopen(date_str,"w");
    fprintf(postfile, "Date : %d/%d/%d Heure : %d:%d\n", post_creator.day, post_creator.month, post_creator.year, (int)lt->tm_hour, (int)lt->tm_min);

	post_creator.data = finalpost;
	
	finalpost[strlen(finalpost)-1] = '\0'; /*So that no extra char in added in the post*/
	
	printf("\n\n\n");
	printf("Your post : \n%s\n", finalpost);
	fprintf(postfile, "Subject :%s\n", post_creator.subject);
	fprintf(postfile, "Post :\n%s\n-- Complete --\n\n\n", post_creator.data);
	
	fclose(postfile);
}



int main(int argc, char const *argv[])
{
	newRecord();

	
	
	return 0;
}