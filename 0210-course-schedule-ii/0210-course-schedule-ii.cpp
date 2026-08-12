class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> res; queue<int> q; vector<vector<int>> arr(n); vector<int> indegree(n);
        for (auto it : p) {
            arr[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < n; i++) {
            for (int node : arr[i]) {
                indegree[node]++;
            }
        }
        for (int i = 0; i < n; i++) {
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
        if (res.size() < n) return {};
        return res;
    }
};