#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

# define V 10          

int main(){
	vector<int>hi;
	hi.push_back(10);
	hi.push_back(1);
	hi.push_back(5);
	hi.push_back(1);
	
	int maximum = *max_element(hi.begin(),hi.end());
	cout << "maximum = " << maximum << endl;
	hi.clear();
	cout<< "\nVector clear testing = " << hi[0] << " hi[1] = " << hi[1];
	
	hi.push_back(33);
	cout<< "\nVector clear testing = " << hi[0] << " hi[1] = " << hi[1];
	
int a = 3;
int b = 4;
float c = (float)a/(float)b;
//cout << "C value is as follows: " << c << endl;
}
