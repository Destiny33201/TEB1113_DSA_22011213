#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

void bfs(char start, unordered_map<char, vector<char>>& graph) {
    unordered_set<char> visited;
    queue<char> q;

    visited.insert(start);
    q.push(start);

    cout << "BFS Order: ";

    while (!q.empty()) {
        char current = q.front();
        q.pop();

        cout << current << " ";

        for (char neighbor : graph[current]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }

    cout << endl;
}

int main() {
    // Define the directed graph using adjacency list
    unordered_map<char, vector<char>> graph;

    // Add edges
    graph['B'] = {'A', 'D', 'E'};
    graph['A'] = {'B', 'C', 'D'};
    graph['C'] = {'A', 'D'};
    graph['D'] = {'A', 'B', 'C', 'D', 'E'}; // D has a self-loop
    graph['E'] = {'B', 'D'};

    // Start BFS from 'A'
    bfs('B', graph);

    return 0;
}
