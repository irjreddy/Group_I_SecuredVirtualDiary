/**
 * @file calendar.c
 *
 * @brief This file contains all the calendar functionality of the project.
 * 
 * @author Akhil Dama - akhildama@cmail.carleton.ca
 * @author Meher Vishnu Kyatham - mehervishnukyatham@cmail.carleton.ca
 * @author Naveen Billapati- naveenbillapati@cmail.carleton.ca
 * @author Rajeshwar Reddy Keesara- rajeshwarreddykeesar@cmail.carleton.ca
 */
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include "../include/user.h"
#include<unistd.h>


int getkey();
void displayCalendar(int,int,int,int[],user *loginptr);
void calendar(int,int,user *loginptr);

//-------------- GOTO function definition ----------------------
void gotoxy(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//------------ Change color -------------------
void SetColor(int ForgC)
{
     WORD wColor;
                          //We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

                           //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                     //Mask out all but the background attribute, and add in the forgournd color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}


char *month[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
char *week[]={"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};



int runCalendar(user *loginptr)
{
     int nmonth,nyr,ch;
    
    time_t mtime;                       
	time(&mtime);
	struct tm *lt = localtime(&mtime); //returns  localtime

	nmonth = (int)lt->tm_mon+1;
	nyr =  (int)lt->tm_year+1900;
       while(1){
        calendar(nyr,nmonth,loginptr);
        while(1)
        {
        gotoxy(20,20);printf("(*) Use LEFT, RIGHT, UP and DOWN arrow.");
        
        gotoxy(20,24);printf("(*) Press ESC to Exit.");
        ch=getkey();
        switch(ch)
        {
        case 80: //-------- DOWN ARROW -----------
               //Increasing month
                if(nmonth==12)
                {
                    //Jump to next year if month is december
                     nmonth=1;
                     nyr++;
                }
                else
                {
                    nmonth++;
                }
                calendar(nyr,nmonth,loginptr);
                break;
        case 77: //-------- RIGHT ARROW ----------
            //Increasing Year
                nyr++;
                calendar(nyr,nmonth,loginptr);
                break;
        case 72: //------- UP ARROW -------------
            // Decreasing Month
                if(nmonth==1)
                {
                    // Jump to previous year if month is january
                    nyr--;
                    nmonth=12;
                }
                else
                    nmonth--;
                calendar(nyr,nmonth,loginptr);
                break;
        case 75: //-------- LEFT ARROW ----------
            //Decreasing year
                if(nyr==1945)
                {
                    //If year is 1945 and we click left arrow than
                  gotoxy(15,2);printf("Year below 1945 not available");
                }
                else
                {
                    nyr--;
                    calendar(nyr,nmonth,loginptr);
                }

                break;
        case 27: //--------- ESC KEY ------------
         
                system("cls");
                gotoxy(50,14);printf("Returning to Main Menu.\n\n\n\n\n");
                goto exit;
                break;
                

                
        
        }
       
        }
         break;
}
       
    exit:
   // getch();
   sleep(1);
    return 0;
}

//============== DISPLAYING THE  CALENDAR ===================
void displayCalendar(int nyr,int nmonth,int tdays,int days[], user *loginptr)
{
    int i,j,pos;
    SetColor(12); //Color red
    gotoxy(56,6);printf("%s %d",month[nmonth-1],nyr); //Heading year and month dispalying
    for(i=0,pos=30;i<7;i++,pos+=10)
    {
         if(i==6)
            SetColor(9); //Sunday color blue
         else
            SetColor(10);  //Others day color green
        gotoxy(pos,8);printf("%s",week[i]);
    }

    SetColor(15); //setting the color white

   tdays++; //incrementing the tdays by 1
    if(tdays==0 || tdays==7)
        pos=91; //if tdays is 0 or 7, position is sunday
    if(tdays==1)
        pos=31; //if tdays is 1, position is monday
    if(tdays==2)
        pos=41;  //if tdays is 2, position is tuesday
    if(tdays==3)
        pos=51;  //if tdays is 3, position is wednesday
    if(tdays==4)
        pos=61;  //if tdays is 4, position is thursday
    if(tdays==5)
        pos=71;  //if tdays is 5, position is friday
    if(tdays==6)
        pos=81;  //if tdays is 6, position is saturday
	j=10;
    for(i=0,i<days[nmonth-1];pos+=10)
    {
        if(pos==91)
            SetColor(8); //Changing color to dark grey for sunday
        else
            SetColor(7); //Changing color to white for all days
    char date_str[100];
    

    char name[50] = "./";
	strcat(name,loginptr->username);
	strcat(name,"/records/");

	snprintf(date_str, sizeof(date_str), "%d-%d-%d.txt", i+1,nmonth,nyr);
    strcat(name,date_str);
        FILE *fp = fopen(name,"r");
        if(fp == NULL){
           gotoxy(pos,j);printf("Missing"); 
        }
        else{
            gotoxy(pos,j);printf("%d-%d-%d",i+1,nmonth,nyr);
        }
        
        if(pos==91)
        {
            pos=21; //Moving position to monday
            j++;  //Increasing j by 10 if position is sunday
        }
        fclose(fp);
	    i++;
    }

    SetColor(5); //Changing color to purple

    //Drawing horizontal line
    for(i=22;i<102;i++)
    {
        gotoxy(i,4);printf("%c",196);
        gotoxy(i,17);printf("%c",196);
    }

    //Drawing all the corner of the rectangle
    gotoxy(21,4);printf("%c",218);
    gotoxy(102,4);printf("%c",191);
    gotoxy(21,17);printf("%c",192);
    gotoxy(102,17);printf("%c",217);

    //Drawing vertical line
    for(i=5;i<17;i++)
    {
        gotoxy(21,i);printf("%c",179);
        gotoxy(102,i);printf("%c",179);
    }

    SetColor(11); //Changing color

    //Navigation Symbol
    gotoxy(24,11);printf("%c",174);
    gotoxy(98,11);printf("%c",175);

}

//==============  ARROW KEY ===============
int getkey()
{
    int ch;
    ch=getch();
     if(ch==0)
    {
        printf("zero");
        ch=getch();

        return ch;
    }
    return ch;
}


void calendar(int nyr,int nmonth, user *loginptr)
{
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int tdays=0,k,myear;
    system("cls");
    myear=nyr-1; //Decrease year by 1
            if(myear>=1945)
            {
                for(k=1945;k<=myear;k++)
                {
                    if(k%4==0) //If the year is a leap year than  no of days is 366
                        tdays=tdays+366;  //counting all the days till nyr - 1
                    else //If the year is a leap year than total no of days is 365
                        tdays=tdays+365;  //counting all the days till nyr - 1
                }
            }

            if(nyr%4==0)
                days[1]=29; //changing value in days array from 28 to 29 since leap year
            else
                days[1]=28; //changing value in days array from 29 to 28 since not a leap year

            for(k=0;k<(nmonth-1);k++)
            {

                tdays=tdays+days[k]; //Adding nmonth-1 days to tdays
            }

            tdays=tdays%7; //Finding the remainder of tdays so it can calculate the position to display
            displayCalendar(nyr,nmonth,tdays,days,loginptr); 
}
