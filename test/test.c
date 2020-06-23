/*
 * @file test.h
 *
 * @brief Collections of declaration function of automated unit tests..
 *
 * @author  - Akhil Dama - akhildama@cmail.carleton.ca - Carleton university
 * @author - Meher Vishnu Kyatham - mehervishnukyatham@cmail.carleton.ca - Carleton University
 * @author - Naveen Billapati - naveenbillapati@cmail.carleton.ca - Carleton University
 * @author - Rajeshwar Reddy Keesara - rajeshwarreddykeesar@cmail.carleton.ca - Carleton University
*/






#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
// #include<conio.h>

#include<string.h>

#include <ctype.h>
#include <unistd.h>
#include<time.h>
#include <errno.h>



#include "../include/app.h"
#include "../include/ui_design.h"

#include "./include/test.h"
 
#ifdef _WIN32	//If in windows
	#define CLEAR system("cls");
#else 
	#define CLEAR system("clear");	//If linux/Mac
#endif

 

/**
 * Macro to print out 'passed'/'failed' based on the boolean value of what was
 * provided to it.
 */
#define ASSERT_TEST(x)                        \
    {                                         \
        if (x)                                \
        {                                     \
            printf("PASSED\n");               \
        }                                     \
        else                                  \
        {                                     \
            printf("%s: FAILED\n", __func__); \
        }                                     \
    }

void automated_general_design_functions(){
    //cls();
    middle1(); pre(4);printf("Testing printf function");
    // printf(" test 2 new lines");
    // br(2);
    // printf("3 tab spaces");
    // pre(3);
    middle1(); pre(4);printf("Testing welcome bar");
    welcome_screen();
    middle1(); pre(4);printf("Testing loading bar");
    loading();
   
    // printf("7 new lines");
    // middle1();
    // printf("5 tab spaces");
    // middtab1();
    middle1(); pre(4);printf("Testing display main menu");
    userMenu();    
    //cls();    

}
void automated_user_signup_signin_testing(){
    middle1(); pre(4);printf("Testing  user Signup");
    user newuser;

    ASSERT_TEST(!signUp(&newuser));
    printf("SignUp function has been tested succesfully");

    user loggedinuser;
    middle1(); pre(4);printf("Testing  user SignIn\n");
    ASSERT_TEST(signIn(&loggedinuser));

     printf("SignIn function has been tested succesfully");


  


}
void automated_testing_records(){

    middle1(); pre(4);printf("Testing Add Records function\n");
    user loginuser;
    loginuser.username = "test_username";
    loginuser.password = "test_password";
    addRecord(&loginuser);

    middle1(); pre(4);printf("Testing the view record functon\n");
    viewRecord(&loginuser);

    middle1(); pre(4);printf(" Testing  the Edit Records\n");
    editRecord(&loginuser);

    middle1(); pre(4);printf("Testing the delete record function\n");
    deleteRecord(&loginuser);
}


void start_automated_testing(void){
   automated_general_design_functions();
    
    //automated_general_design_functions();
   automated_user_signup_signin_testing(); 
   automated_testing_records();

}
