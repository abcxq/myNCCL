#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

int top = 0;
int maze[MAX_ROW][MAX_COL] = {
        0, 1, 0, 0, 0,
        0, 1, 0, 1, 0,
        0, 0, 0, 0, 0,
        0, 1, 1, 0, 0,
        0, 0, 0, 0, 0,
};

struct tagpoint{
	int row;
	int col;
};

typedef struct tagpoint point;

point stack[512];

point predecessor[MAX_ROW][MAX_COL] = {
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
};

int is_empty()
{
	if (top == 0)
		return 1;
	else
		return 0;
}

void push(point p)
{
	stack[top++] = p;
	return;
}

point pop(void)
{
	return stack[--top];
}

point gettop(void)
{
	int i = top -1 ;
	return stack[i];
}

void backtrack(point p)
{
	point pretop; //the predecessor of  point of stack top 
	point prep;  //the predecessor of points which on the backtrack path

	pretop = predecessor[gettop().row][gettop().col];
	prep = predecessor[p.row][p.col];
	maze[p.row][p.col] = 0;

	/*Which points should be marked to 0 during the backtrack?
	  The condition is that the predecessor of points on the backtrack path
	  is not equal to the predecessor of  point of stack top  */
	while(pretop.row !=  prep.row || pretop.col != prep.col) 
	{
		maze[prep.row][prep.col] = 0;
		prep = predecessor[prep.row][prep.col];
		
	}
	return ;
}

void visit(int row,int col,point pre)
{
	point p;
	maze[row][col] = 2;
	p.row = row;
	p.col = col;
	push(p);
	predecessor[row][col] = pre;
	return;
	
}
void print_maze()
{
	int i, j;
	for (i = 0; i < MAX_ROW; i++) {
		for (j = 0; j < MAX_COL; j++)
			printf("%d ", maze[i][j]);
		putchar('\n');
	}
	printf("*********\n");

	return;	
}

void print_pre(point p)
{
	printf("find out a way is \n");
	printf("(%d,%d)",p.row,p.col);
	while(predecessor[p.row][p.col].row != -1)
	{
		p = predecessor[p.row][p.col];
		printf("(%d,%d)",p.row,p.col);
	}
	printf("\n");
}

int main()
{
	int tmp;
	point p = {0,0};
	
	maze[p.row][p.col] = 2;

	push(p);
	while(!is_empty())
	{
		p = pop();
		tmp = top;

		if((p.row == MAX_ROW - 1 )&& (p.col == MAX_COL - 1))//reach the end
			print_pre(p);

		if((p.row >= 1) && (maze[p.row - 1][p.col] == 0) ) //up
			visit(p.row - 1,p.col,p); 		

		if((p.row < MAX_ROW - 1) && (maze[p.row + 1][p.col] == 0)) //down
		{	
			visit(p.row + 1,p.col,p); 		
		}

		if((p.col >= 1) && (maze[p.row][p.col - 1] == 0)) //left
			visit(p.row,p.col - 1,p); 		

		if((p.col < MAX_COL - 1) && (maze[p.row][p.col + 1] == 0) ) //right
			visit(p.row,p.col+1,p); 		
		
//		print_maze();

	
		/* nothing is pushed during this loop,that means 
		find a goal or no path,so backtrack*/
		if(tmp == top) 
		{
			backtrack(p);
		}

		
	}

//	if((p.row != MAX_ROW - 1 ) || (p.col != MAX_COL - 1))
//		printf("No path\n");
	
	printf("Serch is over\n");
		
	return 0;
}
