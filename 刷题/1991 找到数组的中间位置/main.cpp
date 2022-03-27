/*
给你一个下标从 0 开始的整数数组 nums ，请你找到 最左边 的中间位置 middleIndex （也就是所有可能中间位置下标最小的一个）。
中间位置 middleIndex 是满足 nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1] 的数组下标。
如果 middleIndex == 0 ，左边部分的和定义为 0 。类似的，如果 middleIndex == nums.length - 1 ，右边部分的和定义为 0 。
请你返回满足上述条件 最左边 的 middleIndex ，如果不存在这样的中间位置，请你返回 -1 。
示例：
输入：nums = [1, 7, 3, 6, 5, 6]
输出：3
解释：
中心下标是 3 。
左侧数之和 sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11 ，
右侧数之和 sum = nums[4] + nums[5] = 5 + 6 = 11 ，二者相等。
*/

/*
知识点：
1.可只计算一半元素之和，乘以2，再加上中心元素进行判断
*/


#include <vector>
using namespace std;


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long left = 0;
        long sum = 0;
        for(auto& n:nums)
        {
            sum += n;
        }
        long right = sum - nums[0];
        if(left == right) return 0;
        for(int i = 1;i<nums.size();i++)
        {
            left += nums[i-1];
            right -= nums[i];
            if(left == right) return i;
        }
        return -1;
    }
};