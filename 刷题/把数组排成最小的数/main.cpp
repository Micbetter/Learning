#include<vector>
#include<string>
using namespace std;


/*
输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。



*/

class Solution {
public:
    void quickSort(vector<string>& strs, int l, int r)
    {
        if(l>=r) return;
        int i = l,j = r;
        while(i < j)
        {
            while(i < j && strs[i] + strs[l] <= strs[l] + strs[i]) i++;
            while(i < j && strs[l] + strs[j] <= strs[j] + strs[l]) j--;
            swap(strs[i],strs[j]);
        }
        swap(strs[i],strs[l]);
        quickSort(strs,l,i-1);
        quickSort(strs,i+1,r);
    }

    string minNumber(vector<int>& nums) {
        
        vector<string> strs;
        for(int i = 0; i < nums.size(); i++)
            strs.push_back(to_string(nums[i]));
        quickSort(strs, 0, strs.size() - 1);
        string res;
        for(string s : strs)
            res.append(s);
        return res;

        
    }
};