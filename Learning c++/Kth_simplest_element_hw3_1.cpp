/* Homework3
Question_1
Order statistics: Write codes for Rand-Select (with linear expected running time) and
Select (with linear worst-case running time). Test your two programs with an input array that is a random
permutation of A = {1, 2, 3, …, 99, 100}.
*/

/* Expected Linear Time Analysis */

#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;

int Randomised_Partition(int arr[], int start, int end); 

// Now declare a function to find the kth simplest element in an array using Randomised divide and conquer programming paradigm

int Rand_Select(int arr[], int start, int end, int k) // To function to randomly select an element.
{
    if (k > 0 && k <= end - start + 1)             // if k is in the range of the length of the array, continue 
    { 
	int pivot = Randomised_Partition(arr, start, end);

	if (pivot-start == k-1){                            // if kth element itself is the pivot then return that element as the answer.
		return arr[pivot];
	}
	if (pivot-start > k-1){
		return Rand_Select(arr,start,pivot-1,k);              // if k is less than pivot, search to the lower part of the array 
	}	//Else return 								       	  // Quicksort based method.
		return Rand_Select(arr,pivot+1,end,k-pivot+start-1); // if k is greater than pivot then search for k in the right of the pivot element.
	
}
} 

void swap(int *a, int *b)  // Function to swap 2 elements/ 2 indices in an array.
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

int Partition(int arr[], int start, int end){  // funciton to partition an array
	 int x = arr[end], i = start;              // Quick sort algorithm is applied to the array, where the last element x
    for (int j = start; j <= end - 1; j++)     // is considered the pivot 
    { 
        if (arr[j] <= x)                       
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[end]);                  // swapping pivot and last element, so that all elements smaller than pivot are 
    return i;                                  // towards the left of it, and others to the right.
}

int Randomised_Partition(int arr[], int start, int end){ //  function to randomly partition an array to randomly select a pivot between the start and the end element.
	int n = end-start+1; 
    int pivot = rand() % n;                             // To randomly select a pivot in the main array arr, where partition is applied.
    swap(&arr[start + pivot], &arr[end]); 
    return Partition(arr, start, end); 
}

void printarray1D(int arr[], int n)  // A function to print the arrays
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
	
	int k=97;            // Enter the kth smallest element that you desire to get from the input array14.
	//int n = sizeof(arr)/sizeof(arr[0]), k = 10; 
    cout << " \nK'th smallest element is: " << Rand_Select(arr, 0, n-1, k); // Calling the function
    cout << endl;
    
    return 0; 
}



