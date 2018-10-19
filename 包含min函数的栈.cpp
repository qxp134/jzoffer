class Solution {
public:
    stack<int> data;
    stack<int> smin;
    void push(int value) {
        data.push(value);
        if(smin.size() == 0||value < smin.top()){
            smin.push(value);
        }
        else
            smin.push(smin.top());
    }
    void pop() {
        data.pop();
        smin.pop();
    }
    int top() {
        return data.top();
    }
    int min() {
        return smin.top();
    }
};
