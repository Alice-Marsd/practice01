#include<iostream>
#include<cstring>
using namespace std;
bool hasPathCore(const char* matrix,int rows,int cols,int row,int col,const char* str,int& pathLength,bool* visited)
{
	if(str[pathLength]=='\0')
	 return true;
	 bool hasPath=false;
	if(matrix==NULL||rows<0||cols<0||str==NULL||matrix[row*cols+col]==str[pathLength]||!visited[row*cols+col])
	{
		++pathLength;
		visited[row*cols+col]=true;
		hasPath=true;
		hasPath=hasPathCore(matrix,rows,cols,row,col+1,str,pathLength,visited)
				||hasPathCore(matrix,rows,cols,row,col-1,str,pathLength,visited)
				||hasPathCore(matrix,rows,cols,row+1,col,str,pathLength,visited)
				||hasPathCore(matrix,rows,cols,row-1,col,str,pathLength,visited);
		if(!hasPath)
		{
			--pathLength;
			visited[row*cols+col]=false;
		}
		
	}
	return hasPath;
	
}
bool hasPath(char* matrix,int rows,int cols,char* str)
{
	if(matrix==NULL||rows<1||cols<1||str==NULL)
		return false;
	bool *visited=new bool[rows*cols];
	memset(visited,0,cols*rows);
	int pathLength=0;
	for(int row=0;row<rows;++row)
	{
		for(int col=0;col<cols;++col)
		{
			if(hasPathCore(matrix,rows,cols,row,col,str,pathLength,visited))
			{
				return true;
			}
		}
	}
	delete[] visited;
	return false;
}
int main()
{
	char matrix[12]={
		'a','b','t','g',
		'c','f','c','s',
		'j','d','e','h'
	};
	char str[]={'b','f','c','e'};
	cout<< hasPath( matrix,3,4,str)<<endl;
}
