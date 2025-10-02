#define ADJMATRIX_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class GraphAdjMatrix {
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    // Constructor
    GraphAdjMatrix(int v) : vertices(v), adjMatrix(v, vector<int>(v, 0)) {}

    // Add edge
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // For an undirected graph
    }

    // Display graph
    void display() {
        cout << "Graph (Adjacency Matrix):" << endl;
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Depth-First Search (DFS)
    void dfs(int start) {
        vector<bool> visited(vertices, false);
        stack<int> s;
        s.push(start);
        cout << "DFS: ";
        while (!s.empty()) {
            int node = s.top();
            s.pop();
            if (!visited[node]) {
                visited[node] = true;
                cout << node << " ";
                for (int i = vertices - 1; i >= 0; --i) {
                    if (adjMatrix[node][i] && !visited[i]) {
                        s.push(i);
                    }
                }
            }
        }
        cout << endl;
    }

    // Breadth-First Search (BFS)
    void bfs(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        cout << "BFS: ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";
            for (int i = 0; i < vertices; ++i) {
                if (adjMatrix[node][i] && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }
};
