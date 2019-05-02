#include<iostream>
#include<math.h>
#define N 3
using namespace std;

int main()
{
	float A[N][N] = { {2,0,0}, 
                  { 0,3,0}, 
                  { 0,0,4} }; 
	    		  
	float b[N] = {2,9,8};
	float x[N];
	int i,j,k;
	for(i=0;i<N;i++)
	{
		x[i] = b[i]/A[i][i];
	}
	
	cout<<"Solution of Ax=b is x = ";
	for(j=0;j<N;j++)
	{
		cout<<x[j]<<" ";
	}
		
	return 0;
}



