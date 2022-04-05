
#include<vector>
#include<iostream>
using namespace std;

// void mergeSort(vector<int>& nums, int l, int r) {
//     // 终止条件
//     if (l >= r) return;
//     // 递归划分
//     int m = (l + r) / 2;
//     mergeSort(nums, l, m);
//     mergeSort(nums, m + 1, r);
//     // 合并阶段
//     vector<int> tmp(r - l + 1);             // 暂存需合并区间元素
//     for (int k = l; k <= r; k++)
//         tmp[k - l] = nums[k];
//     int i = 0, j = m - l + 1;       // 两指针分别指向左/右子数组的首个元素
//     for (int k = l; k <= r; k++) {  // 遍历合并左/右子数组
//         if (i == m - l + 1)
//             nums[k] = tmp[j++];
//         else if (j == r - l + 1 || tmp[i] <= tmp[j])
//             nums[k] = tmp[i++];
//         else {
//             nums[k] = tmp[j++];
//         }
//     }
// }


void mergeSort(vector<int>& nums, int left, int right)
{
    //划分阶段
    if(left >= right) return;
    int m = left + (right - left) / 2;
    mergeSort(nums,left,m);
    mergeSort(nums,m+1,right);
    //合并阶段
    //将数组中的left--->right，提前保存
    vector<int> temp(right-left+1);
    for (int i = 0; i < right-left+1; i++)
    {
        temp[i] = nums[left + i];
    }
    //建立两个指针分别指向两个数组的头部
    int i = 0, j = m - left + 1;
    //比较大小，移动指针
    for (size_t k = left; k <= right; k++)   //遍历nums[left]到nums[right]
    {
        if(i == m - left + 1)  //左指针已经移动到了右数组的起始位置，说明左侧数据已经全部更新，剩下只需要更新右侧数据
        {
            nums[k] = temp[j];
            j++;
        }
        else if(j == right - left + 1 || temp[i] < temp[j])  //右指针已经移到了数组最右端，说明右侧数据已经全部更新，剩下只需要更新左侧数据
        {
            nums[k] = temp[i];
            i++;
        }
        // if(temp[i] < temp[j])
        // {
        //     nums[k] = temp[i];
        //     i++;
        // }
        else  //这个条件不能与上面的合并，顺序也不能改变，条件表示的是temp[i] >= temp[j]
        {
            nums[k] = temp[j];
            j++;
        }
        
    }
    
    
}


int main()
{
    // 调用
    vector<int> nums = { 4, 1, 3, 2, 5, 1 };
    mergeSort(nums, 0, nums.size() - 1);
    cout << "end" << endl;
}



