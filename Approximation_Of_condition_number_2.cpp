#include<iostream>
#include<math.h>
#define N 4

using namespace std;

float approximation_of_2_norm(float A[N][N])
{
    int i,j,k,sum;
	float x[N];
	float y[N];
	
	//step 1
	x[0] = 1;
	y[0] = A[0][0]*x[0];
	
	//step 2
	for(i=1;i<N;i++)
	{
		sum=0;
		for(j=0;j<i;j++)
		{
			sum = sum + A[i][j]*x[j];
		}
		
		if(abs(A[i][i] + sum) > abs(A[i][i] - sum))
		{
			x[i] = 1;
		}
		else
		{
			x[i] = -1;
		}
		y[i] = (A[i][i]*x[i]) + sum;
	}
	 
	 //step 3
	 float y_2_norm=0;
	 for(i=0;i<N;i++)
	 {
	 	y_2_norm = y_2_norm + (y[i]*y[i]);
	 }
	 
	 y_2_norm = sqrt(y_2_norm);
	 
	 //cout<<"2 norm of vector y is found out to be "<<y_2_norm<<"\n";
	 
	 return y_2_norm/sqrt(N);
}

float approximation_of_2_norm_inverse(float A[N][N])
{
	int i,j,k,sum;
	//A is lower triangular matrix
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
	 
	 //cout<<"2 norm of vector y is found out to be "<<y_2_norm<<"\n";
	 
	 return y_2_norm/sqrt(N);		
}



int main()
{
		float A[N][N] = {{2,0,0,0},{4,-2,0,0},{-5,6,1,0},{1,5,3,3}};
        float norm_A, norm_A_inverse;
        norm_A = approximation_of_2_norm(A);
        norm_A_inverse = approximation_of_2_norm_inverse(A);
        
        cout<<"Approximation of condition number A is : "<<norm_A*norm_A_inverse;
	
	
	
	
	return 0;
}
