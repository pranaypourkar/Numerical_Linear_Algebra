#include<iostream>
#include<math.h>
#define N 4

using namespace std;

int main()
{
	int A[N][N] = { {5, -2, 2, 7}, 
                    {1, 0, 0, 3}, 
                    {-3, 1, 5, 0}, 
                    {3, -1, -9, 4}};
	 
	int x[N];
	int b[N] = {1,2,3,4};
		
    //A* = inverse(A), A* = conj(transpose(A))
	//transpose of A
	int i,j,k;
	for(i=0;i<N;i++)
	{
		for(j=i+1;j<N;j++)
		{
			k = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = k;
		}
	}
	 		
	int sum;
	
	for(i=0;i<N;i++)
	{
		sum = 0;
		for(j=0;j<N;j++)
		{
			sum = sum + (A[i][j] * b[j]);
		}
		x[i] = sum;
	}
	
	cout<<"Solution of Ax=b is x = ";
 	for(j=0;j<N;j++)
 	 {
 		cout<<x[j]<<" ";
	 }
		
		
		
		
	
	
	
	
	return 0;
}
