//Graph ADT using Adjacency Matrix
#include <iostream>
using namespace std;

class GraphMatrix {
    int **adjMatrix;
    int vertices;

public:
    GraphMatrix(int v){
        vertices = v;
        adjMatrix = new int*[vertices];
        for (int i = 0; i < vertices; ++i)
            adjMatrix[i] = new int[vertices]();
    }    
    void insertEdge(int u, int v);
    void deleteEdge(int u, int v);
    bool searchEdge(int u, int v);
    void display();
    ~GraphMatrix() {
        for (int i = 0; i < vertices; ++i)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

int main() {
    int choice, u, v, vertices;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    GraphMatrix graph(vertices);

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
void GraphMatrix::insertEdge(int u, int v) {
    if (u >= 0 && v >= 0 && u < vertices && v < vertices)
        adjMatrix[u][v] = 1;
    else
        cout << "Invalid vertices!\n";
}

//Function to delete egde
void GraphMatrix::deleteEdge(int u, int v) {
    if (u >= 0 && v >= 0 && u < vertices && v < vertices)
        adjMatrix[u][v] = 0;
    else
        cout << "Invalid vertices!\n";
}

//Function to search egde
bool GraphMatrix::searchEdge(int u, int v) {
    if (u >= 0 && v >= 0 && u < vertices && v < vertices)
        return adjMatrix[u][v] == 1;
    return false;
}

//Function to display
void GraphMatrix::display() {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j)
            cout << adjMatrix[i][j] << " ";
        cout << "\n";
    }
}


