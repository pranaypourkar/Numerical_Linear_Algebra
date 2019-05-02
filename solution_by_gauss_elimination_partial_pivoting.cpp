#include<iostream>
#include<math.h>

#define N 3 //order of matrix A
using namespace std;

int main()
{
	int i,j,k,p,q,r;
    float c,x[N],sum=0,max;
    
    //Augmented matrix A
    float A[N+1][N+1] = { {10,-7,0,7}, 
                  { -3,2.099,6,3.901}, 
                  { 5,-1,5,6} };
				      
    printf("\n Elements are inserted in augmented matrix form:\n\n");
    
    for(j=0; j<N; j++) /* loop for the generation of upper triangular matrix*/
    {
    	
    	//check that A[j][j] is max among row otherwise interchange with max
    	    max = abs(A[j][j]);
    	    p=j;
    		for(k=j+1;k<N;k++)
    		{
    			if(abs(A[k][j])>max)
    			{
    				max = A[k][j];
    				p=k;
				}
			}
			
			for(k=0;k<N+1;k++)
			{
				q=A[j][k];
				A[j][k] = A[p][k];
				A[p][k] = q;
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
        
        
        for(p=0;p<N;p++)
       {
    	for(q=0;q<N+1;q++)
    	{
    		cout<<A[p][q]<<" ";
		}
		cout<<"\n";
	   }
	cout<<"............"<<"\n";    
        
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
