# Introduction

Secured Virtual diary refers to a personal application where user can write about their day to day experiences, social commentary and any content that is required which is secure and accessible only by the user.
In this Project we are developing a notable virtual system which is typically to be a platform with user and admin menu’. This application mainly allows users to enter his/her personal notes using a login page by entering their username and password.
One of the important features in this application is not only the effective usage of notes but also expecting the secured way of accessing by protecting them using passwords.

# Requirement

For our project, the clients can be layman person, student, professionals (Doctors, Engineers, Team Leads, Teachers etc..) and wherever prioritizing of tasks is absolutely beneficial. The following are the requirements needed for the user are mentioned below:
1) The Application Should be able to create individual user account.
2) The system should display user menu options like add note, view note, edit note and delete note.
3) While creating Notes, application should include subject/tag.
4) User should be able to have an overview of his/her recorded notes as a monthly view. 
5)The application should support admin login page.
6) Admin should be able to view number of users along with their user id.
7)User should be able to sign out from his account. 
8) User should be able to exit from the application.
9) User should be able to change the password if necessary.



# Program Flow

The main.c calls function in app.c which initiates the program flow, app.c acts as the center of the application linking everything together.

![Diagram](https://github.com/irjreddy/Group_I_SecuredVirtualDiary/blob/dev/assets/program_fow.jpg)



App.c file calls
	Functions in user.c for authentication, edit password, sign out feature, admin login
	Functions in calendar.c for showcasing the calendar view of the records entered and missing records
	Functions in record.c for adding, viewing, editing, deleting records of user
	

