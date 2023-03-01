#include <iostream>
#include<ctime>
#include<stdlib.h>
#include<conio.h>
#include <cstdlib>

using namespace std;
void Insertion(int[], int);
void Merge(int, int, int[]);
void merge_array(int,int,int,int, int[]);

int main(){
	int arr[100], arr1[100];
	int n;
	
	// create an array in reverse sorted order of size n
	cout << "Enter value of n" << endl;
	cin >> n;
	
	for(int i=n; i>0; i--)
	{
		arr[i] = i-1;
		arr1[i] = i-1; 
	}
	for (int i = n ; i > 0; i--) 
	{
    cout << arr[i];                      // array created in the reverse order.
   // cout << arr1[i];
}

// calculating the time for insertion sort
clock_t begin1 = clock();
Insertion(arr, n);
clock_t stop1 = clock();
double elapsed_Insertion_sort_secs = double(stop1 - begin1) / CLOCKS_PER_SEC;
cout << "\n elapsed_Instertion_sort_secs = " << elapsed_Insertion_sort_secs << endl;

// calculating time for merge sort

clock_t begin2 = clock();
Merge(0,n-1, arr1);
clock_t stop2 = clock();
double elapsed_Merge_sort_secs = double(stop2 - begin2)/ CLOCKS_PER_SEC;
cout << "\nSorted Data :";
    for (int i = 0; i < n; i++) {
        cout << "\t" << arr1[i];
    }
cout << "\n elapsed_Merge_sort_secs = " << elapsed_Merge_sort_secs << endl;
getch();
}


