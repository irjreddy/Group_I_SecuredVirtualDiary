/**
 * @file ui_design.h
 *
 * @brief In this file we will be handling all the design functionalities of our system
 * 
 * @author Akhil Dama - akhildama@cmail.carleton.ca
 * @author Meher Vishnu Kyatham - mehervishnukyatham@cmail.carleton.ca
 * @author Naveen Billapati- naveenbillapati@cmail.carleton.ca
 * @author Rajeshwar Reddy Keesara- rajeshwarreddykeesar@cmail.carleton.ca
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<time.h>


/**
 * @brief This function is used to handle the welcome message of our SecuredVirtualDiary application.
 * 
 * @details Once our SecuredVirtualDiary is opened user will be given an good and handy design.
 *  The complete welcome message given to the user will be handled in this function.
 * 
 * @return Return value is void
 *
 */
void welcome_screen();

/**
 * @brief This function is used to handle the loading bar in our application.
 * 
 * @details There are no inputs for this function.
 * The loading bar of our system will be managed with the help of other functions like ccolor etc.
 * 
 * @return Return value is void.
 *
 */
void loading();

/**
 * @brief This function is used to handle the line spacing.
 * 
 * @details There are no input parameters for this function it directly provides 7 line spaces.
 * 
 * @return Return value is void.
 *
 */ 
void middle1(); 

/**
 * @brief This function is used to provide spacing between the characters
 *
 * @param[in] tab--- An input in form of number will be provided.
 *  
 * @details Based on the input provided the number of tab spaces will be provied.
 *
 * 
 * @return There is no return value for the function.
 *
 */
void pre(int nu);

/**
 * @brief This function is used to handle the character spaces.
 * 
 * @details There are no input parameters for this function, it directly provides 6 character spaces.
 * 
 * @return There is no return value for this function.
 *
 */
void middtab1(void);

/**
 * @brief This function is used to set the text colour to red.
 * 
 * @details by calling this function the text will turned to red,  which we can observe in our application.
 * 
 * @return Return value is void.
 *
 */
void red();

/**
 * @brief This function is used to reset the color of the text.
 * 
 * @details by calling this function the text will be turned to white,  which we can observe in our application.
 * 
 * @return Return value is void.
 *
 */
void reset();

/**
  * @brief This function is used to set the text colour to yellow.
 * 
 * @details by calling this function the text will be turned to yellow,  which we can observe in our application.
 * 
 * @return Return value is void.
 *
 */
void yellow();
