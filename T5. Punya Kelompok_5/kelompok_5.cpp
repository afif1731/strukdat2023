// A C++ program for Bellman-Ford's single source
// shortest path algorithm.
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// a structure to represent a weighted edge in graph
struct Edge
{
    int src, dest, weight;
};

// a structure to represent a connected, directed and
// weighted graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;

    // graph is represented as an array of edges.
    struct Edge *edge;
};

// Creates a graph with V vertices and E edges
struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void visiting(struct Graph *graph, int aw, vector<bool> &visited)
{
    cout << aw << " ";
    for(int i=0; i<graph->E; i++) {
        if(graph->edge[i].src == aw && !visited[graph->edge[i].dest]) {
            visited[graph->edge[i].dest] = true;
            visiting(graph, graph->edge[i].dest, visited);
        }
    }
}

void DFS(struct Graph *graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    vector<bool> visited(V);

    //declare that no vertex has been visited
    for(int i=0; i<V; i++) visited[i] = false;
    visited[src] = true;

    cout << "DFS(Depth-First Search)\nSource: " << src << endl;
    visiting(graph, src, visited);
    cout << endl << endl;
}

// A utility function used to print the solution
void printArr(int dist[], int n, int src)
{
    printf("BellmanFord\nSource : %d\n", src);
    printf("+---------------+----------------------+\n");
    printf("| Vertex\t| Distance from Source |\n");
    printf("+---------------+----------------------+\n");
    for (int i = 0; i < n; ++i)
        printf("| %d \t\t| %d\t\t       |\n", i, dist[i]);
    printf("+---------------+----------------------+\n");
}

// The main function that finds shortest distances from src
// to all other vertices using Bellman-Ford algorithm. The
// function also detects negative weight cycle
void BellmanFord(struct Graph *graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    // Step 1: Initialize distances from src to all other
    // vertices as INFINITE
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times. A simple
    // shortest path from src to any other vertex can have
    // at-most |V| - 1 edges
    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Step 3: check for negative-weight cycles. The above
    // step guarantees shortest distances if graph doesn't
    // contain negative weight cycle. If we get a shorter
    // path, then there is a cycle.
    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            printf("Graph contains negative weight cycle");
            return; // If negative cycle is detected, simply
                    // return
        }
    }

    printArr(dist, V, src);

    return;
}

// Driver's code
int main()
{
    /* Let us create the graph given in above example */
    int V; // Number of vertices in graph
    int E; // Number of edges in graph
    cin >> V >> E;
    struct Graph *graph = createGraph(V, E);
    struct Edge edge;

    for (int i = 0; i < E; i++)
    {
        cin >> graph->edge[i].src >> graph->edge[i].dest >> graph->edge[i].weight;
    }

    // Function call
    DFS(graph, 0);
    BellmanFord(graph, 0);

    return 0;
}

/*
Test Case
5 10
0 1 6
0 2 7
1 4 5
1 3 -4
1 2 8
2 3 9
2 4 -3
3 0 2
3 4 7
4 1 -2
*/

/*
test case 2
4 6
0 1 1
0 2 1
1 2 1
2 0 1
2 3 1
3 3 1
*/

/*
3 3 
0 1 2
1 2 3
2 0 -7
*/
