#include "adjList.h"
#include "adjMatrix.h"

int main() {
    int vertices = 5;

    // Create a graph with adjacency list representation
    GraphAdjList graphList(vertices);
    graphList.addEdge(0, 1);
    graphList.addEdge(0, 4);
    graphList.addEdge(1, 2);
    graphList.addEdge(1, 3);
    graphList.addEdge(1, 4);
    graphList.addEdge(2, 3);
    graphList.addEdge(3, 4);
    graphList.display();
    graphList.dfs(0); // DFS starting from vertex 0
    graphList.bfs(0); // BFS starting from vertex 0

    // Create a graph with adjacency matrix representation
    GraphAdjMatrix graphMatrix(vertices);
    graphMatrix.addEdge(0, 1);
    graphMatrix.addEdge(0, 4);
    graphMatrix.addEdge(1, 2);
    graphMatrix.addEdge(1, 3);
    graphMatrix.addEdge(1, 4);
    graphMatrix.addEdge(2, 3);
    graphMatrix.addEdge(3, 4);
    graphMatrix.display();
    graphMatrix.dfs(0); // DFS starting from vertex 0
    graphMatrix.bfs(0); // BFS starting from vertex 0

    return 0;
}
