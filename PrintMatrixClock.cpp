#include<stdio.h>

void PrintMatrixInCircle(int **matrix,int col,int row,int start)
{
	int endX=col-1-start;
	int endY=row-1-start;
	for(int i=start;i<=endX;++i)
		printf("%5d",matrix[start][i]);
	if(start<endY)
	{
		for(int i=start+1;i<=endY;++i)
		printf("%5d",matrix[i][endY]);
	}
	if(start<endX && start<endY)
	{
		for(int i=endX-1;i>=start;--i)
		printf("%5d",matrix[endY][i]);
	}
	
	if(start<endX && start<endY-1)
	{
		for(int i=endY-1;i>start;--i)
		printf("%5d",matrix[i][start]);
	
	}

}
void PrintMatrixClock(int **matrix,int col,int row)
{
	if(matrix==NULL || col<=0 ||row<= 0)
	return ;
	int start=0;
	while(col>start*2 || row>start*2)
	{
		PrintMatrixInCircle(matrix,col,row,start);
		start++;
	}
}
int main()
{
	int matrix[4][5]={	{1 ,2 ,3 ,4,0},
						{5 ,6 ,7 ,8,0},
						{9 ,10,11,12,0},
						{13,14,15,16,0}
					};
	int *p[4]={matrix[0],matrix[1],matrix[2],matrix[3]};
	int **pArray=NULL;
	pArray = p; 
	PrintMatrixClock(pArray,5,4);
}
