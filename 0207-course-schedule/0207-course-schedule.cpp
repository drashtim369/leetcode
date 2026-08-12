class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> indegree(n, 0);
        vector<vector<int>> arr(n);
        for (auto i : p) {
            arr[i[1]].push_back(i[0]);
        }
        for (int i = 0; i < n; i++) {
            for (int node : arr[i]) {
                indegree[node]++;
            }
        }
        queue<int> q; int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            cnt++;
            for (int node : arr[x]) {
                indegree[node]--;
                if (indegree[node] == 0) {
                    q.push(node);
                }
            }
        }
        return cnt == n;
    }
};