/*
二分查找适用情况：
1.数组有序，如果无序，需要先排序

三个步骤：
1.排序 2.二分查找 3.后处理
*/

#include <vector>
using namespace std;

//第一种模板，循环
int binarySearch(vector<int>& nums, int target){
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

//搜索旋转排序数组
/*
整数数组 nums 按升序排列，数组中的值 互不相同 。
在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int k;
        if(nums.size() == 1)  //防止单一元素
        {
            if(nums[0] == target) return 0;
        }
        else{
        for(k = 0;k<nums.size() - 1;k++)
        {
            if(nums[k] == target) return k;
            if(nums[k] > nums[k+1])
            {
                break;
            } 
        }
        }
        if(k == nums.size() - 1) k = 0; //说明没有找到旋转点，k=0需要重头开始找
        //说明左侧没有找到target，直接在右侧找
        int left = k+1, right = nums.size() - 1;
        int mid = 0;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};
//第二种模板