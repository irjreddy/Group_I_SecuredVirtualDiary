#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/record.h"

void clean_stdin(){ //clean the buffer
    int c;
 
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
void addRecord(){ //create a new record
	
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
	getchar();
	
    fgets(post_subject, sizeof(post_subject),stdin);
	post_creator.subject = post_subject;
    printf("Enter Record Now: \n ");
	getchar();
    clean_stdin();
	while(*data != 24){ //Enable user to write until he types CTRL + X which is the 24
		fgets(data, sizeof(data), stdin);
		strcat(finalpost, data);
	}

	char date_str[100];
	snprintf(date_str, sizeof(date_str), "%d-%d-%d.txt", post_creator.day, post_creator.month, post_creator.year);
    printf("Todays date is %s ",date_str);


    FILE *postfile = fopen(date_str,"w");
    fprintf(postfile, "Date : %d/%d/%d Heure : %d:%d\n", post_creator.day, post_creator.month, post_creator.year, (int)lt->tm_hour, (int)lt->tm_min);

	post_creator.data = finalpost;
	
	finalpost[strlen(finalpost)-1] = '\0'; 
	
	printf("\n\n\n");
	printf("Your post : \n%s\n", finalpost);
	fprintf(postfile, "Subject :%s\n", post_creator.subject);
	fprintf(postfile, "Post :\n%s\n-- Complete --\n\n\n", post_creator.data);
	
	fclose(postfile);
}

int deleteRecord(){
	char filename[50] ="";
	FILE *fp;
	 printf("\n Enter date of record to be delted:[dd-mm-yyyy]:");
				getchar();
				
                fgets(filename,sizeof(filename),stdin);
				 filename[strlen(filename)-1] = '\0';
				
				snprintf(filename, sizeof(filename), "%s.txt", filename);
				
                fp = fopen (filename, "r" ) ;

                if ( fp == NULL )

                {

                    printf("\n Sorry, file does not exists, please check date entered!");

                
                    return -1 ;

                }

                fclose(fp);

                remove(filename);

                printf("\n Deleted...");
				return 0;

}


int viewRecord(){
char filename[50] ="";
	FILE *recordFile;
	 printf("\n Enter date of record to be Viewed:[dd-mm-yyyy]:");
				getchar();
				
                fgets(filename,sizeof(filename),stdin);
				 filename[strlen(filename)-1] = '\0';
				
				snprintf(filename, sizeof(filename), "%s.txt", filename);
				
                recordFile = fopen (filename, "r" ) ;

                if ( recordFile == NULL )

                {

                    printf("\n Sorry, file does not exists, please check date entered!");

                
                    return -1 ;

                }

               

char c = 'c';

	while(c != 24){
		c = fgetc(recordFile);
		
		if(c == 24)
			continue;
		printf("%c", c);
	}
	
	fclose(recordFile);
return 0;
}

int getCalenderView(){

	// calenderview 
}




