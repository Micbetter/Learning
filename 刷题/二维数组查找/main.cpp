/*
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/
#include<vector>
using namespace std;


class Solution_1 {
public:
    bool dfs(vector<vector<int>>& matrix, int row, int col, int target, int i, int j)
    {
        if(i >= row || j >= col) return false;
        if(matrix[i][j] != target)
        {
            if(i+1 < row-1)  //右侧还有地方
            {
                if(matrix[i+1][j] > target)
                {
                   return dfs(matrix,row, col,target,i,j+1); 
                }
            }
            if(j+1 < col-1)  //下侧还有地方
            {
                if(matrix[i][j+1] > target)
                {
                   return dfs(matrix,row,col,target,i+1,j); 
                }
            }
            return dfs(matrix,row,col,target,i+1,j) || dfs(matrix,row,col,target,i,j+1);
        }
        else
        {
            return true;
        }
    }


    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int row = matrix.size();
        int col = matrix[0].size();
        return dfs(matrix,row,col,target,0,0);
    }
};

//将数组左旋转45度，转变成为一个二叉搜索树
class Solution_2 {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int row = matrix.size();
        int col = matrix[0].size();        
        int i = 0, j = col-1;
        while (i >=0 && i < row && j >= 0 && j < col)
        {
            if(matrix[i][j] == target)
            {
                return true;
            }
            else if(matrix[i][j] > target)
            {
                //向左侧找
                j--;
                if(j >= col) return false;
            }
            else
            {
                //向右找
                i++;
                if(i >= row) return false;
            }
            
        }
        return false;
    }
};