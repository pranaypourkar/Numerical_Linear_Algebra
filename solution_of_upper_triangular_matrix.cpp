#include<iostream>
#include<math.h>
#define N 3

using namespace std;

int main()
{
	float A[N][N] = { {1,0.3,0.4 }, 
                  { 0,1,(-11/53)}, 
                  { 0,0,1} }; 
	    		  
	float b[N] = {1.5,(-170/53),1};
	float x[N], sum;
	
	int k,j;
	for(int i=N-1;i>=0;i--)
	{
	  sum=0;
	  for(j=i+1;j<N;j++)
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
