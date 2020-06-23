/**
 * @file record.c
 *
 * @brief This is header file which contains all the operations or functions of the user.
 * 
 * @author Akhil Dama - akhildama@cmail.carleton.ca
 * @author Meher Vishnu Kyatham - mehervishnukyatham@cmail.carleton.ca
 * @author Naveen Billapati- naveenbillapati@cmail.carleton.ca
 * @author Rajeshwar Reddy Keesara- rajeshwarreddykeesar@cmail.carleton.ca
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <sys/stat.h>
#include <sys/types.h>



#include "../include/record.h"
#include "../include/ui_design.h"


int mkdir(const char *pathname, mode_t mode);

void clean_stdin(){ //clean the buffer
    int c;
 
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
void addRecord(user *loginptr){ //create a new record
	
	char data[150] = "";
	char finalpost[500] = "";
	char post_subject[50]="";
	post post_creator; 
	
    
    
   
	time_t mtime;                       
	time(&mtime);
	struct tm *lt = localtime(&mtime); //returns  localtime

	post_creator.day = (int)lt->tm_mday;
	post_creator.month = (int)lt->tm_mon+1;
	post_creator.year =  (int)lt->tm_year+1900;

	
	printf("This is your Editor, you can type anything \n");
	printf("Start writing and press CTRL + X on a new line when finished\n");
	printf("====================================================================\n\n\n");

	

    printf("Enter subject for the post\n");
	getchar();
	
    fgets(post_subject, sizeof(post_subject),stdin);
	post_creator.subject = post_subject;
    printf("Enter Record Now:\n");
	
	while(*data != 24){ //Enable user to write until he types CTRL + X which is the 24
		fgets(data, sizeof(data), stdin);
		strcat(finalpost, data);
	}
	mkdir("records",07777);
	mkdir(loginptr->username,07777);
	char pa[50];
	strcpy(pa,loginptr->username);
	strcat(pa,"/records");
	mkdir(pa,07777);

	char date_str[100];
	char fullp[100];
	strcpy(fullp,loginptr->username);
	snprintf(date_str, sizeof(date_str), "/records/%d-%d-%d.txt", post_creator.day, post_creator.month, post_creator.year);
    printf("Todays date is %s ",date_str);
	strcat(fullp,date_str);
	printf("file to be added %s",date_str);

    FILE *postfile = fopen(fullp,"w");
    fprintf(postfile, "Date : %d/%d/%d Heure : %d:%d\n", post_creator.day, post_creator.month, post_creator.year, (int)lt->tm_hour, (int)lt->tm_min);

	post_creator.data = finalpost;
	
	finalpost[strlen(finalpost)-1] = '\0'; 
	
	printf("\n\n\n");
	printf("Your post : \n%s\n", finalpost);
	fprintf(postfile, "Subject :%s\n", post_creator.subject);
	fprintf(postfile, "Post :\n%s\n-- Complete --\n\n\n", post_creator.data);
	
	fclose(postfile);
}

int deleteRecord(user *loginptr){
	char filename[50] ="";
	char foldername[50]="./records/";
	char name[50] = "./";
	strcat(name,loginptr->username);
	strcat(name,"/records/");
	FILE *fp;
	 printf("\n Enter date of record to be delted:[dd-mm-yyyy]:");
				getchar();
				
                fgets(filename,sizeof(filename),stdin);
				 filename[strlen(filename)-1] = '\0';
				
				snprintf(filename, sizeof(filename), "%s.txt", filename);
				
				strcat(name,filename);

                fp = fopen (name, "r" ) ;

                if ( fp == NULL )

                {

                    printf("\n Sorry, file does not exists, please check date entered!");

                
                    return -1 ;

                }

                fclose(fp);

                remove(foldername);

                printf("\n Deleted...");
				return 0;

}


int viewRecord(user *loginptr){
char filename[100] ="";

char name[50] = "./";
	strcat(name,loginptr->username);
	strcat(name,"/records/");

	FILE *recordFile;
	red();
	 printf("\nEnter date of record to be Viewed:[dd-mm-yyyy]:");
	 
	 reset();
				getchar();
				
                fgets(filename,sizeof(filename),stdin);
				 filename[strlen(filename)-1] = '\0';
				 
				printf("\n\n");
				snprintf(filename, sizeof(filename), "%s.txt",filename);
				
				strcat(name,filename);
				//printf("file tobe viewed name is %s",foldername);
                recordFile = fopen (name, "r" ) ;
				
                if ( recordFile == NULL )

                {

					red();
                    printf("\nSorry, file does not exists, please check date entered!\n");
					reset();
                
                    return -1 ;

                }

               

char c = 'c';

	while(c != 24){
		c = fgetc(recordFile);
		
		if(c == 24)
			continue;
		printf("%c", c);
	}

	printf("\n\n");
	
	fclose(recordFile);
return 0;
}

int editRecord(user *loginptr){
	char data[150] = "";
	char finalpost[500] = "";
	char post_subject[50]="";
	char filename[50] ="";
	
	char firstline[200]="";

	char name[50] = "./";
	strcat(name,loginptr->username);
	strcat(name,"/records/");

	FILE *fp;
	red();
	 printf("\nEnter date of record to be edited:[dd-mm-yyyy]:");
	 getchar();
				
				reset();
                fgets(filename,sizeof(filename),stdin);
				 filename[strlen(filename)-1] = '\0';
				
				snprintf(filename, sizeof(filename), "%s.txt", filename);
			strcat(name,filename);
                fp = fopen (name, "r" ) ;

                if ( fp == NULL )

                {
					red();
                    printf("\nTHE FILE DOES NOT EXISTS");
					reset();
                
                    return -1 ;

                }
				else{
					red();
					printf("\n \n Your old Record is: \n \n \n");
					reset();
					char c = 'c';
					fgets(firstline,200,fp);
					while(c != 24){
						c = fgetc(fp);
						
						if(c == 24)
							continue;
						printf("%c", c);
					
				}
				printf("\n \n \n");
					getchar();

	red();
	printf("\n Enter your new record now \n \n");
	printf("This is your Editor, you can type anything");
	printf("Start writing and press CTRL + X on a new line when finished\n");
	printf("====================================================================\n\n\n");

	
	
    printf("Enter subject for the record \n"); reset();
    fgets(post_subject, sizeof(post_subject),stdin);
	red();
    printf("Enter Record Now: \n");reset();
    
	while(*data != 24){ //Enable user to write until he types CTRL + X
		fgets(data, sizeof(data), stdin);
		strcat(finalpost, data);
	}


				FILE *postfile = freopen(name,"w",fp);
				fprintf(postfile, "%s",firstline); // writing previous date


					
					finalpost[strlen(finalpost)-1] = '\0'; /*So that no extra char in added in the post*/
					
					printf("\n\n\n");
					printf("Your post : \n%s\n", finalpost);
					fprintf(postfile, "Subject :%s\n",post_subject);
					fprintf(postfile, "Post :\n%s\n-- Complete --\n\n\n", finalpost);
	

 					fclose(postfile);
					 return 0;
				}

             return 0;  

}








