# Introduction

Secured Virtual Diary is an note taking application where customers can store  their day to day activities in a secured way without worrying about remembering the activities and also with the enhanced features of showcasing the notes of the particular day/month based on the calendar view.

# Installation

Please refer to [INSTALL.md](https://github.com/irjreddy/Group_I_SecuredVirtualDiary/blob/dev/install.md) file for installation instructions.

# Usage

The welcome screen says Secured Virtual Diary where user is redirected to the main menu page have two options. Among those two options, you can choose any option which needed from the main menu as follows:

1. Sign in
2. Sign up
3. Admin Login

By Selecting the option 2 a user can create own account by entering their:
username: This variable allows user to enter the username required for signup.
password: Here User should give the secured password for the user account which gives the access to the account storing the respective user's records.
email: user is also supposed to give the email id for the sign up.

By choosing the option 1 the user is supposed to enter the credentials that are created in the process of signup.

After the successful user login, the page redirects to the user menu which displays the options as follows.
1. Add Todays Records
2. View Previews Records
3. Edit records
4. Delete Records
5. Monthly Calendar view
6. Edit Password
7. Sign Out
8. Exit

Selecting option 1 takes user to add the notes by using this function, where the fields of date, place, time, duration of task are included.

Selecting option 2 takes user to view the notes that which is added allready and stored in the user account.

Selecting option 3 helps user to update or make changes to the existing file. 

Selecting option 4 helps user to delete the information or the notes that are already existing.
Selecting option 5 takes user to the monthly overview of the notes that entered in a month or period of the time. 
Selecting option 6 helps user to edit the password of the user account which is used to give the access to the user.
Selecting option 7 helps user to sign out, where he/she can be able to either sign in back with different account or choose other option.
Selecting option 8 helps user to exit from the application at any time.
# Testing

Unit testing is done for each function defined in the software. The test cases can be run using the command below:

./bin/virtual_diary -t
