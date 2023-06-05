#include <iostream>
#include <queue>
using namespace std;
//----------------------------------------------------------------------------

class Graph {
private:
    int numvertice;
    vector<vector<int>> adjmatrix;
    vector<vector<int>> adjlist;
//----------------------------------------------------------------------------
public:
    Graph(int vertices) {
        numvertice = vertices;

        // Initialize adjacency matrix
        adjmatrix.resize(numvertice, vector<int>(numvertice, 0));

        // Initialize adjacency list
        adjlist.resize(numvertice);
    }
//----------------------------------------------------------------------------
    void addEdge(int src, int dest) {
        adjmatrix[src][dest] = 1;
        adjmatrix[dest][src] = 1;

        adjlist[src].push_back(dest);
        adjlist[dest].push_back(src);
    }
//----------------------------------------------------------------------------
    void DFS(int startVertex, vector<bool>& visited) {
        visited[startVertex] = true;
        cout << startVertex << " ";

        for (int i = 0; i < numvertice; ++i) {
            if (adjmatrix[startVertex][i] == 1 && !visited[i]) {
                DFS(i, visited);
            }
        }
    }
//----------------------------------------------------------------------------
    void DFS(int startVertex) {
        vector<bool> visited(numvertice, false);
        cout << "DFS Traversal: ";
        DFS(startVertex, visited);
        cout << endl;
    }
//----------------------------------------------------------------------------
    void BFS(int startVertex) {
        vector<bool> visited(numvertice, false);
        queue<int> bfsQueue;

        visited[startVertex] = true;
        bfsQueue.push(startVertex);

        cout << "BFS Traversal: ";
//----------------------------------------------------------------------------
        while (!bfsQueue.empty()) {
            int currVertex = bfsQueue.front();
            bfsQueue.pop();
            cout << currVertex << " ";

            for (int i = 0; i < adjlist[currVertex].size(); ++i) {
                int adjVertex = adjlist[currVertex][i];
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    bfsQueue.push(adjVertex);
                }
            }
        }

        cout << endl;
    }
};
//----------------------------------------------------------------------------
int main() {
    // Create a graph
    Graph graph(7);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(2, 6);

    // Perform DFS starting from vertex 0
    graph.DFS(0);

    // Perform BFS starting from vertex 0
    graph.BFS(0);

    return 0;
}
//----------------------------------------------------------------------------