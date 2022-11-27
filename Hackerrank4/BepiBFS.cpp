#include <bits/stdc++.h>
using namespace std;
#define SIZE 1001

vector<int> adjList[SIZE];
bool visited[SIZE] = {false};
bool found = false;

void BFS(int root, int goal) {
    queue<int> Q;
    visited[root] = true;
    Q.push(root);
    cout << root << ' ';

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();

        for (auto u : adjList[v]) {
            if (!visited[u]) {
                visited[u] = true;
                if(goal == u) {
                    found = true;
                }

                Q.push(u);
                cout << u << ' ';
            }
        }
    }
}

int main() {
    int vertices, edges;
    int a, b;
    int matrix[SIZE][SIZE] = {0};
    cin >> vertices >> edges;

    while(edges--) {
        cin >> a >> b;
        if(a != b) {
            adjList[a].push_back(b);
            adjList[b].push_back(a);
            matrix[a][b] = 1;
            matrix[b][a] = 1;
        }
    }
    
    int root, goal;
    cin >> root >> goal;
    BFS(root, goal);

    if(found == true) {
        cout << "Found!" << endl;
    } else {
        cout << "Not Found." << endl;
    }

    if(found) {
        for(int i = 0; i < vertices; i++) {
            for(int j = 0; j < vertices; j++) {
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
    }
}