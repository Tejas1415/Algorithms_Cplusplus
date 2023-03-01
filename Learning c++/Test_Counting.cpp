#include<iostream>
using namespace std;
int k=0;

void Counting_Sort(int A[],int B[],int n)    
{
	int c[k];
	for(int i=0;i<k+1;i++)
	{
		c[i]=0;
	}
	for(int j=1;j<=n;j++)
	{	
		c[A[j]]++;			    
	}
	for(int i=1;i<=k;i++)
	{
		c[i]+=c[i-1];            
	}
	for(int j=n;j>=1;j--)
	{
		B[c[A[j]]]=A[j];          
		c[A[j]]=c[A[j]]-1;		  
	}
}
int main()
{
	int n;
	cout<<"Enter the size of the array :";
	cin>>n;
		
	int A[n],B[n]; 
	
	for(int i=1;i<=n;i++)        
	{
		cin>>A[i];
		if(A[i]>k)
		{
			k=A[i];              
		}
	}
	Counting_Sort(A,B,n);        
	
	for(int i=1;i<=n;i++)       
	{
		cout<<B[i]<<" ";
	}
	
	cout<<endl;
	return 0;
}
