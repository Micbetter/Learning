//问题：设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

//知识点：使用两个栈，一个栈存储值，别一个栈只存最小值
#include <stack>
using namespace std;


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s_stack.push(x);
        if(min_stack.empty() || x <= min_stack.top()){  //此外注意，需要加上等于号，否则pop出的时候会导致min_stack少元素
            min_stack.push(x);
        }
    }
    
    void pop() {
        if(!s_stack.empty()){
            if(s_stack.top() == min_stack.top()){
                min_stack.pop();
            }
            s_stack.pop();
            
        }
    }
    
    int top() {
        return s_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
private:
    std::stack<int> s_stack;
    std::stack<int> min_stack;
    
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */