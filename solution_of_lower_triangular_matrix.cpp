#include<iostream>
#include<math.h>
#define N 3

using namespace std;
int main()
{
	float A[N][N] = { {10,0,0 }, 
                  { 2,-10.6,0}, 
                  { 3, 1.1, (-1163/106)} }; 
	    		  
	float b[N] = {15,37,-10};
	float x[N], sum;
	
	int k,j;
	for(int i=0;i<N;i++)
	{
	  sum=0;
	  for(j=0;j<i;j++)
	  {
	  	sum = sum + (A[i][j]*x[j]);
	  }	
	  x[i] = (b[i] - sum)/A[i][i];	
	}
	
	cout<<"Solution of Ax=b is x = ";
	for(j=0;j<N;j++)
	{
		cout<<x[j]<<" ";
	}    		  
		
	return 0;
}
