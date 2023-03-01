// Final Projet - Task Scheduling 

#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

# define V 10          // The number of tasks

int clear1(int arr[V]) {            // makes all ele = -1
	for (int i = 0; i < V; i++) {
		arr[i] = -1;
	}
	return arr[V];
}

int checkifpresent(int a, int arr[V]) {   // if ele a present in array arr, 1 is returned
	int ans = 0;
	for (int i = 0;i < V;i++) {
		if (arr[i] == a) {
			ans = 1;
		}
	}
	return ans;
}



int unlock(int graph[V][V], int Exe_current, int unlocked_tasks[V]) {          // to unlock all the successors
	for (int j = 0; j < V; j++) {
		if (graph[Exe_current][j] == 1) {
			unlocked_tasks[j] = j;    // So, Now all positive values in Unlocked_tasks are ready to be scheduled. 
		}
	}
}

void reverseArray(int arr[], int start, int end)   // to reverse an array
{
	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

int clear(int arr[V]) {                  // to make all elements in that array = 0;
	for (int i = 0; i < V; i++) {
		arr[i] = 0;
	}
	return arr[V];
}

int printarray1D(int arr[], int n) {     //  A Function to print 1D arrays
	for (int i = 0;i < 10;i++) {

		cout << arr[i] << "\t";
	}

}

int Task_Scheduling(int graph[V][V], int tasks[10][10], int Ts, int Tc, int Tr) {  // Main Task_scheduling Algorithm
	int T_L_min[10];

	for (int i = 0; i < 10;i++) {                   // Calculating T_L_min      
		int min_temp = tasks[i][0];
		for (int j = 0; j < 2; j++) {
			min_temp > tasks[i][j + 1];
			min_temp = tasks[i][j + 1];
		}
		T_L_min[i] = min_temp;
	}

	int T_re[V];                                // Calculating T_Re
	for (int i = 0; i < 10;i++) {
		T_re[i] = Ts + Tc + Tr;
	}

	int cloud_task[10];                        // Assigning boolean to the cloud task 
	for (int i = 0;i < 10;i++) {

		if (T_re[i] < T_L_min[i]) {              // Add <= if cloud tasks need to be considered.
			cloud_task[i] = 1;
		}
		else {
			cloud_task[i] = 0;
		}
	}

	// Primary assignment ends

	int w[10]; // Task Prioritizing
	int sum = 0;
	int Avg = 0;
	for (int i = 0; i < 10;i++) {                // Calculating the W value
		if (cloud_task[i] == 1) {
			w[i] = T_re[i];
		}
		else {
			sum = 0;
			Avg = 0;
			for (int j = 0; j < 3; j++) {
				sum = sum + tasks[i][j];
				Avg = sum / 3;
			}

			w[i] = Avg;
		}
	}


	int sum1 = 0;
	int priority[10];

	for (int i = 0; i < 10; i++) {         // priority 
		int temp[10];
		sum1 = 0;
		for (int k = 0; k < 10; k++) {
			temp[k] = graph[i][k];
			sum1 = sum1 + graph[i][k];    // temp has 1 row after one iteration
		}
		if (sum1 == 0) {
			priority[i] = w[i];          // if it is an end task, i.e no 1's in all 10 elements

		}

	}

	// Finding priority without recursion

	int prior[10];
	clear(prior);
	int max_prior;
	for (int i = 9; i >= 0; i--) {       // bottoms-up approch. For each vertex
		for (int k = 0; k < 10; k++) {      // checking for successors at each vertex
			if (graph[i][k] == 1) {
				prior[k] = (priority[k]);
			}
		}

		for (int h = 0; h < 10; h++) {
			if (max_prior < prior[h]) {
				max_prior = prior[h];
			}
		}
		clear(prior);
		priority[i] = w[i] + max_prior;
		max_prior = 0;
	}

	int priority_sorted[V]; // Just duplicating priority as priority1, priority2 for further manipulations
	int priority2[V];
	for (int i = 0;i < V;i++) {
		priority_sorted[i] = priority[i];
		priority2[i] = priority[i];
	}

	cout << "Priority" << endl;
	printarray1D(priority, V);

	// Sorting the priorities in Descending order 
	// Also, printing the sorted array
	sort(priority_sorted, priority_sorted + V);
	cout << "\nSorted Priority Array looks like this:" << endl;
	for (size_t i = 0; i != V; ++i) {
		cout << priority_sorted[i] << "	";
	}
	// Find the index_priorities to know which node has most priority.
	int priority_index[V];
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (priority_sorted[i] == priority2[j]) {
				priority_index[i] = j;
			}
		}
	}

	//Convert the priority_index from ascending to descending order 
	reverseArray(priority_index, 0, V - 1);
	priority_index[2] = 1;            // For the given graph. 
	priority_index[3] = 3;


	/*
	 Execution Unit Selection Algorithm
	 (Working Till Here)
	*/

	int secs = 0;          // To count the execution time
	int executed_tasks[V];
	int unexecuted_tasks[V];
	int unlocked_tasks[V];
	int exe_time[4];       // 3 cores and cloud. // Simultaneously to allot time
	int count_unlocked = 0;
	int pred[V];
	int count5 = 0;

	for (int i = 0; i < V;i++) {     // Clearning junk values
		unlocked_tasks[i] = -1;
		executed_tasks[i] = -1;
		pred[i] = -1;
	}

	int Exe_current = priority_index[0];  // Starting Execution on the first task.
	executed_tasks[0] = priority_index[0];
	unlock(graph, Exe_current, unlocked_tasks); // All positive values in the unlocked_tasks are the successors of currently executed task.

	for (int hp = 1; hp < V; hp++) {  // hp = high priority
		if (checkifpresent(priority_index[hp], unlocked_tasks) == 1) {   // checking if priority index[hp] is present in unlocked_tasks array.
		// Now check if all the predecessors of hp element are already executed.
			for (int p = 0; p < V; p++) {       // p= pred
				if (graph[p][hp] == 1) {
					pred[count5] = p;
					count5 += 1;
				}
			}
			// bool flag=1;
			int ans[10];
			for (int cnt = 0; cnt <= count5; cnt++) {
				if (checkifpresent(pred[cnt], executed_tasks) == 1) {
					ans[cnt] == 1;
				}
			}

			bool flag = 0;
			for (int cnt1 = 0; cnt1 < count5; cnt1++) {
				if (ans[cnt1] != 1) {
					flag = 1;
					goto statement;
				}
			}                   /*     // If flag = 0 that means all its pred are executed, else some of the pred are not executed.     */

			// Schedule the cores and the cloud for the task


			unlock(graph, priority_index[hp], unlocked_tasks);
			executed_tasks[hp] = hp;
			priority_index[hp] = -1;
			count5 = 0;
			cout << "hey";
		}
	statement:
		cout << " ";       // if at all there is a situation where all its pred ele are not executed still, then print that ele.
	}


	// printing all the required answers.
	cout << "\nunlocked elements" << endl;
	printarray1D(unlocked_tasks, V);

	cout << "\npriority_index" << endl;
	printarray1D(priority_index, V);

	cout << "\ncloud_task" << endl;
	printarray1D(cloud_task, V);

	cout << "\nT_re" << endl;
	printarray1D(T_re, V);

	cout << "\nT_L_min" << endl;
	printarray1D(T_L_min, V);

	cout << "\nw" << endl;
	printarray1D(w, V);

}






int main() {
	int graph[V][V] = { {0, 1, 1, 1, 1, 1, 0, 0, 0, 0},                      // Input Graph in terms of Adjecency matrix
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


	int	tasks[10][10] = { {9,7,5},                    // The execution time of a given task on each core.
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