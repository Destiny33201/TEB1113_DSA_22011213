#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(char current, unordered_map<char, vector<char>>& graph, unordered_set<char>& visited) {
    visited.insert(current);
    cout << current << " ";

    for (char neighbor : graph[current]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor, graph, visited);
        }
    }
}

int main() {
    // Define the directed graph using adjacency list
    unordered_map<char, vector<char>> graph;

    // Add edges
    graph['A'] = {'B', 'C', 'D'};
    graph['B'] = {'A', 'E', 'D'};
    graph['C'] = {'A', 'D'};
    graph['D'] = {'A', 'B', 'C', 'D', 'E'}; // D has a self-loop
    graph['E'] = {'B', 'D'};

    unordered_set<char> visited;

    cout << "DFS Order: ";
    dfs('A', graph, visited);
    cout << endl;

    return 0;
}
