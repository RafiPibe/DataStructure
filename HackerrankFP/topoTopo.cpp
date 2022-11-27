#include <bits/stdc++.h>
using namespace std;

class Graph {
    int d;
    list<int> *adj;
    void topologicalSortUtil(int a, bool visited[], stack<int> &Stack);
    bool isCyclicUtil(int a, bool visited[], bool *rs);

public:
    Graph(int d);
    void addEdge(int a, int b);
    void topologicalSort();
    bool isCyclic();
};

Graph::Graph(int d) {
    this->d = d;
    adj = new list<int>[d];
}

void Graph::addEdge(int a, int b) {
    // Add b to a's list.
    adj[a].push_back(b);
}

bool Graph::isCyclicUtil(int a, bool visited[], bool *recStack) {
    if (visited[a] == false)
    {
        visited[a] = true;
        recStack[a] = true;

        list<int>::iterator i;
        for (i = adj[a].begin(); i != adj[a].end(); ++i)
        {
            if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
                return true;
            else if (recStack[*i])
                return true;
        }
    }
    recStack[a] = false;
    return false;
}

bool Graph::isCyclic() {
    bool *visited = new bool[d];
    bool *recStack = new bool[d];
    for (int i = 0; i < d; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < d; i++)
        if (!visited[i] && isCyclicUtil(i, visited, recStack))
            return true;

    return false;
}

void Graph::topologicalSortUtil(int a, bool visited[], stack<int> &Stack) {

    visited[a] = true;

    list<int>::iterator i;
    for (i = adj[a].begin(); i != adj[a].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);

    Stack.push(a);
}

void Graph::topologicalSort() {
    stack<int> Stack;
    bool *visited = new bool[d];
    for (int i = 0; i < d; i++)
        visited[i] = false;

    for (int i = 0; i < d; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
    if (Stack.empty())
    {
        cout << "-1" << endl;
        return;
    }
    while (Stack.empty() == false)
    {
        if (Stack.size() == 1)
            break;
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main() {
    int sumSimpul, sumSisi;
    cin >> sumSimpul >> sumSisi;

    Graph myGraph(sumSimpul + 1);
    
    while(sumSisi--) {
        int a, b;
        cin >> a >> b;
        myGraph.addEdge(a, b);
    }

    if (myGraph.isCyclic()) {
        cout << "-1" << endl;
    } else myGraph.topologicalSort();
    
    return 0;
}