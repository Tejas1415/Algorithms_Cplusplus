/* 
Longest Common Subsequence - Print the longest common subsequence among the given 2 strings
Also, mention the length of the LCS found.
*/

#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<climits>
#include<cstring>
using namespace std;

// Let X and Y be the input strings. 'm' is the length of the string X and n is length of the string y.
void LeastCommonSubsequence(char *X, char *Y, int m, int n)
{
	int table[m+1][n+1]; // Dynamic programming table that is to be filled up in bottom up fashion.

	for (int i=0; i<=m; i++) 
   { 
     for (int j=0; j<=n; j++) 
     { 
       if (i == 0 || j == 0) // if the iteration reaches top of the table, then stop.
         table[i][j] = 0; 
       else if (X[i-1] == Y[j-1])  // go diagonally if elements match
         table[i][j] = table[i-1][j-1] + 1; 
       else                          //  else travel in the direction of larger element.
         table[i][j] = max(table[i-1][j], table[i][j-1]); 
     } 
   }
   
   // Once the table is filled, we need to trace back the LCS in bottom up fashion. 
   // From the bottom rightmost corner, iterate back up, to find the common subsequence at each level.
   
   int index = table[m][n]; // the last element in the table.
   char LCS[index+1];  // a dummy array to store the common subsequence at each level.
   //LCS[index] = '';  // set the last element in the array as a terminating character. Used while printing the final sequence.
   
   int i=m;
   int j=n;
   while (i>0 && j>0)  // end of iteration is when we reach the top-left element of the table from bottom right element.
   {
   	if (X[i-1] == Y[j-1]){
   		LCS[index-1] = X[i-1]; // if corresponding element in row and column of 'table' match, then note down the value from the end 
   		i=i-1;                 // of matrix LCS. Reduce all the parameters for the next iteraion
   		j=j-1;
   		index = index-1;
   	}
   	
   	else if(table[i-1][j]> table[i][j-1]) {  // If diagonally not matched, then traverse in the direction of the larger element.
   		i=i-1;                           // either to the top
	   }
	   else
	   {
	   	j=j-1;                          // or sideways
	   }
   
   } 
   
   cout << "LCS of " << X << " and " << Y << " is " << LCS << endl; // once loop terminated, print the sring LCS.
   int length = strlen(LCS); // Find the length of LCS
   cout << "\nThe length of the longest common subsequence found is: " << length << endl; // print the length of LCS
}


int main() // main part of the program.
{ 
  char X[] = "TEJASKRISHNAREDDY";   // input strings
  char Y[] = "TEHHMLKNDKLNAPIFN"; 
  int m = strlen(X);     // length of input strings
  int n = strlen(Y); 
  LeastCommonSubsequence(X, Y, m, n);  // recursively call the funciton to obtain desired results.
  return 0; 
} 

