/* This code implement an algorithm to find the path between any two nodes in a graph 
   This algorithm find the path in time O(1) due to the precalculus. */

#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

#define V 9 

static int row = 0;
vector<vector<vector<int>>> paths(V, vector<vector<int>>(V));

// A utility function to find the vertex with minimum distance value 
int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++) {
		if (sptSet[v] == false && dist[v] <= min) {
			min = dist[v];
			min_index = v;
		}
	}
	return min_index;
}

// Function to print shortest path from source to j using parent array 
void printPath(int parent[], int j, int src)
{
	if (parent[j] == -1) return;
	printPath(parent, parent[j], src);
	paths[src][row].push_back(j);
}

// A utility function to print the constructed distance array 
void printSolution(int dist[], int n, int parent[], int src)
{
	for (int i = 0; i < V; i++) {
		paths[src][i].push_back(src);
		row = i;
		printPath(parent, i, src);
	}
}

// Funtion that implements Dijkstra's single source shortest path 
void dijkstra(int graph[V][V], int src)
{
	int dist[V];
	bool sptSet[V];
	int parent[V];

	parent[src] = -1;
	for (int i = 0; i < V; i++) {
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}
	dist[src] = 0;

	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;

		for (int v = 0; v < V; v++) {
			if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}
	printSolution(dist, V, parent, src);
}

void save_all_paths(int graph[V][V])
{
	for (int i = 0; i < V; ++i) dijkstra(graph, i);
}

void print_all_paths()
{
	for (int i = 0; i < paths.size(); ++i) {
		for (int j = 0; j < paths[0].size(); ++j) {
			for (int k = 0; k < paths[i][j].size(); ++k) {
				cout << paths[i][j][k] << " " ;
			}
			cout << endl;
		}
		cout << endl;
	}
}

void find_path_between(int a, int b)
{
	cout << "\nPath between nodes " << a << " and " << b << ": ";
	for (int i = 0; i < paths[a][b].size(); ++i) {
		cout << paths[a][b][i] << " ";
	}
	cout << endl;
}

int main()
{

	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 0, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 14, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	save_all_paths(graph); // Precalculus

	find_path_between(2, 6);	
	find_path_between(0, 8);
	find_path_between(1, 5);


	return 0;
}