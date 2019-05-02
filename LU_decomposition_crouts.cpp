#include<iostream>
#include <bits/stdc++.h> 
#include<math.h>
#define N 3

//uii = 1 crouts method
using namespace std;

int main()
{
   float l[N][N], u[N][N];
   memset(l, 0, sizeof(l)); 
   memset(u, 0, sizeof(u)); 
    
   float a[N][N] = { {10,3,4}, 
                    {2,-10,3}, 
                    {3,2,-10}};
					    			
   
   for (int i = 0; i < N; i++) { 
  
        // Lower Triangular 
        for (int k = i; k < N; k++) { 
            
                // Summation of L(k, j) * U(j, i) 
                float sum = 0; 
                for (int j = 0; j < i; j++) 
				{
                    sum += (l[k][j] * u[j][i]); 
				 } 
  
                // Evaluating L(k, i) 
                l[k][i] = a[k][i] - sum; 
             
            
            // Upper Triangular 
        for (int k = i; k < N; k++) { 
  
            if (i == k)
			{
               u[i][i] = 1; // Diagonal as 1 
     		} 
            else { 
            // Summation of L(i, j) * U(j, k) 
            int sum = 0; 
            for (int j = 0; j < i; j++)
			{
                sum += (l[i][j] * u[j][k]); 	
			 }   
            // Evaluating U(i, k) 
            u[i][k] = (a[i][k] - sum)/l[i][i]; 
            
           }
        } 
            
        } 
    } 
   
   cout<<"A = "<<"\n";
   for(int i=0;i<N;i++)
   {
   	for(int j=0;j<N;j++)
   	{
   		cout<<a[i][j]<<" ";
	}
	cout<<"\n";
   }
   
      cout<<"\nL = "<<"\n";
   
   for(int i=0;i<N;i++)
   {
   	for(int j=0;j<N;j++)
   	{
   		cout<<l[i][j]<<" ";
	}
	cout<<"\n";
   }
   
   cout<<"\nU = "<<"\n";
   
   for(int i=0;i<N;i++)
   {
   	for(int j=0;j<N;j++)
   	{
   		cout<<u[i][j]<<" ";
	}
	cout<<"\n";
   }
	
	
	
	
	return 0;
}

