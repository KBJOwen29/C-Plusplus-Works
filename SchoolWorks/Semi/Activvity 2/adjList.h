#define ADJLIST_H

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <unordered_set>
using namespace std;

class GraphAdjList {
    int vertices; // Number of vertices
    vector<list<int>> adjList;

public:
    // Constructor
    GraphAdjList(int v) : vertices(v), adjList(v) {}

    // Add edge
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For an undirected graph
    }

    // Display graph
    void display() {
        cout << "Graph (Adjacency List):" << endl;
        for (int i = 0; i < vertices; ++i) {
            cout << i << " -> ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
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
                for (auto it = adjList[node].rbegin(); it != adjList[node].rend(); ++it) {
                    if (!visited[*it]) {
                        s.push(*it);
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
            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        cout << endl;
    }
};
