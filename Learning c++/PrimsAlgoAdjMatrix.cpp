/*
Prims Algorithm: Part 1
Question 1 (5 pt.) MST: Write codes for Prim’s algorithm.
Version 1: use adjacency matrix to present graph and use unsorted array for priority queue Q.

For a new input, change the number of vertices in #define and manually add nodes in main() part of the program.
*/

#include<iostream>
#include<cstdlib>
using namespace std;

# define V 9                  // Change the constant based on the number of vertices present in Input Graph.

int extract_min_key(int key[], bool current_tree_set[]){ // V is the total number of vertices in the given graph
	int min = INT_MAX;        // assigns the max value a  int can take +2147483647.
	int min_index;           // INT_MAX is chosen as a value ~ to infinity.
	
	for(int i=0; i< V; i++){      
		if(current_tree_set[i]== false && key[i]< min){  // current tree set checks if the node already exists or its a new node. If new then loop excegutes.
			min = key[i]; min_index = i;           // if index value of graph is less then the initial value, then update key value with the least value.
		}
	}
	return min_index;
}

int Print_Tree(int parent[], int n, int graph[V][V]){   // A function to print the Minimum Spanning Tree.
	cout << "Connection" << "\t" << "Weight of the connection" << "\n" << endl;
	for(int i=1; i<V; i++){
		cout << parent[i] << " - " <<  i << "\t\t\t" << graph[i][parent[i]] << endl; 
	}
}

void Prims_Algorithm(int graph[V][V]){
	int parent[V];              // Array to store the tree 
	int key[V];                // min value is substituted and later chosen for MST.
	bool current_tree_set[V]; //  To check if the Vertex is already in the developing MST. If exists, then the loops breaks and next node is chosen.
	
// Initialize all the key values to Infinity (INT_MAX). Except 1 element to start off with the algorithm.
for (int i = 0; i < V; i++){
        key[i] = INT_MAX, current_tree_set[i] = false; 	
}

// Now, include the first vertex in the MST with a key value less than 
key[0]=0;
parent[0]= -1; // Initialise the first node as the root/ element.

for(int j=0; j< V-1; j++){                         // iterate through all vertices in the input graph
	int u=extract_min_key(key, current_tree_set);  // Extract the node with least key value
	current_tree_set[u] = true;                    // Update the presence of that node in the current MST set
	
	
	/* Now we need to check 3 conditions to update each node
	1. Check if the connection exists from the adjecency matrix, if value 0, then it does notexists
	2. Check if the node is already there in the MST, if 0 it does not exist
	3. Check if the min value is smaller than key value.
	If all 3 conditions are satisfied then update new element, parent node and the new key value for corresponding vertex.
	*/
	
	for (int v=0; v<V; v++){
		if (graph[u][v] && current_tree_set[v] == false && graph[u][v] < key[v]){
			parent[v] = u; key[v] = graph[u][v];
		}
	}
}

Print_Tree(parent, V, graph);
	
}

int main()
{
	
// Each time Change the V value in "#define" accordingly and add the new adjecency matrix as the input.
int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                   {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                   {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                   {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                   {0, 0, 0, 9, 0, 10, 0, 0, 0},
				   {0, 0, 4, 14, 10, 0, 2, 0, 0},
				   {0, 0, 0, 0, 0, 2, 0, 1, 6},
				   {8, 11, 0, 0, 0, 0, 1, 0, 7},
				   {0, 0, 2, 0, 0, 0, 6, 7, 0},
				   }; 

Prims_Algorithm(graph);
}
