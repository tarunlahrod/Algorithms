// C++ program to print all paths from a source to destination. 
#include<iostream> 
#include<iomanip>
#include <list> 
#include<string>

using namespace std; 
//using std::getline ;
using std::cin ;
    
// A directed graph using adjacency list representation 
class Graph 
{ 
    
    int V; // No. of vertices in graph 
    list<int> *adj; // Pointer to an array containing adjacency lists 
   
  
    // A recursive function used by printAllPaths() 
    void printAllPathsUtil(int , int , bool [], int [], int &); 
  
public: 
    Graph(int V); // Constructor 
    void addEdge(int u, int v); 
    void printAllPaths(int x, int y); 
}; 
  
Graph::Graph(int V) 
{ 
     this->V = V; 
    adj = new list<int>[V]; 
   
    
} 
  
void Graph::addEdge(int u, int v) 
{ 
    adj[u].push_back(v); // Add v to u’s list. 
} 
  
// Prints all paths from 's' to 'd' 
void Graph::printAllPaths(int x, int y) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
  
    // Create an array to store paths 
    int *path = new int[V]; 
    int path_index = 0; // Initialize path[] as empty 
  
    // Initialize all vertices as not visited 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function to print all paths 
    printAllPathsUtil(x, y, visited, path, path_index); 
} 
  
// A recursive function to print all paths from 'u' to 'd'. 
// visited[] keeps track of vertices in current path. 
// path[] stores actual vertices and path_index is current 
// index in path[] 
void Graph::printAllPathsUtil(int u, int y, bool visited[], 
                            int path[], int &path_index) 
{ 
    // Mark the current node and store it in path[] 
    visited[u] = true; 
    path[path_index] = u; 
    path_index++; 
    string ar[250];
    ar[0]="mundka";
    ar[1]="nangloi";
    ar[2]="punjabi bagh";
    ar[3]="netji subhash place";
    ar[4]="keshav puram";
    ar[5]="rajouri garden";
    ar[6]="moti nagar";
    ar[7]="kirti nagar";
    ar[8]="ashok park";
    ar[9]="punjabi bagh";
  
   
    // If current vertex is same as destination, then print 
    // current path[] 
    if (u == y) 
    { 
        for (int i = 0; i<path_index; i++) 
        { 
            int x=path[i];
            // cout << ar[x] <<"->"; 
            cout<< x ; 
            if(i != path_index-1)
                cout << " -> ";
        }
        cout << endl; 
          
    } 
    else // If current vertex is not destination 
    { 
        // Recur for all the vertices adjacent to current vertex 
        list<int>::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
            if (!visited[*i]) 
                printAllPathsUtil(*i, y, visited, path, path_index); 
    } 
  
    // Remove current vertex from path[] and mark it as unvisited 
    path_index--; 
    visited[u] = false; 
} 

// a function to print all the station and station codes
void printStationCode(string *ar){
    cout<<setw(20)<<"Station"<<setw(15)<<"Code"<<"\n\n";
    for(int i=0; i<9; i++)
        cout<<setw(20)<<ar[i]<<setw(15)<<i<<"\n";
}
  
// Driver program 
int main() 
{ 
    string ar[250];
    ar[0]="Mundka";
    ar[1]="Nangloi";
    ar[2]="Rajiv Chowk";
    ar[3]="Netaji Subhash Place";
    ar[4]="Keshav Puram";
    ar[5]="Rajouri Garden";
    ar[6]="Moti Nagar";
    ar[7]="Kirti Nagar";
    ar[8]="Ashok Park Main";
    ar[9]="Punjabi Bagh";
  
    // Create a graph given in the above diagram 
    Graph g(10); 
    g.addEdge(0, 1); 
    g.addEdge(1, 0); 
    g.addEdge(1, 2); 
    g.addEdge(2, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 2); 
    g.addEdge(0, 4); 
    g.addEdge(4, 0); 
    g.addEdge(4, 5); 
    g.addEdge(5, 4); 
    g.addEdge(5, 2);
    g.addEdge(2, 5); 
    g.addEdge(1, 6); 
    g.addEdge(6, 1); 
    g.addEdge(6, 7);
    g.addEdge(7, 6); 
    g.addEdge(2, 7); 
    g.addEdge(7, 2);
    g.addEdge(7, 8); 
    g.addEdge(8, 7); 
    g.addEdge(8, 9);
    g.addEdge(9, 8); 
    
    
    // a function to print station code.
    printStationCode(ar);
    
    int x=1 , y=9, i; 

    
    cout<<"\nEnter code for boarding station: ";
    cin>>x;
    cout<<"Enter code for destination station: ";
    cin>>y;

  
 //   string s, d;
 //   cout<<"enter the boarding station"<<endl;
     
 // getline(cin ,s);
      
  //  cout<<"enter the deboarding station"<<endl;
      
//   getline(cin ,d);
       
 //   for(i=0; i<=9 ;i++)
   // {
     //   if(ar[i]==s);
       // x=i;
        //if(ar[i]==d);
    //    y=i;
    //}
//getchar();
    cout << "\nFollowing are all different paths from " << ar[x]
        << " to " << ar[y] << endl << endl; 
    g.printAllPaths(x, y); 
  
    return 0; 
}