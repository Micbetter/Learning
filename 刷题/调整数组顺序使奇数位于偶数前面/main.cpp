/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。

输入：nums = [1,2,3,4]
输出：[1,3,2,4] 
注：[3,1,2,4] 也是正确的答案之一。

*/
#include<vector>
using namespace std;


class Solution {
public:
    bool judge(const int& num)
    {
        return num % 2 == 0;
    }

    vector<int> exchange(vector<int>& nums) {
        //定义2个指针，一个从前找偶数，一个从后找奇数
        int i = 0,j = nums.size() - 1;
        while(i < j)
        {
            if(judge(nums[i]))
            {
                nums.emplace_back(nums[i]);
                nums.erase(nums.begin() + i);
                //由于抽出了一个元素，因此i的值不变，j的值减1
                j--;
            }
            else
            {
                i++;
            }
            if(!judge(nums[j]))
            {
                nums.insert(nums.begin(),nums[j]);
                nums.erase(nums.begin() + j + 1);   //!!!!这里是陷阱，erase时需要索引+1
                i++;
            }
            else
            {
                j--;
            }
        }
        return nums;
    }

    vector<int> exchange(vector<int>& nums) {
        //定义2个指针，一个从前找偶数，一个从后找奇数
        int i = 0,j = nums.size() - 1;
        while(i < j)
        {
            while(i < j && !judge(nums[i])) i++;
            while(i < j && judge(nums[j])) j--;
            swap(nums[i],nums[j]);
        }
        return nums;
    }
};
