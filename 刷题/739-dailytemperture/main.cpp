/*
根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。

例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。

*/

/*
思路：使用栈来存储没有找到高于温度的值，每遍历一个温度，便比较栈顶元素与当前温度，若当前温度比栈顶温度高，则可以通过下标来计算天数。栈内存储的温度（由下至上）始终为递减
*/



#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    // stack<pair<int, int>> help_stack;
    stack<int> help_stack;  //只存储下标
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size(), 0);
        for (size_t i = 0; i < T.size(); i++)
        {            
            while(!help_stack.empty() && T[i] > T[help_stack.top()]) //最新的元素大于栈顶元素
            {
                result[help_stack.top()] = i - help_stack.top();
                help_stack.pop();
            }
            help_stack.push(i);
            
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int>  test;
    test = {73,74,75,71,69,72,76,73};
    vector<int> r = s.dailyTemperatures(test);
    for (size_t i = 0; i < test.size(); i++)
    {
        cout << r[i] << endl;
    }
    
    return 0;
}