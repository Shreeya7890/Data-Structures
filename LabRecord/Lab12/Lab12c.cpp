//Graph ADT + Prim’s, Kruskal’s, Dijkstra’s
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graph {
    int V;
    vector<pair<int, int>> *adj;
    vector<tuple<int, int, int>> edges;

public:
    Graph(int v) {
        V = v;
        adj = new vector<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int w);
    void display();
    void primMST(int start);
    void kruskalMST();
    void dijkstra(int start);
    int find(int u, vector<int>& parent);
    void unionSets(int u, int v, vector<int>& parent, vector<int>& rank);
    ~Graph() {
        delete[] adj;
    }
};

int main() {
    int V, choice;
    cout << "Enter number of vertices: ";
    cin >> V;
    Graph g(V);

    while (true) {
        cout << "\n1. Add Edge\n2. Display\n3. Prim's MST\n4. Kruskal's MST\n5. Dijkstra's SPT\n6. Exit\nEnter your choice: ";
        cin >> choice;
        if (choice == 1) {
            int u, v, w;
            cout << "Enter edge (u v weight): ";
            cin >> u >> v >> w;
            g.addEdge(u, v, w);
        } else if (choice == 2) {
            g.display();
        } else if (choice == 3) {
            int start;
            cout << "Enter starting vertex for Prim's: ";
            cin >> start;
            g.primMST(start);
        } else if (choice == 4) {
            g.kruskalMST();
        } else if (choice == 5) {
            int start;
            cout << "Enter source vertex for Dijkstra: ";
            cin >> start;
            g.dijkstra(start);
        } else if (choice == 6) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}

// Function to insert an edge into the graph
void Graph::addEdge(int u, int v, int w) {
    if (u >= 0 && v >= 0 && u < V && v < V) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({w, u, v});
    } else {
        cout << "Invalid vertices!\n";
    }
}

// Function to display the graph (Adjacency List representation)
void Graph::display() {
    cout << "Graph (Adjacency List):\n";
    for (int i = 0; i < V; ++i) {
        cout << i << ": ";
        for (auto [v, w] : adj[i])
            cout << "(" << v << ", " << w << ") ";
        cout << "\n";
    }
}

// Function to compute the Minimum Spanning Tree (MST) using Prim's Algorithm
void Graph::primMST(int start) {
    vector<bool> inMST(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> key(V, 2147483647), parent(V, -1);  
    int total = 0;

    pq.push({0, start});
    key[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (inMST[u]) continue;

        inMST[u] = true;
        total += key[u];

        for (auto [v, w] : adj[u]) {
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "Prim's MST:\n";
    for (int i = 0; i < V; ++i)
        if (parent[i] != -1)
            cout << parent[i] << " - " << i << "\n";
    cout << "Total Weight: " << total << "\n";
}

// Function to find the representative (parent) of a node (for union-find in Kruskal's)
int Graph::find(int u, vector<int>& parent) {
    if (parent[u] != u)
        parent[u] = find(parent[u], parent);
    return parent[u];
}

// Function to union two sets (for union-find in Kruskal's)
void Graph::unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = find(u, parent);
    v = find(v, parent);
    if (u != v) {
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
}

// Function to compute the Minimum Spanning Tree (MST) using Kruskal's Algorithm
void Graph::kruskalMST() {
    sort(edges.begin(), edges.end());
    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; ++i) parent[i] = i;

    int total = 0;
    cout << "Kruskal's MST:\n";
    for (auto [w, u, v] : edges) {
        if (find(u, parent) != find(v, parent)) {
            cout << u << " - " << v << "\n";
            total += w;
            unionSets(u, v, parent, rank);
        }
    }
    cout << "Total Weight: " << total << "\n";
}

// Function to compute the Shortest Path Tree (SPT) using Dijkstra's Algorithm
void Graph::dijkstra(int start) {
    vector<int> dist(V, 2147483647);  
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Dijkstra's Shortest Path Tree:\n";
    for (int i = 0; i < V; ++i)
        cout << "Vertex " << i << ", Distance: " << dist[i] << "\n";
}
