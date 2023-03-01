/*
Heap Sort
Write codes for heapsort. The input array is a random permutation of A={1,
2, 3, …, 99, 100}. You should write codes to generate and print the random permutation.
*/

#include<iostream>                         // Headers
#include<ctime>
#include<cstdlib>
using namespace std;

void heapify(int arr[], int n, int i)      // To build the max_heap
{
	int largest = i;                       // Declaring the general notation of the indices
	int left  = 2*i+1;
	int right = 2*i+2;
	
	if( left< n && arr[left] > arr[largest]) // if root node < left node then exchange their positions
	{
		largest = left;
	}
	if (right < n && arr[right] > arr[largest]) // if root node < right node then exchange their positions
	{
		largest = right;
	}
	
	if( largest!=i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr,n,largest);
	}
}

void heap_sort(int arr[], int n)    // function to do the main heap sort.
{
	for(int i=n/2-1; i>=0; i--)         // First build the max heap
	{
		heapify(arr,n,i);
	}
	
	for(int i=n-1; i>=0;i--)            // Then sort the array
	{
		swap(arr[0], arr[i]);           // Swap the first element and the last element and discard the last element from further consideration.
		heapify(arr, i, 0);             // Calling Heap sort for the reduced heap.
	}
}

void printarray(int arr[], int n)  // A function to display all the elements in an array
{
	for (int i=1;i<n; ++i)
	{
		cout<< arr[i] << ", ";
		
	}
}

int main()
{
	int n=100;               // Number of elements
	//srand(time(0)); // seed a random number
	int a[n];         // Initial array with given elements [1,2...100]
	int arr[n];       // Random permutation of the given array of elements.
	for(int i=1; i<=n; i++)
	{
		a[i]=i;        // [1,2...100]
	}
	for(int i=1;i<=n;i++)
	{
		int index = rand()%n;   // Generating random index
		arr[i] = a[index];      // shuffling the elements in the array 'a'
	}
	cout << "The random permutation of the given array is \n" << endl;
	printarray(arr,n);
	n = sizeof(arr)/sizeof(arr[0]); // Print the shufled array before being sorted
	heap_sort(arr,n);
	cout << "\n The array elements after Heap Sort \n" << endl;
	printarray(arr,n);              // Print the final array formed after undergoing heapsort
}



