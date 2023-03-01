#include<iostream>
#include<algorithm>
using namespace std;

void printarray1D(int arr[], int n)  // A function to print the arrays
{
	for(int i=0;i<n;i++)
	{
		cout << arr[i] <<", ";
	}
}

int max_elements(int arr[], int n)    // A function to get the maximum value present in an array
{
	int max_ele = arr[0];
	int index=0;
	for(int i=1; i<n; i++){
		if(max_ele<arr[i]){
			max_ele = arr[i];
			index = i;
		}
	}
	
	return max_ele;
}

int max_index(int arr[], int n)        // A function to get the index of the presence of maximum element in an array
{
	int max_ele = arr[0];
	int index=0;
	for(int i=1; i<n; i++){
		if(max_ele<arr[i]){
			max_ele = arr[i];
			index = i;
		}
	}
	
	return index;
}

int summation(int A[], int k, int i){                     // A function to add all the elements in a specified limits of an array.

	int sum2=0;
	for(int m=k+1; m<=i; m++){
		sum2 += A[m];                                     // Summation of array A from k+1 to i.
		//cout << "m= " << m << " Tejas= " << sum2 << " A[m]= " << A[m];
	}
	return sum2;
}

////////////////////////////////////////////////////////////////////////////////

int main()
{
	int n,m;
	//int A[n], B[n];
	int c[100][100];                      //Declaring c[n][m] results in run-time arrays
	
	cout << "Enter the number of elements in the array: " << endl;   // input the number of elements in A
	cin >> n;
	cout << "Enter the elements in array A: " << endl;                // Enter the elements in A
	
	int A[n],B[n];
    for(int i=0; i<n; i++){
	cin >> A[i];                                                      // creating a dummy array B with the same values as A
	B[i] = A[i];
    }

    cout << "\nelements in A are\n" << endl;          // Print the elements in A.
    printarray1D(A,n);           
	 
	cout << "\nEnter the number of groupings that need to be formed " << endl; // Enter the number of groups that would like to divide the array A into.
	cin >> m; 
	
	/* Entering the elements of C[i][j] */
	for(int i=0;i<m;i++){                        // initializing the C matrix to be zero
		for(int j=0;j<n; j++){
			//cout << c[i][j] << ", ";
			c[n][m] = 0;
		}
		//cout<<endl;
	}
		
	/* Replacing the first row of array C as the cummiliative summation of A */
	int sum=0;
	for(int i = 0; i< n; i++)   // First row of C is cumiliative frequency of A.
	{
		sum += B[i];
		c[0][i] = sum;
	}

/////////////////////	
	
/* Define the other rows of array c as max{min{ c[k, j-1], summation A[m]}} */ 
int sum2=0;
int count = 0;
int T[100][100];       // To store the column number that resulted in generating c[i][j]

for(int i=0; i<n; i++){
	T[0][i] = i;
}

	for(int j=1; j<m; j++){                       // for each element in c[i][j]
		for(int i=0;i<n;i++){                     // for (2,0)(2,1)(1,0) have the elements as 0 itself.
			if (j>i){
				c[j][i] = 0;
			}
			else{
			
			int minimum[i-j+1];                  // Calculate argmax j-1<=k<i min{c[j-1,k], summation from k1=k+1 to i (A[k1])
			count=0;
			for(int k=j-1;k<i;k++){               // for different k values
			 
			sum2 = summation(B,k,i); 
			
				minimum[count]= (c[j-1][k]<sum2)?(c[j-1][k]):sum2;
				count = count+1;
				
			
			}
		     c[j][i] = max_elements(minimum, i-j+1);  // calculating all elements in c[i][j].
		     T[j][i] = max_index(minimum, i-j+1) + (j-1); // calculating all elements in T[i][j].
               }
		}
	}
	
/* Printing the elements of C[i][j] */ 
    cout << "\nC[i][j] matrix" << endl;
	cout << endl;
	for(int i=0;i<m;i++){                                  // m is the number of groupings.
		for(int j=0;j<n; j++){                             // n is the number of elements described in array A.
			cout << c[i][j] << ", ";
			//c[n][m] = 0;
		}
		cout << endl;
	}


/* Printing the elements of T[j][i] */ 
	cout << endl;
	cout<< "\nT[i][j] matrix" << endl;
	
	for(int i=0;i<m;i++){                                  // m is the number of groupings.
		for(int j=0;j<n; j++){                             // n is the number of elements described in array A.
			cout << T[i][j] << ", ";
			//c[n][m] = 0;
		}
		cout << endl;
	}

// Finally calculating the Goptimal solution

int new_element=0;                          // Calculate the last row manually
int Goptimal[100];
int last_element = T[m-1][n-1];               // last element 6
Goptimal[m-1] = (n-1) - last_element;     // 11-6 =5 in from the end of the array Goptimal

for(int k=m-2; k>=1; k--){                  //  Recursively loop the middle rows
new_element = T[k][last_element];     // new element is 2 in 6th position of 2nd column
Goptimal[k] = last_element - new_element; // 6-2 = 4
last_element = new_element;               // the new becomes the previous element for next iteration 
}	
Goptimal[0] = last_element+1;              // manually calcualte for the first row. +1 since the indices start from 0.

cout << "\nThe Goptimal solution for the array A with m groupings is = \n" << endl;
printarray1D(Goptimal,m);
	
	getchar();
	return 0;
}



