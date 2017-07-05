# 2048-Game
A simple non GUI C++ implementation of the popular puzzle game 2048.
This program is developed with the help of NCURSES library.

# HOW TO RUN

1. Debian/Ubuntu Linux
  NCURSES library must be installed for running this program 
  For installing follow the following steps:
    a.  Open the Terminal application.
    b.  Type the following apt-get command (without quotes) to install ncurses header and libs:
        "sudo apt-get install libncurses5-dev libncursesw5-dev"
    c.  For compiling the sourse code NCURSES library must be linked use following command (without quotes) on terminbal to             compile:
        "g++ filename.cpp -lncurses"
        
2.  CentOS/RHEL/Scientific Linux 6.x/7.x+ and Fedora Linux 21
    a. Open the Terminal application.
    b. Type the following yum command (without quotes) to install ncurses header and libs:
       "sudo yum install ncurses-devel"
    c.  For compiling the sourse code NCURSES library must be linked use following command (without quotes) on terminbal to             compile:
        "g++ filename.cpp -lncurses"
