/*
In graph theory, a graph consists of vertices (also called nodes or points), which are connected by edges (also called arcs, links, or lines). Edges can be directed (having a specific direction) or undirected (no specific direction). 

Degree of a Vertex − The degree of a vertex V of a graph G (denoted by deg (V)) is the number of edges incident with the vertex V.

Even and Odd Vertex − If the degree of a vertex is even, the vertex is called an even vertex and if the degree of a vertex is odd, the vertex is called an odd vertex.

Degree of a Graph − The degree of a graph is the largest vertex degree of that graph.

The Handshaking Lemma − In a graph, the sum of all the degrees of all the vertices is equal to twice the number of edges.

A bipartite graph is a graph in which if the graph coloring is possible using two colors i.e; vertices in a set are colored with the same color.

given as edges  - convert to adjacent list..
given as matrix
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/* traverse using dfs */
void dfs(int start_vertex, vector<vector<int>>& adj_list, vector<bool>& visited) {
    stack<int> stack;
    stack.push(start_vertex);
    visited[start_vertex] = true;

    while (!stack.empty()) {
        int current_vertex = stack.top();
        stack.pop();
        cout << current_vertex << " ";

        for (int neighbor : adj_list[current_vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                stack.push(neighbor);
            }
        }
    }
}

void bfs(int start_vertex, vector<vector<int>>& adj_list, vector<bool>& visited) {
    queue<int> queue;
    queue.push(start_vertex);
    visited[start_vertex] = true;

    while (!queue.empty()) {
        int current_vertex = queue.front();
        queue.pop();
        cout << current_vertex << " ";

        for (int neighbor : adj_list[current_vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }
}

int dfs(int node, int parent, const vector<vector<int>>& adj, int& diameter) {
    int max_depth1 = 0, max_depth2 = 0;
    for (int child : adj[node]) {
        if (child != parent) {
            int current_depth = dfs(child, node, adj, diameter) + 1;
            if (current_depth > max_depth1) {
                max_depth2 = max_depth1;
                max_depth1 = current_depth;
            } else if (current_depth > max_depth2) {
                max_depth2 = current_depth;
            }
        }
    }
    diameter = max(diameter, max_depth1 + max_depth2);
    return max_depth1;
}

int treeDiameter(int n, const vector<vector<int>>& edges) {
	
	//convert edges to adj list
    vector<vector<int>> adj(n);
    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    int diameter = 0;
    dfs(0, -1, adj, diameter);
    return diameter;
}

// Function to get vertices from a list of edges
set<int> getVerticesFromEdges(const vector<pair<int, int>>& edges) {
    set<int> vertices; // Use a set to store unique vertices

    // Iterate through the edges
    for (const auto& edge : edges) {
        // Extract the vertices from the edge
        int vertex1 = edge.first;
        int vertex2 = edge.second;

        // Add the vertices to the set
        vertices.insert(vertex1);
        vertices.insert(vertex2);
    }

    return vertices;
}



int main() {

    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0},
        {3, 4}
    };

    // Get the vertices
    set<int> vertices = getVerticesFromEdges(edges);

    int num_vertices = 6;
    vector<vector<int>> adj_list(num_vertices);
    adj_list[0] = {1, 2};
    adj_list[1] = {0, 3, 4};
    adj_list[2] = {0, 5};
    adj_list[3] = {1};
    adj_list[4] = {1};
    adj_list[5] = {2};

    vector<bool> visited(num_vertices, false);
    cout << "DFS traversal starting from vertex 0: ";
    dfs(0, adj_list, visited);
    cout << endl;
	
	vector<bool> visited_bfs(num_vertices, false);
    cout << "BFS traversal starting from vertex 0: ";
    bfs(0, adj_list, visited_bfs);
    cout << endl;
	
	int G[][V] = {{ 0, 1, 0, 0},
                { 1, 0, 0, 0},
                { 0, 0, 0, 1},
                { 1, 0, 1, 0}};
				
				
	
    return 0;
}