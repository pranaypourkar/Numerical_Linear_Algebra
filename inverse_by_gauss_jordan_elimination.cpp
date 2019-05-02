#include<iostream>
#include<math.h>
#define N 3
using namespace std;

int main()
{
	int i,j,k,p;
	float q,r;
    float c,sum=0;
    
    //Augmented matrix A|I
    float A[N][N+N] = { {5,7,9,1,0,0 }, 
                  { 4,3,8,0,1,0}, 
                  { 7,5,6,0,0,1} };
    
	float A_inverse[N][N];              
                  
    printf("\n Elements are inserted in augmented matrix form, A|I \n\n");
	
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
			
			for(k=0;k<N+N;k++)
			{
				q=A[j][k];
				A[j][k] = A[p][k];
				A[p][k] = q;
			}
			
		}
    	
    	
        for(i=0; i<N; i++)
        {
            if(i != j)
            {
                c=A[i][j]/A[j][j];
                for(k=0; k<N+N; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }
    
    //reduce diagonal elements to 1
    for(i=0;i<N;i++)
    {
    	q = A[i][i];
    	//cout<<"p"<<p<<"P";
    	for(j=0;j<N+N;j++)
    	{
    		A[i][j] = A[i][j]/q;
    		
    		if(j>=N)
    		{
    			A_inverse[i][j-N] = A[i][j];
			}
		}
	}
    
    cout<<"Inverse of matrix is"<<"\n";
    for(i=0;i<N;i++)
    {
    	for(j=0;j<N;j++)
    	{
    		cout<<A_inverse[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"............"<<"\n";
	
	return 0;
}
