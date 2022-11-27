#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

class Graph {
    int V;

    list<pair<int, int> >* adj;

public:
    Graph(int V);

    void addEdgeRev(int u, int v, int w);

    void shortestPath(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<iPair>[V];
}

void Graph::addEdgeRev(int u, int v, int w) {

    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int dest) {
    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;

    vector<int> dist(V, INF);

    pq.push(make_pair(0, dest));
    dist[dest] = 0;

    while (!pq.empty()) {

        int u = pq.top().second;
        pq.pop();

        list<pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {

            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    for (int i = 1; i < V; ++i)
        printf("%d %d\n", i, dist[i]);
}

int main() {
    int vertices, edges;

    scanf("%d %d", &vertices, &edges);

    Graph g(vertices);

    int a, b, c;

    while(edges--) {
        scanf("%d %d %d", &a, &b, &c);
        g.addEdgeRev(b, a, c);
    }

    g.shortestPath(0);

    return 0;
}