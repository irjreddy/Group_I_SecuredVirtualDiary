
/**
 * @file record.h
 *
 * @brief This is header file which contains all the operations or functions of the user.
 * 
 * @author Akhil Dama - akhildama@cmail.carleton.ca
 * @author Meher Vishnu Kyatham - mehervishnukyatham@cmail.carleton.ca
 * @author Naveen Billapati- naveenbillapati@cmail.carleton.ca
 * @author Rajeshwar Reddy Keesara- rajeshwarreddykeesar@cmail.carleton.ca
 */

#ifndef RECORD_H
#define RECORD_H

#include <stdio.h>
#include "../include/user.h"

typedef struct 
{
	user *creator;
	char *subject;
	char *data;
	int day;
	int month;
	int year;
}post;

/**
 * @brief This function is used to add the record.
 *
 *@param[in] *loginptr--- user pointer structure
 *    
 * @details With the help of this function the user can be able to add the notes/record if he/she choose this function.
 *
 * @return There is no return value for this function.
 *
 */ 
void addRecord(user *loginptr);
/**
 * @brief This function is used to delete the record.
 *
 *@param[in] *loginptr--- user pointer structure
 *    
 * @details With the help of this function the user can be able to delete the notes/record if he/she choose this function.
 *
 * @return There is a return type integer that informs the operation is complete.
 *
 */ 
int deleteRecord(user *loginptr);
/**
 * @brief This function is used to view the record. .
 * 
 *@param[in] *loginptr--- user pointer structure
 *   
 * @details With the help of this function the user can be able to view the notes/record if he/she choose this function.
 *
 * @return There is no return value for this function.
 *
 */ 
int viewRecord(user *loginptr);
/**
 * @brief This function is used to edit the record.
 * 
 *@param[in] *loginptr--- user pointer structure
 *   
 * @details With the help of this function the user can be able to edit the notes/record if he/she choose this function.
 *
 * @return There is a return type integer.
 *
 */ 
int editRecord(user *loginptr);

#endif
