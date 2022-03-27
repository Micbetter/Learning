/*
快速排序原理：
快速排序算法有两个核心点，分别为 “哨兵划分” 和 “递归” 。

哨兵划分操作： 以数组某个元素（一般选取首元素）为 基准数 ，将所有小于基准数的元素移动至其左边，大于基准数的元素移动至其右边。

递归： 对 左子数组 和 右子数组 递归执行 哨兵划分，直至子数组长度为 1 时终止递归，即可完成对整个数组的排序。

*/


#include <vector>
using namespace std;


class solution{
public:
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void quicksort(vector<int>& nums, int l, int r)
{
    if(l >= r) return;
    int i = l, j = r;
    while (i < j)
    {
        while(i < j && nums[j] >= nums[l]) j--;  //从右侧找小的
        while(i < j && nums[i] <= nums[l]) i++;  //从左侧找大的
        swap(nums[i],nums[j]);
    }
    swap(nums[l],nums[i]);
    //递归排序子序列
    quicksort(nums,l,i-1);
    quicksort(nums,i+1,r);
    
}

void sort(vector<int> nums)
{
    quicksort(nums, 0, nums.size()-1);
}
};