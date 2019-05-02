#include<iostream>
#include<math.h>

#define N 3 //order of matrix A
using namespace std;

int main()
{
	int i,j,k,p,q,r;
    float c,x[N],sum=0;
    
    //Augmented matrix A
    float A[N+1][N+1] = { {0.143,0.357,2.01,-5.17 }, 
                  { -1.31,0.911,1.99,-5.46}, 
                  { 11.2,-4.3,0.605,4.42} };
				      
    printf("\n Elements are inserted in augmented matrix form:\n\n");
    
    for(j=0; j<N; j++) /* loop for the generation of upper triangular matrix*/
    { 	
             	
        for(i=0; i<N; i++)
        {
            if(i>j)
            {
                c=A[i][j]/A[j][j];
                for(k=0; k<N+1; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }
    x[N-1]=A[N-1][N]/A[N-1][N-1];
    /* this loop is for backward substitution*/
    
    for(i=0;i<N;i++)
    {
    	for(j=0;j<N+1;j++)
    	{
    		cout<<A[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"............"<<"\n";
    
    
    
    
    for(int i=N-1;i>=0;i--)
	{
	  sum=0;
	  for(j=i+1;j<N;j++)
	  {
	  	sum = sum + (A[i][j]*x[j]);
	  }	
	  x[i] = (A[i][N] - sum)/A[i][i];	
	}
	
	cout<<"Solution of Ax=b is x = ";
	for(j=0;j<N;j++)
	{
		cout<<x[j]<<" ";
	}  
	
	
	
	return 0;
}
