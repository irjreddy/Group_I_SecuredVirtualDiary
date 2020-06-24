/**
 * @file user.h
 *
 * @brief This is the file where all the user related auth, sign, sign up will be handled here
 * 
 * @author Akhil Dama - akhildama@cmail.carleton.ca
 * @author Meher Vishnu Kyatham - mehervishnukyatham@cmail.carleton.ca
 * @author Naveen Billapati- naveenbillapati@cmail.carleton.ca
 * @author Rajeshwar Reddy Keesara- rajeshwarreddykeesar@cmail.carleton.ca
 */
#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
	char *username;
	char *email;
	
	char *password;
	
	int isLoggedIn;
	int line;
}user;

/**
 * @brief A Function which is used to login the user to the system
 * 
 * @param[in] loginuser--- user structure as an input
 *  
 * @details With the help of this input this function, the user can login to the system using his username and password
 * 
 * @return It returns the successs or failure status as an integer
 *
 */
int signIn(user *loginuser);


/**
 * @brief A Function which is used to register the user to the system for the first time
 * 
 * @param[in] newuser--- user structure as an input
 *  
 * @details With the help of this function, the user can signup an account with the system
 * 
 * @return It returns the success or failure status
 *
 */
int signUp(user *newuser);

/**
 * @brief A Function is used to edit or reset the password to the system
 * 
 * @param[in] *loginptr--- user structure as an input
 *  
 * @details With the help of this function, the user can edit or reset the password to the system
 * 
 * @return It returns the success or failure of the operation
 *
 */
int editPassword(user *loginptr);

/**
 * @brief A Function which is used to check if the user is already register to the system or not
 * 
 * @param[in] *username--- username to the system as an input
 *  
 * @param[in] *password--- password to the system as an input
 *  
 * @param[in] *loginuser--- user structure as an input
 *    
 * @details With the help of this function, we can check if we have the user in the system
 * 
 * @return It returns an integer denoting, wheather the user is registered or not
 *
 */
int isuser( const char *username,const char *password,user *loginuser);

/**
 * @brief A Function is used to check if we the username is available while registration.
 * 
 * @param[in] *username---username as an input
 *  
 * @details With the help of this function, by taking given username it checkif it is available or taken
 * 
 * @return It returns an integer denoting username taken(0) or available (1)
 *
 */
int availableuser(const char *username);

/**
 * @brief A Function is used to create an user to the system for the first time
 * 
 * @param[in] *newuser--- user structure will taken as an input
 *  
 * @details With the help of this function, it takes an empty user structure and create new user with the user given password and username
 * 
 * @return It returns type is void
 *
 */
void createuser(user *newuser);

/**
 * @brief A Function which is used to check the user entered password with the system register password while signin
 * 
 * @param[in] *check_pass--- user entered password will be given as an input
 *  
 * @details With the help of this function, it takes the usergiven password and compares it with password stored in the system
 * 
 * @return It returns 1 if passwords match, 0 if not
 *
 */
int check_password(char*);

#endif
