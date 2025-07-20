// Backtracking: M Coloring Problem
#include <vector>
using namespace std;

bool isSafe(int node, int color, vector<int>& colors, vector<vector<int>>& graph) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[node][i] == 1 && colors[i] == color) return false;
    }
    return true;
}

bool graphColoring(vector<vector<int>>& graph, int m, int node, vector<int>& colors) {
    if (node == graph.size()) return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(node, c, colors, graph)) {
            colors[node] = c;
            if (graphColoring(graph, m, node + 1, colors)) return true;
            colors[node] = 0;
        }
    }
    return false;
}
