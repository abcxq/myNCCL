#include "chess.h"

/*   */

int main(int argc, char *argv[])
{
	int x = ROW/2, y = COL/2;
	int step = 0;
	int who;
	int first;

	if (argc < 2)
	{
		PRINT("./a.out who_is_first(pc/people)\n");
		return 0;
	}

	if (strcmp(argv[1], "pc") == 0)
	{
		PRINT("pc first\n");
		first = COMPUTER;      //1
		playerpc = 1;
		playerpe = 2;
	}
	else
	{
		PRINT("people first\n");
		first = PEOPLE;      //2
		playerpc =  2;
		playerpe =  1;
	}

	clear(chessboard); // init chess board;
	printf("Hello\n");
	print(chessboard);
	printf(" ");

	while(1)
	{
		who = step % 2 + 1;
		printf("player %d: ", who);	
		
		if ( first == who)
		{
			if ( step != 0)
				think(&x, &y);
			fprintf(stdout, "step %d : %d  %d\n", step, x, y);
			fflush(stdout);
		}
		else
		{
			get(&x, &y);
		}
		if (test(x, y))
		{
			put(x, y, who); //if (step !=0)
		
			print(chessboard);

			step++;

			if (find())
			{
				printf("Congratulations, player %d win! \n",who);
				return 0;
			} 
		}
		else
			printf("%d %d is not permitted ! Please reinput \n\n",x,y);  
	} 
	return 0; 
}
