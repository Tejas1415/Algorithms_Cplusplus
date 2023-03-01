/*
Homework 5 - Part 2
Question 2 (2 pt.) Write codes for Bellman-Ford algorithm. 
C++ implementation of the Bellman Ford Algorithm.
*/


#include <iostream>
#include<cstdlib>
using namespace std; 
  
// Structure to get the vertex, its destination and weight for each node
struct Edge 
{ 
    int src, dest, weight; 
}; 
  
// A structutre to represent the graph and its weighted direction.
struct Graph 
{ 
    int V, E;                 // V is the vertex and E is the number of edges
    struct Edge* edge;       // Array of edges.
}; 
  
struct Graph* createGraph(int V, int E)  // Generating graph with number of edges and vertices decided by the user.
{  
    struct Graph* graph = new Graph; 
    graph->V = V; 
    graph->E = E; 
    graph->edge = new Edge[E]; 
    return graph; 
} 
  
// Print one dimensional arrays.
void PrintArray1D(int dist[], int n) 
{ 
    cout << "\nDistance of the vertex from the source\n" << endl;
    for (int i = 0; i < n; ++i) 
        cout << i << "\t\t" << dist[i] << endl;
} 
  
// Function to detect negetive weight cycle, apply bellmanFord algorithm to find shortest path from source to all vertices.
void BellmanFord(struct Graph* graph, int src) 
{ 
    int V = graph->V; 
    int E = graph->E; 
    int dist[V]; 
  
    for (int i = 0; i < V; i++) // setting all distances to infinite to start off with the algorithm.
        dist[i]   = INT_MAX; 
        dist[src] = 0; 
  
    // Start relaxing all the edges step by step.
    for (int i = 1; i <= V-1; i++) 
    { 
        for (int j = 0; j < E; j++) 
        { 
            int u = graph->edge[j].src; 
            int v = graph->edge[j].dest; 
            int weight = graph->edge[j].weight; 
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
                dist[v] = dist[u] + weight; 
        } 
    } 
  
    // If the graph encounters negetive weight cycle, do the following.
    for (int i = 0; i < E; i++) 
    { 
        int u = graph->edge[i].src; 
        int v = graph->edge[i].dest; 
        int weight = graph->edge[i].weight; 
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
            printf("Graph contains negative weight cycle"); 
    } 
  
    PrintArray1D(dist, V); 
  
    return; 
} 
  
// Main part of the program.
int main() 
{ 
    
    int V = 5;  // V is the number of vertices and E is the number of edges
    int E = 8;   
    struct Graph* graph = createGraph(V, E); 
  
    // Create the inout graph.
    graph->edge[0].src = 0; 
    graph->edge[0].dest = 1; 
    graph->edge[0].weight = -1; 
  
  
    graph->edge[1].src = 0; 
    graph->edge[1].dest = 2; 
    graph->edge[1].weight = 4; 
  
   
    graph->edge[2].src = 1; 
    graph->edge[2].dest = 2; 
    graph->edge[2].weight = 3; 
  
  
    graph->edge[3].src = 1; 
    graph->edge[3].dest = 3; 
    graph->edge[3].weight = 2; 
  

    graph->edge[4].src = 1; 
    graph->edge[4].dest = 4; 
    graph->edge[4].weight = 2; 
  
 
    graph->edge[5].src = 3; 
    graph->edge[5].dest = 2; 
    graph->edge[5].weight = 5; 
  

    graph->edge[6].src = 3; 
    graph->edge[6].dest = 1; 
    graph->edge[6].weight = 1; 
  

    graph->edge[7].src = 4; 
    graph->edge[7].dest = 3; 
    graph->edge[7].weight = -3; 
    
    // Apply Bellanford algorithm over the above created graph.
    BellmanFord(graph, 0); 
  
    return 0; 
}
