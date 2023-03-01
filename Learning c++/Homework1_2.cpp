
// Insertion Sort and Merge Sort
// Headers
#include <iostream>
#include<ctime>
#include<stdlib.h>
#include <cstdlib>

using namespace std;

void merge(int arr[], int l, int m, int r)  // Starting merge sort, Merging part of the algorithm.
{ 											// Low, High and middle values as parameters to divide an input array.
    int i, j, k;                            
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    // create temp arrays 
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into main array*/
    i = 0; 
    j = 0;
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r)  // Sorting part of the algorithm
{ 
    if (l < r) 
    { 
        
        int m = l+(r-l)/2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}                                         // Merge Sort ends here


void insertionSort(int arr[], int n)      // Start Program for Insertion sort 
{
   int i, key, j;
   for (i = 0; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}


void printArray(int arr[], int n)       // A small function to print arrays
{
   int i;
   for (i=0; i < n; i++)
       cout << arr[i] << endl;
       cout << "\n" << endl;
}

 
int main()
{
	int arr[100], arr1[100];            // two arrays with same values for merge and insertion sort separatly
//	float elapsed_Insertion_sort_secs, elapsed_Merge_sort_secs;
	int n;
	
	// creating an array in reverse sorted order of size n (worst case condition for insertion sort).
	cout << "Enter value of n" << endl;
	cin >> n;
	
	for(int i=n-1; i>=0; i--)
	{
		arr[i] = n-i-1;
		arr1[i] = n-i-1; 
	}

// checking if code is correct till here
cout << "\n Before Sorted arr: \n" << endl;     // Checking the value of arr, if the elements are in worst case condition
printArray(arr, n);
//cout << "\n Before Sorted arr1: \n" << endl;
//printArray(arr1, n);

// calculating the time for insertion sort
clock_t begin1 = clock();
insertionSort(arr, n);
clock_t stop1 = clock();
cout << "\n Insertion sort result" << endl;
printArray(arr, n);
clock_t elapsed_Insertion_sort_secs = double(stop1 - begin1) /(CLOCKS_PER_SEC);
cout << "\n elapsed_Instertion_sort_secs = " << elapsed_Insertion_sort_secs << endl;

// calculating time for merge sort
clock_t begin2 = clock();
mergeSort(arr1,0, n-1);
clock_t stop2 = clock();
cout << " \n Merge sort result: \n" << endl;
printArray(arr1, n);
clock_t elapsed_Merge_sort_secs =(double)(stop2 - begin2)/(CLOCKS_PER_SEC);
cout << "\n elapsed_Merge_sort_secs = " << elapsed_Merge_sort_secs << endl;
}


