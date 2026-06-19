class MinStack {
    Stack<Integer> s;
    Stack<Integer> a;
    public MinStack() {
        s = new Stack<>();
        a = new Stack<>();
    }
    
    public void push(int value) {
        s.push(value);
        if (a.isEmpty()) {
            a.push(value);
        } else if (value <= a.peek()) {
            a.push(value);
        }
    }
    
    public void pop() {
        if (s.isEmpty()) {
            return;
        }
        int top = s.pop();
        if (top == a.peek()) {
            a.pop();
        }
    }
    
    public int top() {
        if (s.isEmpty()) {
            return -1;
        }
        return s.peek();
    }
    
    public int getMin() {
        if (s.isEmpty()) {
            return -1;
        }
        return a.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(value);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */