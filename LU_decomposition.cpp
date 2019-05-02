#include<iostream>
#include <bits/stdc++.h> 
#include<math.h>
#define N 3

//lii = 1 doolittle method
using namespace std;

int main()
{
   int l[N][N], u[N][N];
   memset(l, 0, sizeof(l)); 
   memset(u, 0, sizeof(u)); 
    
   int a[N][N] = { {2,-1,-2}, 
                    {-4,6,3}, 
                    {-4,-2,8}};
					    			
   
   for (int i = 0; i < N; i++) { 
  
        // Upper Triangular 
        for (int k = i; k < N; k++) { 
  
            // Summation of L(i, j) * U(j, k) 
            int sum = 0; 
            for (int j = 0; j < i; j++)
			{
                sum += (l[i][j] * u[j][k]); 	
			 }   
            // Evaluating U(i, k) 
            u[i][k] = a[i][k] - sum; 
        } 
  
        // Lower Triangular 
        for (int k = i; k < N; k++) { 
            if (i == k) 
                l[i][i] = 1; // Diagonal as 1 
            else { 
  
                // Summation of L(k, j) * U(j, i) 
                int sum = 0; 
                for (int j = 0; j < i; j++) 
                    sum += (l[k][j] * u[j][i]); 
  
                // Evaluating L(k, i) 
                l[k][i] = (a[k][i] - sum) / u[i][i]; 
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

