//Graph ADT using Adjacency List
#include <iostream>
#include <list>
using namespace std;

class GraphList {
    list<int> *adj;
    int vertices;

public:
    GraphList(int v){
        vertices = v;
        adj = new list<int>[vertices];
    }
    void insertEdge(int u, int v);
    void deleteEdge(int u, int v);
    bool searchEdge(int u, int v);
    void display();
    ~GraphList() {
        delete[] adj;
    }    
};

int main() {
    int choice, u, v, vertices;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    GraphList graph(vertices);

    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                graph.insertEdge(u, v);
                break;
            case 2:
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                graph.deleteEdge(u, v);
                break;
            case 3:
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                if (graph.searchEdge(u, v))
                    cout << "Edge exists.\n";
                else
                    cout << "Edge does not exist.\n";
                break;
            case 4:
                graph.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}

//Function to insert edge
void GraphList::insertEdge(int u, int v) {
    if (u >= 0 && v >= 0 && u < vertices && v < vertices)
        adj[u].push_back(v);
    else
        cout << "Invalid vertices!\n";
}

//Function to delete egde
void GraphList::deleteEdge(int u, int v) {
    if (u >= 0 && v >= 0 && u < vertices && v < vertices)
        adj[u].remove(v);
    else
        cout << "Invalid vertices!\n";
}

//Function to search egde
bool GraphList::searchEdge(int u, int v) {
    if (u >= 0 && v >= 0 && u < vertices && v < vertices) {
        for (int node : adj[u]) {
            if (node == v) return true;
        }
    }
    return false;
}

//Function to display
void GraphList::display() {
    cout << "Adjacency List:\n";
    for (int i = 0; i < vertices; ++i) {
        cout << i << ": ";
        for (int v : adj[i]) cout << v << " ";
        cout << "\n";
    }
}

