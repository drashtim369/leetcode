class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (dfs(i, 0, color, graph) == false) return false;
            }
        }
        return true;
    }
    bool dfs(int node, int col, vector<int>&color, vector<vector<int>>& graph) {
        color[node] = col;
        for (int adj : graph[node]) {
            if (color[adj] == -1) {
                if (dfs(adj, 1 - col, color, graph) == false) return false; 
            } else if (color[adj] == col) {
                return false;
            }
        }
        return true;
    }
};