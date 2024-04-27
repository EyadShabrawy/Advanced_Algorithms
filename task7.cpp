#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
    int V;
    vector<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void fillOrder(int v, bool visited[], stack<int> &Stack);
    void DFS(int v, bool visited[]);
    void printSCCs();
    Graph getTranspose();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::DFS(int v, bool visited[]) {
    visited[v] = true;
    cout << v << " ";
    for(int i = 0; i < adj[v].size(); ++i)
        if(!visited[adj[v][i]])
            DFS(adj[v][i], visited);
}

Graph Graph::getTranspose() {
    Graph g(V);
    for (int v = 0; v < V; v++)
        for(int i = 0; i < adj[v].size(); ++i)
            g.adj[adj[v][i]].push_back(v);
    return g;
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack) {
    visited[v] = true;
    for(int i = 0; i < adj[v].size(); ++i)
        if(!visited[adj[v][i]])
            fillOrder(adj[v][i], visited, Stack);
    Stack.push(v);
}

void Graph::printSCCs() {
    stack<int> Stack;
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            fillOrder(i, visited, Stack);

    Graph gr = getTranspose();

    for(int i = 0; i < V; i++)
        visited[i] = false;

    while (Stack.empty() == false) {
        int v = Stack.top();
        Stack.pop();

        if (visited[v] == false) {
            gr.DFS(v, visited);
            cout << endl;
        }
    }
}

int main() {
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout << "Following are strongly connected components in given graph:\n";
    g.printSCCs();

    return 0;
}
