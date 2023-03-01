#include <iostream>
#include <stdio.h> 
#include <limits.h> 

void output_to_console(int distance[], int vertices) 
{ 
  int src = 0; 
  printf("Vertex \t Distance from Source\n"); 
  for (int i = 1; i < vertices; i++){
      printf("%d \t %d\n", i, distance[i]);       
    } 
}


int minimun_distance_vertex(int distance[], bool shortest_path[], int vertices) 
{ 
	
  int min = INT_MAX, min_index; 
  for (int v = 0; v < vertices; v++) {
    if (shortest_path[v] == false && distance[v] <= min) {
      min = distance[v], min_index = v;
    }
}

  return min_index; 
} 


void dijkstra(int** graph, int src, int vertices) 
{ 
	
  int predecessor[vertices]; 
  int distance[vertices]; 
  bool shortest_path[vertices]; 

  for (int i = 0; i < vertices; i++){
    predecessor[0] = -1; 
    distance[i] = INT_MAX; 
    shortest_path[i] = false; 
  } 

  distance[src] = 0; 
  for (int count = 0; count < vertices - 1; count++){
    int u = minimun_distance_vertex(distance, shortest_path, vertices); 
    shortest_path[u] = true; 
    for (int v = 0; v < vertices; v++) {
      if (!shortest_path[v] && graph[u][v] && distance[u] + graph[u][v] < distance[v]){
	predecessor[v] = u; 
	distance[v] = distance[u] + graph[u][v]; 
      }
    }
  } 

  output_to_console(distance, vertices); 
} 


int main() 
{

  int source;
  int vertices;

  std::cout<<"Enter the number of vertices: ";
  std::cin>>vertices;

  int **_graph = new int*[vertices];

  for(int i=0; i<vertices; i++){
    _graph[i] = new int[vertices];
  }

  
  for(int i=0; i<vertices; i++){
    std::cout<<"Enter the connections for vertex "<<i<<" (Please separate weights by a space): ";
    for(int j=0; j<vertices; j++){
      std::cin>>_graph[i][j];
    }
  }

  std::cout<<"Enter the source vertex: ";
  std::cin>>source;

  dijkstra(_graph, source, vertices);
  
}
