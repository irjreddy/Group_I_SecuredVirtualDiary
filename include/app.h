/**
 * @file app.h
 *
 * @brief This is the application file which is used to link everything in the project.
 * 
 * @author Akhil Dama - akhildama@cmail.carleton.ca
 * @author Meher Vishnu Kyatham - mehervishnukyatham@cmail.carleton.ca
 * @author Naveen Billapati- naveenbillapati@cmail.carleton.ca
 * @author Rajeshwar Reddy Keesara- rajeshwarreddykeesar@cmail.carleton.ca
 */

#ifndef APP_H
#define APP_H


#include<stdio.h>
#include "../include/record.h"

/**
 * @brief A Function is used to display the items in the Menu.
 * 
 * @details with help of this function, it prints all the options for the user. So that the user can choose the desired option.
 * 
 * @return The return value for this function is interger denoting the success of the operation.
 *
 */ 

int userMenu();
/**
 * @brief This function is used to excecute the choice made by the user.
 * 
 * @param[in] choice--- This paramater is the integer denoting user choice.
 *
 * @details With the help of the above mentioned parameter this function can execute the right operation.
 * 
 * @return There is no return value for this function.
 *
 */ 

void execUserMenuChoice(int choice,user *login);
/**
 * @brief This function is used to authenticate the user .
 *
 * @param[in] loginuser--- This parameter is used to give the authenticate user to the system.

 * @details Function is used to authenticate th user by the given data.
 * 
 * @return It returns the logged in User structure.
 *
 */ 
user* authUser(user *loginuser);

#endif
