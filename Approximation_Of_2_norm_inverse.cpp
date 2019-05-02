#include<iostream>
#include<math.h>
#define N 4

using namespace std;

int main()
{
	int i,j,k,sum;
	//A is lower triangular matrix
    float A[N][N] = {{2,0,0,0},{4,-2,0,0},{-5,6,1,0},{1,5,3,3}};
	float x[N];
	float y[N];
	int sign;
	
	//step 1
	x[0] = 1;
	y[0] = 1/(A[0][0]);
	
	//step 2
	for(i=1;i<N;i++)
	{
		sum=0;
		for(j=0;j<i;j++)
		{
			sum = sum + A[i][j]*y[j];
		}
		
		if(sum>0)
		{
			sign = 1;
		}
		else
		{
			sign = -1;
		}
		
		
		y[i] = (-1/A[i][i])*(sum + sign);
	}
	 
	 //step 3
	 float y_2_norm=0;
	 for(i=0;i<N;i++)
	 {
	 	y_2_norm = y_2_norm + (y[i]*y[i]);
	 }
	 
	 y_2_norm = sqrt(y_2_norm);
	 
	 cout<<"2 norm of vector y is found out to be "<<y_2_norm<<"\n";
	 
	 cout<<"Approximation of 2 norm of matrix A inverse estimates to "<<y_2_norm/sqrt(N)<<"\n";
	 
	
	return 0;
}
