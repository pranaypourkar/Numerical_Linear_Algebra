
// CPP Program to check whether given matrix 
// is Diagonally Dominant Matrix. 
#include<iostream>
#include<math.h>
#define N 4
using namespace std; 
   
  
// Driven Program 
int main() 
{ 
    
    int n = 4; 
    int m[N][N] = { { 8, 0, -2, -3 }, 
                    { -2, -10, 2, 2}, 
                    { 1, -6, 12, -3},
					{ -3, 2, 3, -15} }; 
                    
    bool status = true;
	int diff_array[n] , delta;                
  
     // for each row 
    for (int i = 0; i < n; i++) 
   {         
  
        // for each column, finding sum of each row. 
        int sum = 0; 
        for (int j = 0; j < n; j++) 
		{
		  sum = sum + abs(m[i][j]);         
        } 
  
        // removing the diagonal element. 
        sum = sum - abs(m[i][i]); 
  
        // checking if diagonal element is less  
        // than sum of non-diagonal element. 
        if (abs(m[i][i]) < sum)
		{
		  status = false; 	
		}
		else
		{
			diff_array[i] =  abs(m[i][i]) - sum;
			//cout<<diff_array[i]<<"\n";
		}  
                     
    }  
    
    //check for diagonal dominant or not
    if(status == true)
    {
      //let delta=diff_array[0]	
      delta = diff_array[0];
      for(int j=1;j<n;j++)
	  {
	  	if(delta>diff_array[j])
	  	{
	  		delta = diff_array[j];
		}
	  }	
	  
	  cout<<"Given Square matrix is diagonal dominant"<<"\n"<<"Magnitude of diagonal dominance is delta = "<<delta;
	  
	}
	else
	{
	  cout<<"Given Square matrix is NOT diagonal dominant";	
	}
  
    return 0; 
} 

