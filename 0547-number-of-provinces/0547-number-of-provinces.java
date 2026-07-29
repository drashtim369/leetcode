class Solution {
    public void dfs(int node, List<List<Integer>> edges, boolean[] vis) {
        vis[node] = true;
        for (int it : edges.get(node)) {
            if (!vis[it]) {
                dfs(it, edges, vis);
            }
        }
    }
    public int findCircleNum(int[][] isConnected) {
        List<List<Integer>> edges = new ArrayList<>();
        int V = isConnected.length;
        for (int i = 0; i < V; i++) {
            edges.add(new ArrayList<>());
        }
        for (int i = 0; i < V; i++) {
            for (int j = i+1; j < V; j++) {
                if (isConnected[i][j] == 1) {
                    edges.get(i).add(j);
                    edges.get(j).add(i);
                }
            }
        }
        boolean[] vis = new boolean[V + 1];
        Arrays.fill(vis,false);
        int cnt = 0;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, edges, vis);
            }
        }
        return cnt;
    }
}