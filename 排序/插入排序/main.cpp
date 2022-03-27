#include<vector>
using namespace std;



class Solution{
public:

    void swap(int& a, int& b)
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    //交换插入排序
    void sort_1(vector<int>& nums)
    {
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t j = i; j > 0; j--)
            {
                if(nums[j] < nums[j-1])
                {
                    swap(nums[j],nums[j-1]);
                }
                else
                {
                    //提前终止
                    break;
                }
                
            }
            
        }
    }
    //移动插入排序
    void sort_2(vector<int>& nums)
    {
        for (size_t i = 0; i < nums.size(); i++)
        {
            int j = i;
            int number = nums[i];
            for (; j > 0; j--)
            {
                if(nums[j-1] > number)
                {
                    nums[j] = nums[j-1];
                }
                else
                {
                    break;
                }
            }
            nums[j] = number;
            
        }
        
    }
};