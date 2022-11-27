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
    cin >> vertices >> edges;

    while(edges--) {
        cin >> a >> b;
        if(a != b) {
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
    }
    
    int root, goal;
    cin >> root >> goal;
    BFS(root, goal);

    if(found == true) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}