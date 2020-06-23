/**
 * @file calendar.h
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

/**
 * @brief This Function is used to display calendar with given inputs  with the current date.

 * @param[in] nyr--- present year is given as input
 *  
 * @param[in] nmonth--- present month is given as input
 *  
 * @param[in] tdays--- present number of days in a year is given as input
 *  
 * @param[in] days[]--- week days is given as input.
 *  
 *@param[in] *loginptr--- user pointer structure.
 *  
 * @details with the help  of this function, the calendar is started by taking current date as the predefined date and will display.  
 * 
 * @return There is no return type.
 *
 */ 
void displayCalendar(int,int,int,int[],user *loginptr);

/**
 * @brief This Function is used to initiate the calendar feature of the application with the current date.

 * @param[in] nyr--- current year as input.
 *  
 * @param[in] nmonth--- current month as input
 * 
 * @param[in] *loginptr--- user pointer structe as input
 *   
 * @details with the help  of this function, the calendar is started by taking current date as the predefined date.  
 * 
 * @return There is no return type.
 *
 */ 
void calendar(int,int, user *loginptr);

/**
 * @brief This Function is used to initiate the calendar feature of the application with the current date.
 * 
 *@param[in] *loginptr--- user pointer structure
 *  
 * @details with the help  of this function, the calendar is started by taking current date as the predefined date.  
 * 
 * @return There is a return type interger to denote the success of the function.
 *
 */ 
int runCalendar(user *loginptr);

