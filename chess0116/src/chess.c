#include "chess.h"

/* clear board */
void clear(int board[ROW][COL])
{
	int i, j;

	for(i = 0; i < ROW; i++)
		for(j = 0; j < COL; j++)
			board[i][j] = 0;
}

/* display chessboard using printf */
void print(int board[ROW][COL])
{
	int i, j;
	char * str = "0123456789abcdef";

	printf("\n");
	printf("  ");

	for (j = 0; j < COL; j++)
		printf(" %c", str[j]);
	printf("\n");

        printf(" -");
        for (j = 0; j < COL; j++)
        	printf(" -");

    	printf("\n");
    	for (i = 0; i < ROW; i++) 
	{
        	printf("%c| ", str[i]);
        	for (j = 0; j < COL; j++) 
		{
            		printf("%d ", board[i][j]);
        	}
        	printf("\n");
    	}

    printf("\n");
}

void  put (int x,int y,int who)
{
	chessboard[x][y] = who;
	
	return ;
}	


/* get user input */
void get(int *x, int *y)
{
	int *z;
	scanf("%d %d",x,y);
	//scanf("step %d : %d %d\n",z,x,y);
	return ;
}

int  test(int x, int y)
{
	if (x >= ROW || x < 0)
        	return 0;

	if (y >= COL || y < 0)
        	return 0;

	if (chessboard[x][y] != 0 )
        	return 0;
		
	return 1;
}


