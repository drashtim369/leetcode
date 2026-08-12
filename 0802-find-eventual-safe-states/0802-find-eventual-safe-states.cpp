class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> indegree(graph.size(), 0);
        vector<int> res;
        queue<int> q;
        vector<vector<int>> arr(graph.size());
        for (int i = 0; i < graph.size(); i++) {
            for (auto it : graph[i]) {
                // 0 -> 1
                // 1 -> 0
                arr[it].push_back(i);
                indegree[i]++;
            }
        }
        int V = graph.size();
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            res.push_back(x);
            for (int node : arr[x]) {
                indegree[node]--;
                if (indegree[node] == 0) {
                    q.push(node);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};