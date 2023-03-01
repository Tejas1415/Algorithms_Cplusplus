#include<iostream>
#include<algorithm>
using namespace std;

int max_elements(int arr[], int n)
{
	int max_ele = arr[0];
	for(int i=1; i<n; i++){
		if(max_ele<arr[i]){
			max_ele = arr[i];
		}
	}
	return max_ele;
}

void printarray1D(int arr[], int n)  // A function to print the arrays
{
	for(int i=0;i<n;i++)
	{
		cout << arr[i] <<", ";
	}
}
	
int main(){

int x[1]= {109};   // x[this values is number of elements = 4]
//printarray1D(x,5);      // send n element indices to print
x[1]=3;
int l= max_elements(x,1);
//cout << l << endl;
int n;
cout << "enter n value" << endl;
cin >> n;

int A[n],B[n];
for(int i=0; i<n; i++){
	cin >> A[i];
	B[i] = A[i];
}

cout << "elements in A are" << endl;
printarray1D(A,n);

cout << "elements in B are" << endl;
printarray1D(B,n);

{
	int min = INT_MAX;             // assigns the max value a  int can take +2147483647.
	cout << "Printing Min" << endl;
	cout<< min<< endl;
}
}























}
