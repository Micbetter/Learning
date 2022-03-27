/*
冒泡排序是入门级的算法，但也有一些有趣的玩法。通常来说，冒泡排序有三种写法：

一边比较一边向后两两交换，将最大值 / 最小值冒泡到最后一位；
经过优化的写法：使用一个变量记录当前轮次的比较是否发生过交换，如果没有发生交换表示已经有序，不再继续排序；
进一步优化的写法：除了使用变量记录当前轮次是否发生交换外，再使用一个变量记录上次发生交换的位置，下一轮排序时到达上次交换的位置就停止比较。

*/


#include <vector>
using namespace std;


class solution{
public:
    // inline void swap(int& a, int& b)
    // {
    //     int temp;
    //     temp = a;
    //     a = b;
    //     b = temp;
    // }

    inline void swap(int& a, int& b)
    {
        //不引入第三方变量的条件下完成交换
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;

        //或者
        // a = a + b;
        // b = a - b;
        // a = a - b;

    }

    void sort(vector<int> nums)
    {
        //将最大值移到右侧，升序
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t j = 0; j < nums.size() - i; j++)
            {
                if(nums[j] > nums[j+1])
                {
                    swap(nums[j],nums[j+1]);
                }
            } 
        }
        //将最小值移到右侧，降序
        // for (size_t i = 0; i < nums.size(); i++)
        // {
        //     for (size_t j = 0; j < nums.size() - i; j++)
        //     {
        //         if(nums[j] < nums[j+1])
        //         {
        //             swap(nums[j],nums[j+1]);
        //         }
        //     } 
        // }
        
    }

    void sort_v1(vector<int> nums)
    {
        bool swapped = true;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if(!swapped) break;
            swapped = false;
            for (size_t j = 0; j < nums.size()-i; j++)
            {
                if(nums[j] > nums[j+1])
                {
                    swap(nums[j],nums[j+1]);
                    swapped = true;
                }
            }
            
        }
        
    }
};