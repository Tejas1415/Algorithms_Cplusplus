/*
Prims Algorithm: Part 2
Question 1 (5 pt.) MST: Write codes for Prim’s algorithm.
Version 1: use adjacency matrix to present graph and use unsorted array for priority queue Q.
Version 2: use adjacency lists to present graph and use heap for priority queue Q. - The solution is as follows-
*/
 
#include <iostream>
#include <cstdlib>
using namespace std;
  // Struct can store mixture of datatypes arr[name,age,float]. 
   // Struct is always declared outside the main().
    // struct user bucky where user is a structure in which bucky is a person.  bucky.age can be accessed using (.) operator
 
struct AdjListNode { 
    int destination; 
    int weight; 
    struct AdjListNode* next; 
}; 
  
// A structure to represent an adjacency list 
struct AdjList { 
    struct AdjListNode* head; // pointer to head of list 
}; 

// Another structure to represent the Graph. A graph is an array of adjecency lists.
struct Graph { 
    int V; 
    struct AdjList* array; 
}; 


/*
IMPORTANT - The members of variables can be accessed by the following in c++
-> for accessing object member variables and methods via pointer to object
. for accessing object member variables and methods via object instance
:: for accessing static variables and methods of a class/struct or namespace. 
   It can also be used to access variables and functions from another scope 
   (actually class, struct, namespace are scopes in that case)
*/


  
//Creating a new adjecency list node.
struct AdjListNode* newAdjListNode(int destination, int weight) 
{ 
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));  // Allocating memory to create a new adjecency list node
    newNode->destination = destination; // Accessing the parameters of the list and updating them.
    newNode->weight = weight; 
    newNode->next = NULL; 
    return newNode; 
} 
  
// creating a structure for the input graph of V vertices.
struct Graph* createGraph(int V) 
{ 
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph)); // allocating memory block. Allocates size bytes of uninitialized storage. 
    graph->V = V; // Updating the vertices in the input graph.
  
    // Creating an array of size V, to store the adjacency lists.
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList)); 
  
    // Assign the Head of the array to a Null value.
    for (int i = 0; i < V; ++i) 
        graph->array[i].head = NULL; 
  
    return graph; 
} 
 
// A Function to add connection between vertices in the graph with the user specified weights. 
void addEdge(struct Graph* graph, int src, int destination, int weight) 
{ 
    // Connections are made from source to destination
    struct AdjListNode* newNode = newAdjListNode(destination, weight); 
    newNode->next = graph->array[src].head;  // (.) dot opetaror to acess the elements in the structure
    graph->array[src].head = newNode; 
  
    // Since graph is undirected, add an edge from dest to src also 
    newNode = newAdjListNode(src, weight); 
    newNode->next = graph->array[destination].head;  // update the parameters
    graph->array[destination].head = newNode; 
} 
  
// Structure for min heap node 
struct MinHeapNode { 
    int v; 
    int key; 
}; 
  
// Structure to represent a min heap 
struct MinHeap { 
    int size;           // Number of heap nodes present currently 
    int capacity;       // Capacity of min heap 
    int* pos;           // This is needed for decreaseKey() 
    struct MinHeapNode** array; 
}; 
  
// Function to create a new Min Heap node
struct MinHeapNode* newMinHeapNode(int v, int key) 
{ 
    struct MinHeapNode* minHeapNode = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode)); 
    minHeapNode->v = v; 
    minHeapNode->key = key; 
    return minHeapNode; 
} 
  
// creating the minimum Heap
struct MinHeap* createMinHeap(int capacity) 
{ 
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap)); 
    minHeap->pos = (int*)malloc(capacity * sizeof(int)); 
    minHeap->size = 0; 
    minHeap->capacity = capacity; 
    minHeap->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*)); 
    return minHeap; 
} 
  
// A function to swap 2 nodes, while extracting the minimum heap.
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) 
{ 
    struct MinHeapNode* t = *a; 
    *a = *b; 
    *b = t; 
} 
  
// Creating a function to Heapify based on a specific index.
// position of the node where swapping happens is recorded to use it in decreasing the key value.
void minHeapify(struct MinHeap* minHeap, int idx) 
{ 
    int smallest, left, right; 
    smallest = idx; 
    left = 2 * idx + 1; 
    right = 2 * idx + 2; 
  
    if (left < minHeap->size && minHeap->array[left]->key < minHeap->array[smallest]->key) 
        smallest = left; 
  
    if (right < minHeap->size && minHeap->array[right]->key < minHeap->array[smallest]->key) 
        smallest = right; 
  
    if (smallest != idx) { 
        MinHeapNode* smallestNode = minHeap->array[smallest];  // Nodes that need to be swapped
        MinHeapNode* idxNode = minHeap->array[idx]; 
  
        minHeap->pos[smallestNode->v] = idx;  // swapping
        minHeap->pos[idxNode->v] = smallest; 
  
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]); // swapping nodes.
  
        minHeapify(minHeap, smallest); 
    } 
} 
  
// A check if min_heap formed is empty or not.
int isEmpty(struct MinHeap* minHeap) 
{ 
    return minHeap->size == 0; 
} 
  
// function to extract minimum node from heap 
struct MinHeapNode* extractMin(struct MinHeap* minHeap) 
{ 
    if (isEmpty(minHeap)) 
        return NULL; 
  
    // root node 
    struct MinHeapNode* root = minHeap->array[0]; 
  
    // swap least node with root node 
    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1]; 
    minHeap->array[0] = lastNode; 
  
    // Update 
    minHeap->pos[root->v] = minHeap->size - 1; 
    minHeap->pos[lastNode->v] = 0; 
  
    // Reduce heap size and heapify root 
    --minHeap->size; 
    minHeapify(minHeap, 0); 
  
    return root; 
} 
  
// Function to decreasy key value at vertex V. 
void decreaseKey(struct MinHeap* minHeap, int v, int key) 
{ 
    // Obtain Indev form the heap.
    int i = minHeap->pos[v]; 
  
    // obtain node and update the key value
    minHeap->array[i]->key = key; 
  
    // Travel up while the complete tree is not hepified. 
    while (i && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key) { 
        // Swap this node with its parent 
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2; 
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i; 
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]); 
  
        i = (i - 1) / 2; 
    } 
} 
  
  
////////////////////////////////till here - done- delete this

// Funciton to check if a node is included in the current mst set or not
bool isInMinHeap(struct MinHeap* minHeap, int v) 
{ 
    if (minHeap->pos[v] < minHeap->size) 
        return true; 
    return false; 
} 
  
// Funciton to print the MST after processing through Prims algorithm. 
void printArr(int arr[], int n) 
{ 
    for (int i = 1; i < n; ++i) 
        printf("%d - %d\n", arr[i], i); 
} 
  
// Prims Algorithm
void PrimMST(struct Graph* graph) 
{ 
    int V = graph->V; // Obtain the number of verticesin the graph. 
    int parent[V]; // Array to store the current MST tree.
    int key[V]; // used to Extract min key value. 
  
    struct MinHeap* minHeap = createMinHeap(V); 
    
  // Initialise all key values to INT_MAX except the first node to start off with the algorithm to extract the first min key value. 
  for (int v = 1; v < V; ++v) { 
        parent[v] = -1; 
        key[v] = INT_MAX; 
        minHeap->array[v] = newMinHeapNode(v, key[v]); 
        minHeap->pos[v] = v; 
    } 
  
    // Let first key be zero.
    key[0] = 0; 
    minHeap->array[0] = newMinHeapNode(0, key[0]); 
    minHeap->pos[0] = 0; 
    minHeap->size = V; 
  
   // For elements not in current mst list, run the loop to add connections using prims algorithm
    while (!isEmpty(minHeap)) { 
        // Extract the vertex with minimum key value 
        struct MinHeapNode* minHeapNode = extractMin(minHeap); 
        int u = minHeapNode->v; // Store the extracted vertex index.
  
       // Update key values in each iteration
        struct AdjListNode* pCrawl = graph->array[u].head; 
        while (pCrawl != NULL) { 
            int v = pCrawl->destination; 
   
            if (isInMinHeap(minHeap, v) && pCrawl->weight < key[v]) { 
                key[v] = pCrawl->weight; 
                parent[v] = u; 
                decreaseKey(minHeap, v, key[v]); 
            } 
            pCrawl = pCrawl->next; 
        } 
    } 
  
// print the connections in order.
    printArr(parent, V); 
} 
  
// main part of the program. 
int main() 
{ 
    // Manually creating the input graph by adding connections and assigning them weights. 
    int V = 9; 
    cout << "Connections in the final MST will be for the following nodes " << endl;
    
    struct Graph* graph = createGraph(V); 
    addEdge(graph, 0, 1, 4); 
    addEdge(graph, 0, 7, 8); 
    addEdge(graph, 1, 2, 8); 
    addEdge(graph, 1, 7, 11); 
    addEdge(graph, 2, 3, 7); 
    addEdge(graph, 2, 8, 2); 
    addEdge(graph, 2, 5, 4); 
    addEdge(graph, 3, 4, 9); 
    addEdge(graph, 3, 5, 14); 
    addEdge(graph, 4, 5, 10); 
    addEdge(graph, 5, 6, 2); 
    addEdge(graph, 6, 7, 1); 
    addEdge(graph, 6, 8, 6); 
    addEdge(graph, 7, 8, 7); 
  
  // Applying Prims algorithm over the generated input graph.
    PrimMST(graph); 
  
    return 0; 
}
