# 2048-Game
A simple non GUI C++ implementation of the popular puzzle game 2048.<br/>
This program is developed with the help of NCURSES library.

# HOW TO RUN

1. Debian/Ubuntu Linux<br/>
  NCURSES library must be installed for running this program \n<br/>
  For installing follow the following steps:<br/>
    a.  Open the Terminal application.<br/>
    b.  Type the following apt-get command (without quotes) to install ncurses header and libs:<br/>
        "sudo apt-get install libncurses5-dev libncursesw5-dev"<br/>
    c.  For compiling the sourse code NCURSES library must be linked use following command (without quotes) on terminbal to             compile:<br/>
        "g++ filename.cpp -lncurses"<br/><br/>
     
2.  CentOS/RHEL/Scientific Linux 6.x/7.x+ and Fedora Linux 21<br/>
    a. Open the Terminal application.<br/>
    b. Type the following yum command (without quotes) to install ncurses header and libs:<br/>
       "sudo yum install ncurses-devel"<br/>
    c.  For compiling the sourse code NCURSES library must be linked use following command (without quotes) on terminbal to             compile:<br/>
        "g++ filename.cpp -lncurses"<br/>
