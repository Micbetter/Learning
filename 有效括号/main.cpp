/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。

注意空字符串可被认为是有效字符串。
*/

//注意点：左侧符号入栈，每当出现右符号时进行对比，并pop出栈，需要特殊处理首符号为右符号的情况
//使用map容器进行对比左右符号


#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>
using namespace std;

class Solution {
private:
    string left_str = "({[";
    string ringh_str = ")}]";
    map<char,char> m1;
    stack<char> s1;
public:
    
    bool isValid(string s) {
        if (s == "") return true;
        if (s.length() % 2 != 0) return false;
        m1['('] = ')';
        m1['{'] = '}';
        m1['['] = ']';
        for (size_t i = 0; i < s.length(); i++)
        {
            if (left_str.find(s[i]) != string::npos)  //找到了左符号
            {
                s1.push(s[i]);
            }
            else if(ringh_str.find(s[i]) != string::npos)  //找到了右符号
            {
                if (s1.empty() || m1[s1.top()] != s[i]) return false;  //首次出现为右符号或不匹配
                s1.pop();
            }
        }
        if (s1.empty()) return true;
        return false;
    }
};


int main()
{
    Solution s;
    cout << s.isValid("([)]") << endl;
    return 0;
}