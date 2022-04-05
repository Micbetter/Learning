/*
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

输入：m = 2, n = 3, k = 1
输出：3

*/
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    int sum(int num)
    {
        int res = 0;
        while(num)
        {
            res = res + (num % 10);
            num = num / 10;
        }
        return res;
    }

    int accessNum(vector<vector<int>>& visited,int m, int n, int i, int j, int k)
    {
        int res = 0;
        //确定终止条件
        if(i >= m || j >= n || sum(i) + sum(j) > k || visited[i][j] == 1) return res;
        //记录当前被访问节点，以防重复访问，剪枝
        visited[i][j] = 1;
        res = res + 1 + accessNum(visited,m,n,i+1,j,k) + accessNum(visited,m,n,i,j+1,k);//只向右和向下查找即可，因为是从(0,0)开始查找
        return res;
    }

    int movingCount(int m, int n, int k) {
        vector<int> temp(n);
        vector<vector<int>> visited(m,temp);
        return accessNum(visited,m,n,0,0,k);
    }
};