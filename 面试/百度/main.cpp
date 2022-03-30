#include<vector>
#include<string>
#include<unordered_set>
using namespace std;


/*
一、判断数组中是否存在重复元素，数组长度为N，元素取值1-N

[1,2,2]-->true
[1,2,3,4]--?false

*/

bool Solution_1(vector<int>& nums)
{
    //第一种方法,遍历
    //第二种方法，新建一个长度为N的数组，记录每个元素出现的次数,O(N)
    vector<int> nums_n(nums.size(),0);
    for (auto& n:nums)
    {
        nums_n[n-1]++;
        if(nums_n[n-1] > 1) return false;
    }
    return true;
    //第三种方法，交换数组中的值，使得数组值与数组索引一致。降低空间复杂度
    //todo
    
}

/*
二、去除数组中的非数字、非字母、不考虑大小写，判断是否为回文字符串
*/
bool Solution_2(string& str)
{
    //step 1 筛选，大写转小写可使用  str[i] + 'a' - 'A'
    //step 2 判断
    //方法一：双指针
    int left = 0, right = str.size() - 1;
    while (left < right)
    {
        if(str[left] != str[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

/*
三、输出2^10000

*/

/*
四、判断链表是否有环
*/

struct Node
{
    Node* next;
    int val;
};


bool Solution_4(Node* node)
{
    //方法一：用一个集合来存储节点，如果已经存在，则有环
    unordered_set<Node*> node_set;
    while (node != nullptr)
    {
        if(node_set.count(node) == 1) return true;
        else node_set.insert(node);
        node = node->next;
    }
    //方法二：快慢指针，一个指针快，一个指针慢，如果有环，快指针必定会在环内套圈慢指针
    Node* slow = node;
    Node* quick = node;
    while (quick != nullptr)
    {
        if(slow == quick) return true;
        slow = slow->next;
        quick = quick->next;
        if(quick == nullptr)
        {
            break;
        }
        else
        {
            quick = quick->next;
        }
    }
    return false;
}

/*
5.输出斐波那契数列
*/
int Solution_5(int k)
{
    
}