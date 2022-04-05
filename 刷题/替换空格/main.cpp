//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
#include<string>
using namespace std;


class Solution {
public:
    //使用系统api
    string replaceSpace(string s) {
        int index = 0;
        while (s.find(' ',index) != string::npos)
        {
            int i = s.find(' ');
            s.replace(i,1,"%20");
            index = i + 3;
        }
        return s;
    }

    //不使用api
    string replaceSpace(string s) {
        int index = 0;
        string res = "";
        for (size_t i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                res+="%20";
            }
            else
            {
                res += s[i];
            }
            
        }
        return res;
    }
};