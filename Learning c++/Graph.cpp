 #include <iostream>
   #include <vector>
   #include <bits/stdc++.h>

   using namespace std;


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


   void printGraph (GRAPH const& G, int n){
        for(int i = 0; i < n; i++){
            cout << i << "->";
            for(int v: G.adjList[i]){
               cout << v << " ";
            }
            cout << endl;
        }

   }

   int main()
   {
       int n = 10; //# of nodes
       vector<EDGE> edge = {
           {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5},
           {1, 7}, {1, 8},
           {2, 6},
           {3, 7}, {3, 8},
           {4, 8},
           {5, 7},
           {6, 9},
           {7, 9},
           {8, 9},

       };
       GRAPH G(edge, n);  // construct a graph here
       printGraph(G,n);

      system("pause");
      return 0;
  }
