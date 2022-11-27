#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define SIZE 5

vector<int>adjList[SIZE];

void makeConnections(int a, int b) {
    adjList[a].push_back(b);
    adjList[b].push_back(a);
}

void bfs(int root) {
    bool visited[SIZE] = {false};
    queue<int> Q;
    visited[root] = true;
    Q.push(root);
    printf("%d ", root + 1);

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();

        // for (int w : adjList[v]) {
        for (int i = 0; i < adjList[v].size(); i++) {
            int w = adjList[v].at(i);
            if (!visited[w]) {
                visited[w] = true;
                Q.push(w);
                printf("%d ", w + 1);
            }
        }
    }
}

int main() {
    int connections;
    cin >> connections;

    for (int i = 0; i < connections; i++) {
        int a, b;
        cin >> a >> b;
        makeConnections(a - 1, b - 1);
    }

    int root;
    cin >> root;
    bfs(root - 1);
}