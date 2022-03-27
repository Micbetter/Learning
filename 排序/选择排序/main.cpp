/*
冒泡排序：发现满足条件的值时就进行交换
选择排序：全部比较完成后，再进行交换

时间复杂度都是O(n^2)，空间复杂度O(1)

冒泡排序是稳定的，选择排序是不稳定的。即选择排序在排序完成后，原数组中值相同元素的相对顺序在排序后数组中可能发生了变化
冒泡排序可以进行改变，最好的时间复杂度可以做到O(n)
*/


#include <vector>
using namespace std;

class Solution {
public:
    inline void swap(int& a, int& b)
    {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
    void sort(vector<int> nums)
    {
        for (size_t i = 0; i < nums.size(); i++)
        {
            //记录最小值的下标
            int min_index = i;
            for (size_t j = i+1; j < nums.size(); j++)
            {
                if(nums[j] < nums[min_index]) min_index = j;
            }
            //交换
            swap(nums[i],nums[min_index]);
        }
        
    }
};