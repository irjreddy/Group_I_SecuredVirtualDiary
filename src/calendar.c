#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>


int key();
void displayCalendar(int,int,int,int[]);
void calendar(int,int);

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



int runCalendar()
{
     int nmonth,nyr,ch;
    
    time_t mtime;                       
	time(&mtime);
	struct tm *lt = localtime(&mtime); //returns  localtime

	nmonth = (int)lt->tm_mon+1;
	nyr =  (int)lt->tm_year+1900;
       
        calendar(nyr,nmonth);
        while(1)
        {
        gotoxy(20,20);printf("(*) Use LEFT, RIGHT, UP and DOWN arrow.");
        gotoxy(20,22);printf("(*) Press P to go to particular year and month.");
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
                calendar(nyr,nmonth);
                break;
        case 77: //-------- RIGHT ARROW ----------
            //Increasing Year
                nyr++;
                calendar(nyr,nmonth);
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
                calendar(nyr,nmonth);
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
                    calendar(nyr,nmonth);
                }

                break;
        case 27: //--------- ESC KEY ------------
         
                system("cls");
                gotoxy(50,14);printf("Returning to Main Menu.\n\n\n\n\n");
                break;
                
        
        }
        break;
        }
       

   // getch();
   sleep(1);
    return 0;
}

