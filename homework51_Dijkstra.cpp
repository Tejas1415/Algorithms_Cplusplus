/* Algorithms - Homework 5 
Write codes for Dijkstra’s algorithm using unsorted array for priority Q.
C++ implementation of Dijkstra's algorithm with Adjacency Matrix input.
*/
   
#include <iostream> 
#include <cstdlib> 
using namespace std;
   
#define V 9          // Define constant number of vertices 
   
// Funtion to extract minimum distance in the distance array.
int DistanceMinimum(int dist[], bool sptSet[]) 
{ 
   // Initialize min value to be infinity to compare with others
   int min = INT_MAX, minIndex; 
   
   for (int v = 0; v < V; v++) 
     if (sptSet[v] == false && dist[v] <= min) 
         min = dist[v], minIndex = v; 
   
   return minIndex; 
} 
   
// A function to print the constructed distance array 
int printArray1D(int dist[], int n) 
{ 
   printf("\n Source to vertex distance\n"); 
   for (int i = 0; i < V; i++) 
      cout << i << "\t\t" << dist[i] << endl; 
} 
   
// Main function to perform dijkstra's Algorithm over the adjecency matrix
void dijkstraAlgorithm(int graph[V][V], int src) 
{ 
     int dist[V];     
     bool sptSet[V]; // 1 if the dist is shortest path, else it is not the shortest path.
   
     // Declare all elements in dist matrix to be infinite for further manipulations.
     for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
   
     dist[src] = 0; 
   
     // Find shortest path for all vertices 
     for (int count = 0; count < V-1; count++) 
     { 
       int u = DistanceMinimum(dist, sptSet); 
       sptSet[u] = true;  // That particular vertex is used and not to be processed for further iterations.

       // Update new distances. 
       for (int v = 0; v < V; v++) {
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX  && dist[u]+graph[u][v] < dist[v]) 
            dist[v] = dist[u] + graph[u][v]; 
     } 
}
     // print the constructed distance array 
     printArray1D(dist, V); 
} 
   
// driver program to test above function 
int main() 
{ 
   
   // Provide the input in terms of adjacency matrix
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                      {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                      {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                      {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                      {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                      {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                      {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                      {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                      {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                     }; 
   
    dijkstraAlgorithm(graph, 0);  // Applying Dijkstra's Algorithm over the adjacency matrix.
    return 0; 
    system("pause");
} 
