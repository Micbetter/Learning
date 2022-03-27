#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;


/*
知识点：unorder_set  速度快，适用于无需排序、快速索引
        BFS：利用队列进行BFS搜索
        字符加减   '3'-'0'
*/


class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> l(deadends.begin(),deadends.end());
        if (l.count("0000"))
        {
            return -1;
        }
        
        
        queue<string> q;
        q.push("0000");
        unordered_set<string> v;  //用于记录str是否被用过
        v.insert("0000");
        
        int step = 0;
        int dir[2] = {-1, 1};  //用于处理字符+1 -1
        while (!q.empty())
        {
            step++;
            int size = q.size();
            //遍历点
            for (size_t i = 0; i < size; i++)
            {
                string str = q.front();
                q.pop();    //弹出已处理点
                //根据当前str添加临近点
                for (size_t j = 0; j < 4; j++)
                {
                    for (size_t k = 0; k < 2; k++)
                    {
                        char temp = str[j];  //记录当前字符，因为后面还需要使用str的值，防止发生改变
                        str[j] = (str[j] - '0' + 10 + dir[k]) % 10 + '0';
                        //判断是否为target
                        if(str == target)
                        {
                            return step;
                        }
                        //判断str是否为deadends，是否已经处理过
                        if(l.count(str) == 0 && v.count(str) == 0)
                        {
                            q.push(str);
                            v.insert(str);
                        }
                        str[j] = temp;
                        
                    }
                    
                }
                
                
            }
            
        }
        return -1;
        
    }
};
