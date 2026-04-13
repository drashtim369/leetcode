class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {

        // Step 1: build graph
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < numCourses; i++)
            graph.add(new ArrayList<>());

        int[] indeg = new int[numCourses];

        // Step 2: fill graph + indegree
        for (int[] p : prerequisites) {
            int course = p[0];
            int prereq = p[1];

            graph.get(prereq).add(course);
            indeg[course]++;
        }

        // Step 3: queue for indegree 0
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                q.add(i);
            }
        }

        // Step 4: BFS
        int cnt = 0;

        while (!q.isEmpty()) {
            int curr = q.poll();
            cnt++;

            for (int nei : graph.get(curr)) {
                indeg[nei]--;

                if (indeg[nei] == 0) {
                    q.add(nei);
                }
            }
        }

        // Step 5: check
        return cnt == numCourses;
    }
}