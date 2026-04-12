import java.util.*;

class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        for (char c : s.toCharArray()) {
            // opening brackets
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } 
            else {
                // ❌ no opening to match
                if (st.isEmpty()) return false;

                char top = st.pop();

                // ❌ mismatch
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false;
                }
            }
        }

        return st.isEmpty();
    }
}