/*
Radix sort
Write codes for radix sort: use counting sort for decimal digits from
the low order to high order. The input array is A = {329, 457, 657, 839, 436, 720, 353}.
*/

#include<iostream>

using namespace std;

int max_in_array(int arr[], int n)  // To find the maximum element in the array to get the max digits a element has in input array
{
	int max = arr[0];      
	for(int i=1;i<n;i++)
	{
		if (arr[i]>max)
		{
			max = arr[i];
		}
	}
	return max;
}

// Counting sort over the desired digits in the input array

void counting_sort(int arr[],int n, int e)
{
	int c[10] = {0};              // Intialise a cumuliative frequency count array as null, from 0..9 i.e 10 digits
	int output[n];               // To store the sorted output 
	
	for (int i = 0; i < n; i++)
	{
		c[(arr[i] / e) % 10]++;
}
	// Calculating their cumulative count.
	for (int i = 1; i < 10; i++)
	{
		c[i] += c[i-1];
}
	// Inserting the corresponding digits from 1 to the max digits present in max
	for (int i = n - 1; i >= 0; i--)
	{
		output[c[(arr[i] / e) % 10] - 1] = arr[i];
		c[(arr[i] / e) % 10]--;
	}
 
	for (int i = 0; i < n; i++)
	{
	
		arr[i] = output[i];
}}

// Function to perform Radix sort for ith digit where i is from 1 to the maximum num of digits in max

void radix_sort(int arr[],int n)
{
	int e, max;
	max = max_in_array(arr,n);
	
	// Now check the number of digits max has, and then perform counting sort over each of the corresponding digit numbers.
	
	for(e=1; max/e > 0; e = e*10)
	{
		counting_sort(arr,n,e);
	}
}

void printarray(int arr[], int n)
{
	for(int i=0;i<n; ++i)
	{
		cout << arr[i] << "  ";
	}
}

// Main part of the program

int main()
{
	int n,i;
	cout << "Enter the number of elements in the array" << endl;
	cin >> n;
	
	int arr[n];            // Input matrix         
	for(i=0;i<n;i++)       // Take in the elements from the user
 	{
		cin >> arr[i];
	}
	
	cout << "Elements before sorting" << endl;
	printarray(arr,n);   // print elements in the array before radix sort
	radix_sort(arr,n);     // Perform radix sort
	cout << " \n Elements after going through radix sort" << endl;
	printarray(arr,n);// print elements in the array after radix sort
	
}

