#include <bits/stdc++.h>
using namespace std;

int dist[10000] = {9999}, prev[10000] = {-1};

int minDistance(bool Q[], int vertices) {

	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < vertices; v++)
		if (Q[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void printSolution(int dist[], int vertices) {
	cout <<"Vertex \t Distance from Source" << endl;
	for (int i = 0; i < vertices; i++)
		cout << i << " \t\t"<<dist[i]<< endl;
}

void dijkstra(int graph[][], int source, int vertices) {
    bool Q[vertices] = {true};
    dist[source] = {0};
    int count = vertices;
    
    while(count > 0) {
        int u = minDistance(Q, vertices);

    }


}

int main() {
    int vertices;
    cin >> vertices;

    int graph[vertices][vertices] = {0};
    for(int i; i < vertices; i++) {
        for (int j; j < vertices; j++) {
            cin >> graph[i][j];
        }
    }
}