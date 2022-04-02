//使用两个栈实现一个队列
//思路：入队列时，直接加入第一个队列。出队列时，如果stack2中有数据，需要先把2中的数据全部出完，如果2中没有数据，需要一次性把stack1中的数据全部拷贝至stack2中


#include<stack>
#include<iostream>
using namespace std;


template<typename T>
class MyQueue
{
private:
    stack<T> s1;
    stack<T> s2;
public:
void pop()
{
    if(s2.empty())    //第二个栈为空
    {
        while(!s1.empty())  //把第一个栈中的数据全部取出
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    if(s2.empty())  //说明第一个栈里面也什么没有
    {

    }
    else
    {
        s2.pop();
    }
}
void push(const T& value)
{
    s1.push(value);
}

};