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

int bfs(int root, int goal) {
    bool visited[SIZE] = {false};
    queue<int> Q;
    visited[root] = true;
    Q.push(root);

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();

        printf("%d ", v + 1);
        if (v == goal) {
            return v;
        }

        for (int w : adjList[v]) {
            if (!visited[w]) {
                visited[w] = true;
                Q.push(w);
            }
        }
    }

    return 0;
}

int main() {
    int connections;
    cin >> connections;

    for (int i = 0; i < connections; i++) {
        int a, b;
        cin >> a >> b;
        makeConnections(a - 1, b - 1);
    }

    int root, goal;
    cin >> root >> goal;
    if (bfs(root - 1, goal - 1)) {
        cout << "Found!" << endl;
    }
}