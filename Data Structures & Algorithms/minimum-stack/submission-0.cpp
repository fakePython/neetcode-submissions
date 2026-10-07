class MinStack {
private:
    stack<int> st;
    stack<int> st_min;
public:
    MinStack() {
        this->st = stack<int>();
    }
    
    void push(int val) {
        this->st.push(val);
        if(this->st_min.empty() || val <= this->st_min.top()){
            this->st_min.push(val);
        }
    }
    
    void pop() {
        if(!this->st_min.empty() && this->st.top() == this->st_min.top()){
            this->st_min.pop();
        }
        this->st.pop();
    }
    
    int top() {
        return this->st.top();
    }
    
    int getMin() {
        return this->st_min.top();
    }
};
