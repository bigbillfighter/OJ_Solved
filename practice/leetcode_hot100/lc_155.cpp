#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> x_stack;
    stack<int> min_stack;

public:
    MinStack() {
    }
    
    void push(int x) {
        x_stack.push(x);
        if(min_stack.size() == 0){
            min_stack.push(x);
        }else{
            min_stack.push(min(min_stack.top(), x));
        }
    }
    
    void pop() {
        x_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
