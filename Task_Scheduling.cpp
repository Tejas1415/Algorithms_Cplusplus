// Final Projet - Task Scheduling 

#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

# define V 10          // The number of tasks


int clear(int arr[V]){
	for (int i=0; i<V; i++){
		arr[i] = 0;
	}
	return arr[V];
}


/*
int find_priority(int vertex,int graph[V][V], int w[V])
{
	//vector <int> priorities;                   
	//vector<int> succ; 
	int maximum = 0;
	int new_value;
	if(vertex == 9){                 // assign the answers for all known exit tasks 
		return w[9];
	}
	else
	{
		for(int i=0; i<V; i++){       // for non_exit tasks, know the location of the successors
			if(graph[vertex][i] == 1){
				//succ.push_back(i);
				//priorities.push_back(find_priority(i, graph, w)); 
				new_value = find_priority(i, graph, w);
				
				if (new_value > maximum)
				{
					maximum = new_value;
				}
			}
		}
		
		return w[i] + maximum;
	  	// for each successor find the priority
	//	for(int i = 0; i<=succ.size(); i++){
	//		int a = succ[i];
	//		priorities.push_back(find_priority(a, graph, w));  // recursively calculate
			
			
				
	//	}
		//maximum = *max_element(priorities.begin(), priorities.end());
		
	/*	//return max_element(priorities.begin(), priorities.end());
		maximum = priorities[0];
		for(int i=1; i<=priorities.size(); i++){
			if(priorities[i] > maximum){
				maximum = priorities[i];
			}
		}
		
	//	return maximum;        // return the max priority of the successors 
	}
}

*/

int printarray1D(int arr[],int n){     //  A Function to print 1D arrays
	for(int i=0;i<10;i++){
	
		cout <<arr[i]<< "\t";
	}
	
}

int Task_Scheduling(int graph[V][V], int tasks[10][10], int Ts, int Tc, int Tr){  // Main Task_scheduling Algorithm
	int T_L_min[10];		
		
	for(int i=0; i<10;i++){                   // Calculating T_L_min      
		    int min_temp = tasks[i][0];
            for (int j = 0; j <2; j++) {
            min_temp > tasks[i][j+1];
            min_temp =  tasks[i][j+1];
        }
        T_L_min[i] = min_temp;
	} 
	
int T_re[V];                                // Calculating T_Re
    for(int i=0; i<10;i++){
		T_re[i] = Ts+Tc+Tr;
	}

int cloud_task[10];                        // Assigning boolean to the cloud task 
for(int i=0;i<10;i++){

	if(T_re[i]<= T_L_min[i]){
		cloud_task[i]=1;
	}	
	else{
		cloud_task[i]=0;
	}
}

// Primary assignment ends

int w[10]; // Task Prioritizing
int sum=0;
int Avg=0;
for(int i=0; i<10;i++){                // Calculating the W value
	if(cloud_task[i] == 1){
		w[i]= T_re[i];
	}
	else{
		sum=0;
		Avg=0;
		for(int j=0; j<3; j++){
		   	sum = sum + tasks[i][j];
		   	 Avg = sum/3;
		}
	   
		w[i] = Avg;
	}
}


int sum1=0;
int priority[10];

for(int i=0; i<10; i++){         // priority 
	int temp[10];
	sum1=0;
	for(int k=0; k<10; k++){
		temp[k] = graph[i][k];
		sum1 = sum1+graph[i][k];    // temp has 1 row after one iteration
	}
	if(sum1 == 0){
		priority[i]= w[i];          // if it is an end task, i.e no 1's in all 10 elements

	}
	/*
	else
	{
		
	   find_priority(graph,temp,w);	
	}
	*/
}

// Finding priority without recursion

int prior[10];
clear(prior);
int max_prior;
for(int i=8; i>=0; i--){       // bottoms-up approch. For each vertex
	for(int k=0; k<10; k++){      // checking for successors at each vertex
		if(graph[i][k] == 1){
			prior[k] = (priority[k]);
		}
	}
	
	for(int h=0; h<10; h++){
		if(max_prior < prior[h]){
			max_prior = prior[h];
		}
	}
	clear(prior);
	priority[i] = w[i] + max_prior;
    max_prior=0;
}



/*
for(int i=0; i<=V-2; i++){
	priority[i] = find_priority(i, graph, w);  // calculating the priorities
}
*/

	
	cout << "\nPriority" << endl;
	printarray1D(priority, V);

    cout<<"\ncloud_task"<<endl;
	printarray1D(cloud_task, V);
	
	cout<<"\nT_re"<<endl;
	printarray1D(T_re, V);
	
	cout<<"\nT_L_min" << endl;
	printarray1D(T_L_min, V);
	
	cout<<"\nw" << endl;
	printarray1D(w, V);
	
}






int main(){
	int graph[V][V] = {{0, 1, 1, 1, 1, 1, 0, 0, 0, 0},                      // Input Graph in terms of Adjecency matrix
                       {0, 0, 0, 0, 0, 0, 0, 1, 1, 0}, 
                       {0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, 
                   	   {0, 0, 0, 0, 0, 0, 0, 1, 1, 0}, 
                       {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
				       {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
				       {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
				       {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
				       {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
				       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				       }; 
	
	
int	tasks[10][10] =  {{9,7,5},                    // The execution time of a given task on each core.
	                  {8,6,5},
					  {6,5,4},
					  {7,5,3},
					  {5,4,2},
					  {7,6,4},
					  {8,5,3},
					  {6,4,2},
					  {5,3,2},
					  {7,4,2},
					  };
    
    int Ts = 3;                                   // Sending, Cloud and Receiving Time 
    int Tc = 1;
    int Tr = 1;
    
Task_Scheduling(graph, tasks, Ts, Tc, Tr);
getchar();
system("pause");
}
