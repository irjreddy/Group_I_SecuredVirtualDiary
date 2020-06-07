
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#ifdef _WIN32	//If in windows
	#define CLEAR system("cls");
#else 
	#define CLEAR system("clear");	//If linux/Mac
#endif

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"

#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


void echo(char print[]){

	printf("%s",print);
}

void br(int line){
	for(int i=0; i<line;i++){
		printf("\n");
	}
}

void pre(int tab){

	for(int i=0; i<tab;i++){
		printf("\t");
	}

}
void span(int space){

	for(int i=0; i<space;i++){
		printf(" ");
	}

}
void ccolor(int clr){

	//HANDLE  hConsole;
	//hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hConsole, clr);

}

void welcome_screen(){
	

	char welcome[50]=" WELCOME ";
	char welcome2[50]=" TO  ";
	char welcome3[50]=" Secured Virtual  ";
	char welcome4[50]=" Diary  ";
	printf("\n\n\n\n\n\t\t\t");
	for(int wlc=0; wlc<strlen(welcome);wlc++){
           
		printf("%s%c",KGRN,welcome[wlc]);
		//sleep(0.2);
	}
	ccolor(26);
	printf("\n\n\t\t\t\t");
	for(int wlc2=0; wlc2<strlen(welcome2) ;wlc2++){
           

		printf(" %s%c",KRED,welcome2[wlc2]);
		//sleep(0.2);
	}
	ccolor(26);
	printf("\n\n\n\t\t\t ");
	for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++){
		

		printf(" %s%c",KBLU,welcome3[wlc3]);
		

		//sleep(0.2);
	}

	
	printf("\n\n\n\t\t\t\t ");
	for(int wlc4=0; wlc4<strlen(welcome4) ;wlc4++){
		
		printf(" %s%c",KYEL,welcome4[wlc4]);
		
		//sleep(0.2);
	}
	printf("\n\n\t\t\t ");
}
void loading(){

	for (int i=15;i<=100;i+=5){

		CLEAR
		ccolor(26);

		printf("\n\n\n\n\n\n\n\t\t\t\t");
		printf("%d %% Loading...\n\n\t\t",i);

		printf(" ");

		for (int j=0; j<i;j+=2){

			ccolor(160+j);
			printf(" ");
			ccolor(26);

		}
		//sleep(1);
		if(i==90 || i==50 || i==96 || i==83){
			sleep(1);
		}

	}

}

void middle1(void){

	printf("\n\n\n\n\n\n\n");
}
void middtab1(void){
	printf("\t\t\t\t\t");
}
