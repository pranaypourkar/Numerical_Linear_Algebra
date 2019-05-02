#include<iostream>
#include<math.h>

#define N 4 //order of matrix A
using namespace std;

int main()
{
	int i,j,k,p,q,r;
    float c,x[N],sum=0;
    
    //Augmented matrix A
    float A[N][N+1] = { {1,-1,2,-1,-8 }, 
                  { 2,-2,3,-3,-20}, 
                  { 1,1,1,0,-2},
				  {1,-1,4,3,4} };
				  
	float b[N] = {-8,-20,-2,4};			  
    
    printf("\n Elements are inserted in augmented matrix form:\n\n");
    
    for(j=0; j<N; j++) /* loop for the generation of upper triangular matrix*/
    {
    	
    	//check that A[j][j] is non zero otherwise interchange
    	if(A[j][j]==0)
    	{
    		for(k=j+1;k<N;k++)
    		{
    			if(A[k][j]!=0)
    			{
    				p=k;
    				break;
				}
			}
			
			for(k=0;k<N+1;k++)
			{
				q=A[j][k];
				A[j][k] = A[p][k];
				A[p][k] = q;
			}
			
		}
    	
    	
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
