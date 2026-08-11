class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        vector<bool> vis(numCourses, false);
        vector<bool> pathvis(numCourses, false);
        vector<vector<int>> arr(numCourses);
        for (auto it : p) {
    arr[it[1]].push_back(it[0]);
}
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, pathvis, arr)) {
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(int node, vector<bool>& vis, vector<bool>& pathvis, vector<vector<int>>& arr) {
        vis[node] = true;
        pathvis[node] = true;
        for (int adj : arr[node]) {
            if (!vis[adj]) {
                if (dfs(adj, vis, pathvis, arr)) {
                    return true;
                }
            } else if (pathvis[adj]) {
                return true;
            }
        }
        pathvis[node] = false;
        return false;
    }
};