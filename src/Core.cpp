#include <iostream>
#include <ctime>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ncurses.h>

using namespace std;

int game_grid[4][4];
int duplicate_grid[4][4];

int up_arrow = 0;
int left_arrow = 0;
int down_arrow = 0;
int right_arrow = 0;
int no_of_updates = -1;

int counter = 0;
int score =0;

void update_grid();		/* For updating the grid after input from user */
void display_grid();	/* For displaying the game screen and taking input through arrow keys */
int is_grid_empty(int game_grid[4][4]);   /*For checking if any legal move is possible */
void insert_into_grid();	/* Randomly inserting numbers into grid */
void display_exit();	/* Displaying the exit screen */

/*
The function display_grid() is used to display the game screen and taking input from the user via arrow keys.
For taking input via arrow keys NCURSES library which is an exxtension of the curses library is used.
For more about NCURSES visit:
https://en.wikipedia.org/wiki/Ncurses
http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/
*/

int main()
{
	srand(time(NULL));
        
    int n1 = (rand() % 4 );
    int n2 = (rand() % 4 );

    if(n1%2 == 0)
    	game_grid[n1][n2] = 4;
    else
    	game_grid[n1][n2] = 2;
	
	while(1)	
	{
		if(is_grid_empty(game_grid) != 1)
		{
			display_exit();
			break;
		}
		insert_into_grid();
		display_grid();
		update_grid();
	}
}

int is_grid_empty(int game_grid[4][4])	
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(game_grid[i][j] == 0)
				return 1;
		}
	}
	return 0;
} 
		

void update_grid()   
{
    no_of_updates = 1;

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            duplicate_grid[i][j]=0;
    
 
    
        if(down_arrow == 1)
        {
            for(int j=0;j<4;j++)
            {
            	int k = 3;
                for(int i=3;i>=0;i--)
                {
                    if(game_grid[i][j] != 0)
                    {
                        duplicate_grid[k][j] = game_grid[i][j];
                        if(k != i)
                        	no_of_updates++;
                        k--;
                    }
                }
            }

            for(int j=0;j<4;j++)
            {
                if(duplicate_grid[2][j] == duplicate_grid[3][j])
                {
                    if(duplicate_grid[0][j] == duplicate_grid[1][j])
                    {
                        duplicate_grid[3][j] += duplicate_grid[2][j];
                        score += duplicate_grid[3][j];
                        duplicate_grid[2][j] = duplicate_grid[0][j] + duplicate_grid[1][j];
                        score += duplicate_grid[2][j];
                        duplicate_grid[0][j] = 0;
                        duplicate_grid[1][j] = 0;
                        if(duplicate_grid[2][j] != 0 ||duplicate_grid[0][j] !=0)
                        	no_of_updates++;
                    }
                    else
                    if(duplicate_grid[0][j] != duplicate_grid[1][j])        
                    {
                        duplicate_grid[3][j] += duplicate_grid[2][j];
                        score += duplicate_grid[3][j];
                        duplicate_grid[2][j] = duplicate_grid[1][j];
                        duplicate_grid[1][j] = duplicate_grid[0][j];
                        duplicate_grid[0][j] = 0;
                        if(duplicate_grid[3][j] != 0)
                        	no_of_updates++;
                    }
                }
                else
                {    
                    if(duplicate_grid[1][j] == duplicate_grid[2][j])
                    {
                        duplicate_grid[2][j] += duplicate_grid[1][j];
                        score += duplicate_grid[2][j];
                        duplicate_grid[1][j] = duplicate_grid[0][j];
                        duplicate_grid[0][j] = 0;
                        if(duplicate_grid[2][j] != 0)
                        	no_of_updates++;
                    }
                    else
                        if(duplicate_grid[0][j] == duplicate_grid[1][j])
                        {
                            duplicate_grid[1][j] += duplicate_grid[0][j];
                            score += duplicate_grid[1][j];
                            duplicate_grid[0][j] = 0;
                            if(duplicate_grid[1][j] != 0)
                        	no_of_updates++;
                        }
                }
            }
        }
        else
        
            if(up_arrow == 1)
            {
                
                for(int j=0;j<4;j++)
                {
                	int k=0;
                    for(int i=0;i<4;i++)
                    {
                        if(game_grid[i][j] != 0)
                        {
                        	if(k != i)
                        	no_of_updates++;
                            duplicate_grid[k][j] = game_grid[i][j];
                            k++;
                        }
                    }
                }
                for(int j=0;j<4;j++)
                {
                    if(duplicate_grid[0][j] == duplicate_grid[1][j])
                    {
                        if(duplicate_grid[2][j] == duplicate_grid[3][j])
                        {
                            duplicate_grid[0][j] += duplicate_grid[1][j];
                            score += duplicate_grid[0][j];
                            duplicate_grid[1][j] = duplicate_grid[2][j] + duplicate_grid[3][j];
                            score += duplicate_grid[1][j];
                            duplicate_grid[2][j] = 0;
                            duplicate_grid[3][j] = 0;
                            if(duplicate_grid[0][j] != 0 || duplicate_grid[2][j] != 0)
                        	no_of_updates++;
                        }
                        else
                        if(duplicate_grid[2][j] != duplicate_grid[3][j])
                        {
                            duplicate_grid[0][j] += duplicate_grid[1][j];
                            score += duplicate_grid[0][j];
                            duplicate_grid[1][j] = duplicate_grid[2][j];
                            duplicate_grid[2][j] = duplicate_grid[3][j];
                            duplicate_grid[3][j] = 0;
                            if(duplicate_grid[0][j] != 0)
                        	no_of_updates++;
                        }
                    }
                    else
                        if(duplicate_grid[1][j] == duplicate_grid[2][j])
                        {
                            duplicate_grid[1][j] += duplicate_grid[2][j];
                            score += duplicate_grid[1][j];
                            duplicate_grid[2][j] = duplicate_grid[3][j];
                            duplicate_grid[3][j] = 0;
                            if(duplicate_grid[1][j] != 0)
                        	no_of_updates++;
                        }
                        else
                            if(duplicate_grid[2][j] == duplicate_grid[3][j])
                            {   
                                duplicate_grid[2][j] += duplicate_grid[3][j];
                                score += duplicate_grid[2][j];
                                duplicate_grid[3][j] = 0;
                                if(duplicate_grid[3][j] != 0)
                        		no_of_updates++;	
                            }
                }
            }
        
            else
            
                if(left_arrow == 1)
                {
                    
                    for(int i=0;i<4;i++)
                    {
                    	int k=0;
                        for(int j=0;j<4;j++)
                        {
                            if(game_grid[i][j] != 0)
                            {
                            	if(k != j)
                        		no_of_updates++;
                                duplicate_grid[i][k] = game_grid[i][j];
                                k++;
                            }
                        }
                    }
                    for(int i=0;i<4;i++)
                    {
                        if(duplicate_grid[i][0] == duplicate_grid[i][1])
                        {
                            if(duplicate_grid[i][2] == duplicate_grid[i][3])
                            {
                                duplicate_grid[i][0] += duplicate_grid[i][1];
                                score += duplicate_grid[i][0];
                                duplicate_grid[i][1] = duplicate_grid[i][2] + duplicate_grid[i][3];
                                score += duplicate_grid[i][1];
                                duplicate_grid[i][2] = 0;
                                duplicate_grid[i][3] = 0;
                                if(duplicate_grid[i][0] != 0 || duplicate_grid[i][2] != 0)
                        		no_of_updates++;
                            }
                            else
                                if(duplicate_grid[i][2] != duplicate_grid[i][3])
                                {
                                    duplicate_grid[i][0] += duplicate_grid[i][1];
                                    score += duplicate_grid[i][0];
                                    duplicate_grid[i][1] = duplicate_grid[i][2];
                                    duplicate_grid[i][2] = duplicate_grid[i][3];
                                    duplicate_grid[i][3] = 0;
                                    if(duplicate_grid[i][0] != 0)
                        			no_of_updates++;
                                }
                        }
                        else
                            if(duplicate_grid[i][1] == duplicate_grid[i][2])
                            {
                                duplicate_grid[i][1] += duplicate_grid[i][2];
                                score += duplicate_grid[i][1];
                                duplicate_grid[i][2] = duplicate_grid[i][3];
                                duplicate_grid[i][3] = 0;
                                if(duplicate_grid[i][1] != 0)
                        		no_of_updates++;
                            }
                            else
                                if(duplicate_grid[i][2] == duplicate_grid[i][3])
                                {
                                    duplicate_grid[i][2] += duplicate_grid[i][3];
                                    score += duplicate_grid[i][2];
                                    duplicate_grid[i][3] = 0;
                                    if(duplicate_grid[i][2] != 0)
                        			no_of_updates++;
                                }
                    }
                }
            
                else
                
                    if(right_arrow == 1)
                    {
                        
                        for(int i=0;i<4;i++)
                        {
                        	int k = 3;
                            for(int j=3;j>=0;j--)
                            {
                                if(game_grid[i][j] != 0)
                                {
                                	if(k != j)
                        			no_of_updates++;
                                    duplicate_grid[i][k] = game_grid[i][j];
                                    k--;
                                }
                            }
                        }
                        for(int i=0;i<4;i++)
                        {
                            if(duplicate_grid[i][2] == duplicate_grid[i][3])
                            {
                                if(duplicate_grid[i][0] == duplicate_grid[i][1])
                                {
                                    duplicate_grid[i][3] += duplicate_grid[i][2];
                                    score += duplicate_grid[i][3];
                                    duplicate_grid[i][2] = duplicate_grid[i][0] + duplicate_grid[i][1];
                                    score += duplicate_grid[i][1];
                                    duplicate_grid[i][1] = 0;
                                    duplicate_grid[i][0] = 0;
                                    if(duplicate_grid[i][2] != 0 || duplicate_grid[i][0] != 0)
                        			no_of_updates++;
                                }
                                else
                                    if(duplicate_grid[i][0] != duplicate_grid[i][1])
                                    {
                                        duplicate_grid[i][3] += duplicate_grid[i][2];
                                        score += duplicate_grid[i][3];
                                        duplicate_grid[i][2] = duplicate_grid[i][1];
                                        duplicate_grid[i][1] = duplicate_grid[i][0];
                                        duplicate_grid[i][0] = 0;
                                        if(duplicate_grid[i][3] != 0)
                        				no_of_updates++;
                                    }
                            }
                            else
                                if(duplicate_grid[i][1] == duplicate_grid[i][2])
                                {
                                    duplicate_grid[i][2] += duplicate_grid[i][1];
                                    score += duplicate_grid[i][2];
                                    duplicate_grid[i][1] = duplicate_grid[i][0];
                                    duplicate_grid[i][0] = 0;
                                    if(duplicate_grid[i][2] != 0)
                        			no_of_updates++;
                                }
                                else
                                    if(duplicate_grid[i][0] == duplicate_grid[i][1])
                                    {
                                        duplicate_grid[i][1] += duplicate_grid[i][0];
                                        score += duplicate_grid[i][1];
                                        duplicate_grid[i][0] = 0;
                                        if(duplicate_grid[i][1] != 0)
                        				no_of_updates++;
                                    }
                        }   
                    }
        
        for(int i=0;i<4;i++)
        	for(int j=0;j<4;j++)
        		game_grid[i][j] = duplicate_grid[i][j];            
    
}

void insert_into_grid()
{
	if(no_of_updates == -1)
	{
		srand(time(NULL));
        
    	int n1 = (rand() % 4 );
    	int n2 = (rand() % 4 );

    	while(1)
    	{
	    	if(game_grid[n1][n2] == 0)
    		{
    			if(n1%2 == 0)
    				game_grid[n1][n2] = 2;
    			else
	    			game_grid[n1][n2] = 4;
    			break;
    		}
    		else
    		{
	    		n1 = (rand() % 4 );
    			n2 = (rand() % 4 );
    		}
    	}
	}
	else
		if(no_of_updates > 1)
		{
			srand(time(NULL));
        
    		int n1 = (rand() % 4 );
    		int n2 = (rand() % 4 );

    		while(1)
    		{
		    	if(game_grid[n1][n2] == 0)
    			{
	    		if(n1%2 == 0)
	    				game_grid[n1][n2] = 2;
    				else
		    			game_grid[n1][n2] = 4;
    				break;
    			}
    			else
    			{
		    		n1 = (rand() % 4 );
    				n2 = (rand() % 4 );
    			}
    		}
		}
}

void display_grid()
{
	int ch;
	int i,j;
	up_arrow=0;
	down_arrow=0;
	right_arrow=0;
	left_arrow=0;

	initscr();	/* Initialising NCURSES */
	cbreak();	/* Line buffering disabled. pass on everything */
	noecho();	/* Don't echo() while we do getch */
	clear();	/* Clear the screen */
	keypad(stdscr, TRUE);

	attron(A_BOLD);
	printw("\t\t\t\t   2048");
	attroff(A_BOLD);
	printw("\n");
	printw("\t\t\t\t\t\t\t\tScore: %d",score);
	printw("\n\n");


	for(i=0;i<4;i++)
    {
        printw("\t\t  |");
        for(j=0;j<4;j++)
        {
            if(game_grid[i][j])
                printw("  %4d  |",game_grid[i][j]);
            else
                printw("        |");
        }
        printw("\n\n\n");
    }
    printw("Press the arrow keys to move in respective direction\n\n");
    printw("Press Q to QUIT\n\n");

    ch = getch();

    if(ch == KEY_UP)
    	up_arrow = 1;
    else
    	if(ch == KEY_DOWN)
    		down_arrow = 1;
    	else
    		if(ch == KEY_LEFT)
    			left_arrow = 1;
    		else
    			if(ch == KEY_RIGHT)
    				right_arrow = 1;
    			else
    				if(ch == 'q')
    				{
    					printw("\t\t\t   Your score is %d\n\n",score);
    					refresh();
    					std::exit(0);
    				}	

    refresh();
//    getch();
    endwin();
}

void display_exit()
{
	int  ch;
    
    initscr();
    cbreak();            /* Line buffering disabled. pass on everything */
    noecho();            /* Don't echo() while we do getch */
    keypad(stdscr, TRUE);

    printw("\n\n\n");
    printw("\t\t\t    The game is over\n\n");
    printw("\t\t\t   Your score is %d\n\n",score);
    printw("Press any key to exit");
    
    refresh();
    getch();                /* Wait for user input */
    endwin();
}