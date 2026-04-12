class Solution {
    public int evalRPN(String[] tokens) {
        int[] stack = new int[tokens.length];
        int top = 0;

        for (String c : tokens) {

            if (c.equals("+")) {
                int b = stack[--top];
                int a = stack[--top];
                stack[top++] = a + b;

            } else if (c.equals("-") && c.length() == 1) {
                int b = stack[--top];
                int a = stack[--top];
                stack[top++] = a - b;

            } else if (c.equals("*")) {
                int b = stack[--top];
                int a = stack[--top];
                stack[top++] = a * b;

            } else if (c.equals("/")) {
                int b = stack[--top];
                int a = stack[--top];
                stack[top++] = a / b;

            } else {
                stack[top++] = Integer.parseInt(c);
            }
        }

        return stack[0];
    }
}