/*
Randomised Quick Sort
Write codes for randomized quicksort. You may need rand()
to generate random numbers. Run the randomized quicksort 5 times for input array A = {1, 2, 3, …, 99,
100} and report the 5 running times.
*/

#include<iostream>
#include<cstdlib>
#include<time.h>
#include<sys/time.h>

using namespace std;
int PARTITION(int [],int ,int );
void Randomised_quick_sort(int [],int ,int);
int Randomised_Partition(int [],int,int);

	
int main()
{
	struct timeval start;
	struct timeval end;
	gettimeofday(&start,NULL);
	clock_t t1, t2;
	int n=100;                                               // number of elements in the array
	int a[n];
	cout <<"Enter the n value \n n=99" << endl;
	for (int i=1; i<=n;i++)
	{
		a[i]=i;                                      // Given input array
	}
	cout <<"sorting the given input array \n" << endl;       
	int p=1, r=n;                                           // 'p' is index of first element 
	//struct timeval end;                                   // 'r' is the index of last element
	//t1 = clock();                                            // number of clicks per second            
	//gettimeofday(&start,NULL);
	Randomised_quick_sort(a, p, r);                         // call the function to sort the array
	gettimeofday(&end,NULL);                                         // time taken for radix sort
	cout<<"Resultant array after sorting"<<endl;            // Once sorted print the array
	 for(int i=1;i<=n;i++)
   {
       cout<<a[i] << ", ";
   }
   	gettimeofday(&end,NULL);
   //double d = 1000*(t2-t1) / CLOCKS_PER_SEC;
   cout <<  "\n time: " << end.tv_usec-start.tv_usec<< "us";
     return 0;
     
}

void Randomised_quick_sort(int a[], int p, int r)
{
	int q;                                              // A random index value inbetween p and r
	if (p<r)
	{
		q = Randomised_Partition(a,p,r);                // Find a random value 'q' in between p and r
		Randomised_quick_sort(a,p,q-1);                 // Now sort the array untill pivot element seperatly and array after disparetly.
		Randomised_quick_sort(a,q+1,r);                 
	}
}
int Randomised_Partition(int a[], int p, int r)
{
	int i= p+rand()%(r-p+1);
	int temp;
	temp=a[r];                                         // Swap the elements 
    a[r]=a[i];
    a[i]=temp;
    return PARTITION(a,p,r);
}
int PARTITION(int a[], int p, int r)                 // Partition again and again untill we achieve the final sorted list.
{
	int temp,temp1;
        int x=a[r];
        int i=p-1;
        for(int j=p;j<=r-1;j++)
        {
            if(a[j]<=x)
            {

                i=i+1;
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp1=a[i+1];
        a[i+1]=a[r];
        a[r]=temp1;
        return i+1;
  }
  
