class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;
        for (int i = 0; i < asteroids.size(); i++) {
            bool alive = true;
            int current = asteroids[i];
            while (!st.empty() && st.top() > 0 && current < 0) {
                if (st.top() > abs(current)) {
                    alive = false;
                    break;
                } else if (st.top() == abs(current)) {
                    alive = false;
                    st.pop();
                    break;
                } else {
                    st.pop();
                }
            }
            if (alive) {
                st.push(current);
            } 
        }
        if (st.size() == 0) return {};
        vector<int> res(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};