#include<iostream>
#include<limits.h>
using namespace std;

#define V 6


int printSolution(int dist[], int n) 
{ 
   cout<<"Vertex   Distance from Source\n"; 
   for (int i = 0; i < V; i++) 
      cout << i+1 << "\t \t \t" << dist[i] <<"\n"; 
} 

int minDistance(int dist[], bool sptSet[]){
	int min = INT_MAX, min_index;

	for(int i=0; i<V; i++)
		if(sptSet[i] == false && dist[i] <= min)
			min = dist[i], min_index = i;

	return min_index;
}

void dij(int graph[][6], int src){

	bool sptSet[6] = {0};
	int dist[6];

	for(int i=0; i<6; i++)
		dist[i] = INT_MAX;
	// distance of source = 0, so that it is picked up first.
	dist[src] = 0;

	for(int i=0; i<V-1; i++){

		// while sptSet doesn't include all vertices,
		// 		1. Pick a vertex u which is not there in sptSet and has minimum distance value.
		// 		2. Include u to sptSet.
		// 		3. Update distance value of all adjacent vertices of u.
		int u = minDistance(dist, sptSet);

		sptSet[u] = true;

		for(int v=0; v<V; v++){

			if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){

				dist[v] = dist[u] + graph[u][v];

			}

		}

	}

	printSolution(dist, V);

}

int main(){
	// directed graph
	// int graph[6][6] = {
	// 	{ 0, 2, 4, 0, 0, 0},
	// 	{ 0, 0, 1, 7, 0, 0},
	// 	{ 0, 0, 0, 0, 3, 0},
	// 	{ 0, 0, 0, 0, 0, 1},
	// 	{ 0, 0, 0, 0, 0, 5},
	// 	{ 0, 0, 0, 0, 0, 0}
	// };

	// undirected graph
	int graph[6][6] = {
		{ 0, 2, 4, 0, 0, 0},
		{ 2, 0, 1, 7, 0, 0},
		{ 4, 1, 0, 0, 3, 0},
		{ 0, 7, 0, 0, 0, 1},
		{ 0, 0, 3, 0, 0, 5},
		{ 0, 0, 0, 1, 5, 0}
	};

	dij(graph, 1);
}
