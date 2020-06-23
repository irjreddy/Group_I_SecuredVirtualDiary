/*
 * @file test.h
 *
 * @brief Collections of declaration function of automated unit tests..
 *
 * @author  
 * @author 
 * @author 
 * @author 
*/

#ifndef TEST_H
#define TEST_H

#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include<string.h>
#include<time.h>
#include <errno.h>
#include<time.h>


// #include "../include/app.h"
// #include "../include/ui_design.h"
// #include "../include/record.h"
// #include "../include/user.h"

/*
 * @brief Starts automated testing
 *
 * @details Entry point into the automated test script
 */

void start_automated_testing(void);

/**
 * @brief Automated unit testing of records in the diary
 *
 * @details Automatically tests the linked list functions by doing the
 * following:
 *  - Add a record to the file
 *  - View previous records in the diary
 *  - Edit the record in the diary file
 *  - Delete record in the diary file 
 */
void automated_testing_records(void);


/**
 * @brief Automated unit testing of general design functions
 *
 * @details Automatically tests the all the general design functions
 * 
 */
void automated_general_design_functions(void);
/**
 * @brief Automated unit testing of loggging in user
 *
 * @details Automatically tests the user sign in and sign up and change in password
 * 
 */
void automated_user_signup_signin_testing(void);





#endif






