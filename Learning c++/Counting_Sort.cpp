/*
Counting sort
Write codes for counting sort. The input array is A = {20, 18, 5, 7, 16,
10, 9, 3, 12, 14, 0}.
*/

#include<iostream>

using namespace std;
int k=0;


void counting_sort(int A[],int B[], int n)
{
	int c[k];
	for(int i=0; i<k+1;i++)
	{
		c[i]=0;             //create a null matrix with n elements
	}
	for(int j=1; j<=n;j++) 
	{
		c[A[j]]=c[A[j]]+1; // counts the presence of each element in the input array A and stores it in array C
	}
	for(int i=1; i<=k; i++)
	{
		c[i] = c[i]+c[i-1]; // cumiliatve frequency of the elements in array c.
	}
	for(int j=n; j>=1;j--)
	{
		B[c[A[j]]]=A[j];    // Counting sort final step
		c[A[j]]=c[A[j]]-1;
	}
	
}

void printarray(int arr[], int n)  // A function to print the arrays
{
	for(int i=1;i<=n;++i)
	{
		cout << arr[i] <<"  ";
	}
}

int main()
{
	int n;                    // Enter the number of elements in the array
	
	cout<<"Enter the size of the array :";
	cin>>n;              
		
	cout << "Enter the elements in array A" << endl;
	int A[n],B[n]; 
	
	for(int i=1;i<=n;i++)    // Fill the elements in array A        
	{
		cin>>A[i];
		if(A[i]>k)
		{
			k=A[i];              
		}
	}
	cout << "Input array: " << endl;
	printarray(A,n);
	counting_sort(A,B,n);        // Do counting sort over the elements present in A
	
	cout << " \nOutput array after counting sort: " << endl;
	printarray(B,n);
	
	cout<<endl;
	return 0;
}
