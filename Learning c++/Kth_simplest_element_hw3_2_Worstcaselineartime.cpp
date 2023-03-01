/*
Kth simplest element - Worst case linear time analysis
Write codes for Rand-Select (with linear expected running time) and
Select (with linear worst-case running time). Test your two programs with an input array that is a random
permutation of A = {1, 2, 3, …, 99, 100}
*/

/*
Worst case linear time analysis
*/

#include<iostream>
#include<algorithm>
#include<climits>
#include<cstdlib>
using namespace std;

int Partition(int arr[], int start, int end, int k); // k is the kth smallest integer that user demands from an input array
  
int Median(int arr[], int n)  // A funciton to calculate the median. middle elemenet of a sorted array.
{ 
    sort(arr, arr+n);  
    return arr[n/2];   
}

int Rand_Select(int arr[], int start, int end, int k) 
{ 
    if (k > 0 && k <= end - start + 1) 
    { 
        int n = end-start+1;  //Number of elements in the input array.
        int i, median[(n+4)/5]; // First step is to divide the input array into n/5 groups of 5 elements each. 
        for (i=0; i<n/5; i++)  
            median[i] = Median(arr+start+i*5, 5);  // for each group find the median.
        if (i*5 < n) //For last group with less than 5 elements 
        { 
            median[i] = Median(arr+start+i*5, n%5);  // Last group can have less than 5 elements, for that recursively calculate the median.
            i++; 
        }      // All the medians of n/5 groups are stored in the array median, to further calculate the median of medians.
  
        int medOfMed = (i == 1)? median[i-1]: Rand_Select(median, 0, i-1, i/2); // if there is only one element in the array, then return that
                                                                                // Else recursively calculate the median of medians.
        int pivot = Partition(arr, start, end, medOfMed); 
  
        // If position is same as k 
        if (pivot-start == k-1)  //if k is less than pivot, search to the lower part of the array 
            return arr[pivot]; 
        if (pivot-start > k-1)  // if k is greater than pivot then search for k in the right of the pivot element.
            return Rand_Select(arr, start, pivot-1, k); // Quicksort based method.
        // else   
        return Rand_Select(arr, pivot+1, end, k-pivot+start-1); 
    } 
} 

void swap(int *a, int *b) // Function to swap 2 elements/ 2 indices in an array.
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

int Partition(int arr[], int start, int end, int x) // In a given input array, search for the element x and then partition the array 
{                                                   // such that x is the pivot.
    int i; 
    for (i=start; i<end; i++) 
        if (arr[i] == x) 
           break; 
    swap(&arr[i], &arr[end]); 
  
    i = start; 
    for (int j = start; j <= end - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[end]); 
    return i; 
} 
  
void printarray1D(int arr[], int n)  // A function to print the one dimensional arrays
{
	for(int i=1;i<=n;++i)
	{
		cout << arr[i] <<"  ";
	}
}

int main()                                             // main part of the funciton.
{ 

	int n=100;
	
	int a[n];         // Initial array with given elements [1,2...100]
	int arr[n];       // Random permutation of the given array of elements.
	for(int i=1; i<=n; ++i)
	{
		a[i]=i;        // [1,2...100]
	}
	cout << "Input Array before random permutation [1....100] \n" << endl;
	
	printarray1D(a,n); // print array from 1...100
	cout << endl;
	
	
	for(int i=1;i<=n;++i)
	{
		int index = rand() % (n-1);   // Generating random index
		arr[i] = a[index];            // shuffling the elements in the array 'a'
	}
	
	cout << "Input Array after random permutation of elements from [1....100] \n" << endl;
	
	printarray1D(arr,n); // print array with random permutation over elements from 1 to 100.
	cout << endl;
	
	int k=99;            // Enter the kth smallest element that you desire to get from the input array14.
	//int n = sizeof(arr)/sizeof(arr[0]), k = 10; 
    cout << " \nK'th smallest element is: " << Rand_Select(arr, 0, n-1, k); // Calling the function
    cout << endl;
    return 0; 
}

