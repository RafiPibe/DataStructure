#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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

void dfs(int root) {
    bool visited[SIZE] = {false};
    stack<int> S;
    S.push(root);
    while (!S.empty()) {
        int v = S.top();
        S.pop();
        if (!visited[v]){
            visited[v] = true;
            printf("%d ", v+1);
            for (int i = 0; i < adjList[v].size(); i++) {
                int w = adjList[v].at(i);
                if (!visited[w]){
                    S.push(w);
                }
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
    // bfs(root - 1);
    dfs(root -1);
}