#include <iostream>
#include <vector>
using namespace std;

// Structure for a node in the adjacency list
struct Node {
    int data;
    Node* next;

    // Constructor for creating a new node
    Node(int value) : data(value), next(nullptr) {}
};

// Function to add an edge between two vertices
void addEdge(vector<Node*>& adj, int i, int j){
    Node* newNode = new Node(j);
    newNode->next = adj[i];
    adj[i] = newNode;

    newNode = new Node(i); // For undirected graph
    newNode->next = adj[j];
    adj[j] = newNode;
}

// Function to display the adjacency list
void displayAdjList(vector<Node*>& adj) {
    for (size_t i = 0; i < adj.size(); i++) {
        cout << i << ": "; // Print the vertex
        Node* temp = adj[i];
        while (temp != nullptr) {
            cout << temp->data << " "; // Print its adjacent vertices
            temp = temp->next;
        }
        cout << endl;
    }
}

// Main function
int main() {
    // Create a graph with 4 vertices and no edges
    int V = 4;
    vector<Node*> adj(V, nullptr); // Initialize adjacency list

    // Now add edges one by one
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    cout << "Adjacency List Representation:" << endl;
    displayAdjList(adj);

    return 0;
}