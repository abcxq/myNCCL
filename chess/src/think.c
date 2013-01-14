#include "chess.h"


/* get the max valuable position */
int get_max_value(int thinkboard[ROW][COL], int *x, int *y)
{
	int i,j;
	int max = 0;
	int cur;
	
	for (i = 0; i < ROW; i++)
	{
		for(j = 0; j < COL; j++)
		{
			/* get thinkboard value to cur */
			cur = thinkboard[i][j];

			/* if cur >max,then set the cur value to max */
			if (cur > max)
			{
				max = cur;
				*x = i;
				*y = j;
			}
		}
	}
	
	return max;
}
void think( int *x, int *y )
{
	int i ,j,maxpc,maxpe;
	int pcx=0,pcy=0,pex=0,pey=0;

	for ( i =0; i< ROW; i++)
		for( j = 0;j <COL;j++)
		{
			thinkboardpc[i][j] = 0;
			thinkboardpe[i][j] = 0;
		}		

	for ( i = 0;i < ROW; i++)   //count the weigth of pc
		for( j = 0;j <COL;j++)
		{
			if (chessboard[i][j] != 0)
				continue;
			else
			{
				thinkboardpc[i][j] += check_level(i,j,playerpc);
				thinkboardpc[i][j] += check_vertical(i,j,playerpc);
				thinkboardpc[i][j] += check_45(i,j,playerpc);
				thinkboardpc[i][j] += check_135(i,j,playerpc);	
			}
		}


	for ( i = 0;i < ROW; i++)	//count the weigth of pe
		for( j = 0;j <COL;j++)
		{
			if (chessboard[i][j] != 0)
				continue;
			else
			{
				thinkboardpe[i][j] += check_level(i,j,playerpe);
				thinkboardpe[i][j] += check_vertical(i,j,playerpe);
				thinkboardpe[i][j] += check_45(i,j,playerpe);
				thinkboardpe[i][j] += check_135(i,j,playerpe);	
			}
		}
		
	maxpc = get_max_value(thinkboardpc,&pcx,&pcy);
	maxpe = get_max_value(thinkboardpe,&pex,&pey);

	if ( maxpc >= maxpe )	 
	{
		*x = pcx;
		*y = pcy;

	}
	else
	{
		*x = pex;
		*y = pey;
	}
}



int check_vertical(int x, int y, int player)
{
	int i;	
	int counterplayer = 0;	//统计player棋子的个数
	int counter = 0;	//统计player对手棋子的个数
	int counter0 = 0;	//统计空白点的个数
	int nx;

	for( i = 1; i < 5; i++)	//count up 
	{
		nx = x - i;

		if ( nx < 0 )
			break;
	
		if ( chessboard[nx][y] == player  )	
		{
			counterplayer ++;
			continue;
		}
		else
		{
			if ( chessboard[nx][y] == 0)
			{
				counter0 ++;	//空白点加一
				break;
			}
			else
			{
				counter ++;	//对手棋加一
				break;
			}
		}
	}

	for( i = 1; i < 5; i++)	//count down
	{
		
		nx = x + i;

		if ( nx > COL )
			break;
	
		if ( chessboard[nx][y] == player  )	
		{
			counterplayer ++;
			continue;
		}
		else
		{
			if ( chessboard[nx][y] == 0)
			{
				counter0 ++;	//空白点加一
				break;
			}
			else
			{
				counter ++;	//对手棋加一
				break;
			}
		}
	}

	if ( counterplayer == 4)
		return w1;

	if ( counter == 2 || counterplayer == 0 )
		return 0 ;

	if ( counter == 1)
	{
		switch ( counterplayer )
		{
			case 3:	
				return w3;
			case 2:
				return w5;
			case 1:
				return w7;
		}
	}
	else
	{
		switch ( counterplayer )
		{
			case 3:	
				return w2;
			case 2:
				return w4;
			case 1:
				return w6;
		}
	}
}
		
				

int check_level(int x, int y, int player)
{
	int i;	
	int counterplayer = 0;	//统计player棋子的个数
	int counter = 0;	//统计player对手棋子的个数
	int counter0 = 0;	//统计空白点的个数
	int ny;

	for( i = 1; i < 5; i++)	//count left 
	{
		ny = y - i;

		if ( ny < 0 )
			break;
	
		if ( chessboard[x][ny] == player  )	
		{
			counterplayer ++;
			continue;
		}
		else
		{
			if ( chessboard[x][ny] == 0)
			{
				counter0 ++;	//空白点加一
				break;
			}
			else
			{
				counter ++;	//对手棋加一
				break;
			}
		}
	}

	for( i = 1; i < 5; i++)	//count right
	{
		
		ny = y + i;

		if ( ny > COL )
			break;
	
		if ( chessboard[x][ny] == player  )	
		{
			counterplayer ++;
			continue;
		}
		else
		{
			if ( chessboard[x][ny] == 0)
			{
				counter0 ++;	//空白点加一
				break;
			}
			else
			{
				counter ++;	//对手棋加一
				break;
			}
		}
	}

	if ( counterplayer == 4)
		return w1;

	if ( counter == 2 || counterplayer == 0 )
		return 0 ;

	if ( counter == 1)
	{
		switch ( counterplayer )
		{
			case 3:	
				return w3;
			case 2:
				return w5;
			case 1:
				return w7;
		}
	}
	else
	{
		switch ( counterplayer )
		{
			case 3:	
				return w2;
			case 2:
				return w4;
			case 1:
				return w6;
		}
	}
	return;
}
		
	
int check_45(int x, int y, int player)
{
	int i;	
	int counterplayer = 0;	//统计player棋子的个数
	int counter = 0;	//统计player对手棋子的个数
	int counter0 = 0;	//统计空白点的个数
	int nx,ny;

	for( i = 1; i < 5; i++)	//count left_down 
	{
		nx = x + i;
		ny = y - i;

		if ( ny < 0 || nx > ROW )
			break;
	
		if ( chessboard[nx][ny] == player  )	
		{
			counterplayer ++;
			continue;
		}
		else
		{
			if ( chessboard[nx][ny] == 0)
			{
				counter0 ++;	//空白点加一
				break;
			}
			else
			{
				counter ++;	//对手棋加一
				break;
			}
		}
	}

	for( i = 1; i < 5; i++)	//count left_up
	{
		
		nx = x - i;
		ny = y + i;

		if ( ny > COL  || nx < 0 )
			break;
	
		if ( chessboard[nx][ny] == player  )	
		{
			counterplayer ++;
			continue;
		}
		else
		{
			if ( chessboard[nx][ny] == 0)
			{
				counter0 ++;	//空白点加一
				break;
			}
			else
			{
				counter ++;	//对手棋加一
				break;
			}
		}
	}

	if ( counterplayer == 4)
		return w1;

	if ( counter == 2 || counterplayer == 0 )
		return 0 ;

	if ( counter == 1)
	{
		switch ( counterplayer )
		{
			case 3:	
				return w3;
			case 2:
				return w5;
			case 1:
				return w7;
		}
	}
	else
	{
		switch ( counterplayer )
		{
			case 3:	
				return w2;
			case 2:
				return w4;
			case 1:
				return w6;
		}
	}
}
		
int check_135(int x, int y, int player)
{
	int i;	
	int counterplayer = 0;	//统计player棋子的个数
	int counter = 0;	//统计player对手棋子的个数
	int counter0 = 0;	//统计空白点的个数
	int nx,ny;

	for( i = 1; i < 5; i++)	//count right_down 
	{
		nx = x + i;
		ny = y + i;

		if ( ny > COL || nx > ROW )
			break;
	
		if ( chessboard[nx][ny] == player  )	
		{
			counterplayer ++;
			continue;
		}
		else
		{
			if ( chessboard[nx][ny] == 0)
			{
				counter0 ++;	//空白点加一
				break;
			}
			else
			{
				counter ++;	//对手棋加一
				break;
			}
		}
	}

	for( i = 1; i < 5; i++)	//count right_up
	{
		
		nx = x - i;
		ny = y - i;

		if ( ny < 0  || nx < 0 )
			break;
	
		if ( chessboard[nx][ny] == player  )	
		{
			counterplayer ++;
			continue;
		}
		else
		{
			if ( chessboard[nx][ny] == 0)
			{
				counter0 ++;	//空白点加一
				break;
			}
			else
			{
				counter ++;	//对手棋加一
				break;
			}
		}
	}

	if ( counterplayer == 4)
		return w1;

	if ( counter == 2 || counterplayer == 0 )
		return 0 ;

	if ( counter == 1)
	{
		switch ( counterplayer )
		{
			case 3:	
				return w3;
			case 2:
				return w5;
			case 1:
				return w7;
		}
	}
	else
	{
		switch ( counterplayer )
		{
			case 3:	
				return w2;
			case 2:
				return w4;
			case 1:
				return w6;
		}
	}
}
