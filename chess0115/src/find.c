#include "chess.h"

int check_right(int x, int y)
{
	int counter = 1;
	int temp,i;

	temp = chessboard[x][y];

	if (temp == 0)
		return 0;
	else
	{
		for (i = 1;i<N;i++)
		{
			int nx,ny; //next position
			
			nx=x;
			ny=y+i;

			if ( ny >= COL )    //ny is out of board 
				return 0;

			if (temp == chessboard[nx][ny])
				counter++;
		}
	}
	
	if ( N ==counter )
	{
		printf("game over!%d %d have five numbers",x,y);
		return 1;
	}
	return 0;
}


int check_down(x,y)
{
	int counter = 1;
        int temp,i;

        temp = chessboard[x][y];

        if (temp == 0)
                return 0;
        else
        {   
                for (i = 1;i<N;i++)
                {   
                        int nx,ny; //next position
    
                        nx=x+i;
                        ny=y;

                        if ( nx >= ROW)    //nx is out of board 
                                return 0;

                        if (temp == chessboard[nx][ny])
                                counter++;
                }   
        }   
    
        if ( N ==counter )
        {   
                printf("game over!%d %d have five numbers",x,y);
                return 1;
        }   
        return 0;
}	


int check_down_right(x,y)
{
        int counter = 1;
        int temp,i;

        temp = chessboard[x][y];

        if (temp == 0)
                return 0;
        else
        {
                for (i = 1;i<N;i++)
                {
                        int nx,ny; //next position

                        nx=x+i;
                        ny=y+i;

                        if ( nx >= ROW || ny >=COL )    //nx,ny is out of board 
                                return 0;

                        if (temp == chessboard[nx][ny])
                                counter++;
                }
        }

        if ( N ==counter )
        {
                printf("game over!%d %d have five numbers",x,y);
                return 1;
        }
        return 0;
}

int check_down_left(x,y)
{
        int counter = 1;
        int temp,i;

        temp = chessboard[x][y];

        if (temp == 0)
                return 0;
        else
        {
                for (i = 1;i<N;i++)
                {
                        int nx,ny; //next position

                        nx=x+i;
                        ny=y-i;

                        if ( nx >= ROW || ny < 0 )    //nx,ny is out of board 
                                return 0;

                        if (temp == chessboard[nx][ny])
                                counter++;
                }
        }

        if ( N ==counter )
        {
                printf("game over!%d %d have five numbers",x,y);
                return 1;
        }
        return 0;
}

int find()
{
	int i ,j;

	for (i = 0;i < ROW;i++)
	{
		for(j = 0;j< COL;j++)
		{
			if (check_right(i, j))
				return 1;

			if (check_down(i,j))
				return 1;

			if (check_down_right(i,j))
				return 1;

			if (check_down_left(i,j))
				return 1;
		}
	}
 	return 0;
}
