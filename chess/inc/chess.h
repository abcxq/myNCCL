#ifndef CHESS_H
#define	CHESS_H



#include <stdio.h>
#include <string.h>


#define ROW 15
#define COL 15

/* define how many chess win */
#define N 5

/* define Weight  */

#define w1 1000		//ready to five
#define w2 120		//active four
#define w3 60		//dead four
#define w4 50		//active three
#define w5 30		//dead three
#define w6 20		//active two
#define w7 10		//dead two




#define PRINT(x) printf( #x " =%s\n",x) 

/* define chessboard using matrix  */
int chessboard[ROW][COL];

int thinkboardpc[ROW][COL];	//weight table of pc
int thinkboardpe[ROW][COL];	//weight table of pe

int playerpc,playerpe;

#define COMPUTER        1
#define PEOPLE          2  


/* clear board */
void clear(int board[ROW][COL]);


/* display chessboard using printf */
void print(int board[ROW][COL]);


void  put (int x,int y,int who);

int find(); //find if have 5 numbers

int check_right(int x, int y);

int check_down(int x,int y);

int check_down_right(int x,int y);

int check_down_left(int x,int y);


void get(int *x, int *y); /* get user input */

void think(int *x,int *y); /* get conputer input */

int  test(int x, int y); // test if the position of xy is vaild

int check_level(int x, int y, int player);

int check_vertical(int x, int y, int player);

int check_45(int x, int y, int player);

int check_135(int x,int y, int player);


int get_max_value(int thinkboard[ROW][COL], int *x, int *y);



#endif	/* CHESS_H */
