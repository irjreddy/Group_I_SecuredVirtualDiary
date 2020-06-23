# Secured Virtual Diary

Secured Virtual Diary refers to storing the day to day activity data which works as note taking in a secured realible way with additional features like user accounts, showcasing notes of particular day/month view based on calendar.


# Authors

- Akhil Dama - akhildama@cmail.carleton.ca - Carleton University
- Rajeshwar Reddy Keesara - rajeshwarreddykeesar@cmail.carleton.ca - Carleton University
- Naveen Billapati - naveenbillapati@cmail.carleton.ca - Carleton University
- Meher Vishnu Kyatham - mehervishnukyatham@cmail.carleton.ca - Carleton University

# Installation

Installation steps are mentioned in [INSTALL.md]

# Usage

To run, you must first install it. Then you can follow instructions mentioned in
[User_Manual.md]https://github.com/irjreddy/Group_I_SecuredVirtualDiary/blob/dev/docs/user_manual.md

# File Structure

The correct file structure (after installing GSL library should be follow and run the binary)

```
├── DOCS.md 	-> Usage file
           └──  Developer_Manual.md
		   └──  User_Manual.md
├── INSTALL.md 	-> Installation Guide
├── LICENSE 	-> License file
├── Makefile 	-> Makefile
├── README.md 	-> Readme file
├── bin 	-> Binary directory
├── include 	-> Header files
          ├── app.h
          ├── calendar.h
          ├── record.h
          ├── ui_design.h
          ├── .h
├── install.sh 	-> Installation script
├── obj 	-> Object files
          ├── app.o
		  ├── calendar.o
		  ├── main.o
		  ├── record.o
		  ├── ui_design.o
		  ├── user.o
├── src 	-> Source files for  SecuredVirtualDiary
│       ├──app.c
│       ├── calendar.c
│       ├── main.c
│       ├── record.c
│       ├── ui_design.c
│       ├── user.c
└── test
          ├── include		-> Header file for unittest
                     └──test.h
          
        └── test.c
```

# For Developers

The developer manual is available [here](https://github.com/irjreddy/Group_I_SecuredVirtualDiary/blob/dev/docs/developer_manual.md).

# License

This project is licensed under the MIT License - see the [LICENSE.md](https://github.com/irjreddy/Group_I_SecuredVirtualDiary/blob/dev/LICENSE) file for details

# Acknowledgements

Thank to Dr. Cristina Ruiz Martin for providing guidance on how to develop the software.






