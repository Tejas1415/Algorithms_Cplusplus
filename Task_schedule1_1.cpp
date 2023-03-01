// Final Projet - Task Scheduling
 
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
 
# define V 10          // The number of tasks
 
// Try to find predecessors for an exit task
vector<int> findPred (int graph[V][V], int a){
    vector<int> parent;
    //int parent[V];
    for (int i = 0; i < V; i++){
        if (graph[i][a] == 1){
            parent.push_back(i);
            //parent[i] = i;
        }
    }
    return parent;
}
 
int Priority(){
 
}
 
/*
// Graph
struct EDGES {
    int from, to;
  };
 
 
   class GRAPH{
       public:
       vector<vector<int> > adjList;
 
       GRAPH(vector<EDGES> const &edge, int n){
            adjList.resize(n);
            for (auto  &i: edge){
                adjList[i.from].push_back(i.to);
            }
       }
 
   };
 
 
 
int find_priority(int temp[10], int w[10]){
    int priority[10];
    for(int i=0; i<10;i++){
        if temp[i]
    }
}
*/
/*
int findParent(int graph[V][V], int exitTask){
    vector<int> parent;
   //int temp = 0;
    for(int i = 0; i < 10; i++){
       // for (int j = 0; j<V; j++){
          if (graph[i][exitTask]== 1){
                //temp = i;
                parent.push_back(i);
          }
 
       // }
 
   }
 for (auto k: parent){
    cout << "Parent " << k << endl;
 }
 return parent;
}
*/
int printarray1D(int arr[], int n){     //  A Function to print 1D arrays
    for(int i=0; i < n; i++){
 
        cout << arr[i]<< "\t";
    }
}
 
int Task_Scheduling(int graph[V][V], int tasks[10][10], int Ts, int Tc, int Tr){  // Main Task_scheduling Algorithm
    int T_L_min[V];
 
    for(int i = 0; i < V; i++){                   // Calculating T_L_min
            int min_temp = tasks[i][0];
            for (int j = 0; j <2; j++) {
            min_temp > tasks[i][j+1];
            min_temp =  tasks[i][j+1];
        }
        T_L_min[i] = min_temp;
    }
 
int T_re[10];                                // Calculating T_Re
    for(int i=0; i < V;i++){
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
 
//int w[10]; // Task Prioritizing
int *w = new int[V];
    for (int i = 0; i < V; i++)
    {
      w[i] = 0;
    }
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
int exitTask = 0;
for(int i=0; i<10; i++){         // priority
    int temp[10];
    sum1=0;
    for(int k=0; k<10; k++){
        temp[k] = graph[i][k];
        sum1 = sum1+graph[i][k];
    }
    if(sum1 == 0){
        priority[i]= w[i];
        exitTask = i;
 
    }
 
    //else
    //{
 
       //find_priority(temp,w);
    //}
 
}
vector<int> result;
result.clear();
for(int i = 0; i<V; i++){
    result = findPred(graph,i);
    }
 
for (auto z: result){
    cout << "result " << z << "\t";
    }
/*
for (int i = 0; i<= parent.size(); i++){
    priority[i] =
}
for (int i = exitTask; i >=0; i--){
    priority[i-1] = w[i-1]+ priority[i];
    cout<< "\n" << priority[i];
}
cout<<"\n priority"<<endl;
    printarray1D(priority, V);
/*
   vector<int> parent;
   //int temp = 0;
    for(int i = 0; i < 10; i++){
         if (graph[i][exitTask]== 1){
                parent.push_back(i);
          }
 
 
   }
for (auto k: parent){
    cout << "Parent " << k << endl;
 }
vector<int> children;
 for(int i = 0; i < parent.size(); i++){
    for (int j = 0; j < 10; j++){
        if (graph[parent[i]][j]== 1){
            children.push_back(j);
          }
 
        }
for (auto s: children){
    cout << "children " << s << endl;
 }
 
 
   }
*/
 
//vector<int> ParentOfExit;
//ParentOfExit = findXXX (graph, exitTask);
 
//int succ[10];
//  int count1=0;
//  for(int i=0; i<10;i++){
//      if(int temp[i]==1){
//          succ[count1] = i;  // storing the location where the element is 1
//          count1 = count1 + 1;
//      }
//  }
 
    cout<<"\n w"<<endl;
    printarray1D(w, V);
 
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
 
 
 
int tasks[10][10] =  {{9,7,5},                    // The execution time of a given task on each core.
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
}
 
 
/*
0 1 1 1 1 1 0 0 0 0                      // Input Graph in terms of Adjecency matrix
0 0 0 0 0 0 0 1 1 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 1 1 0
0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0
 
 
    */
