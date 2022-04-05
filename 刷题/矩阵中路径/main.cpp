#include<vector>
#include<string>
using namespace std;

/*给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。


例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true

*/

class Solution {
public:
    //i,j为下一个访问坐标，k为字符串索引
    bool dfs(vector<vector<char>>& board, string& word, int i, int j,int k)
    {
        //当前节点越界或不是目标字符
        if(i >= row || i < 0 || j >= col || j < 0 || board[i][j] != word[k]) return false;
        //已经找到最后一个
        if(k == word.size() - 1) return true;
        //需要继续向其他节点遍历
        //将当前节点"剪枝"，在后续遍历过程重复查找
        board[i][j] = ' ';
        bool res = dfs(board,word,i+1,j,k+1) || dfs(board,word,i-1,j,k+1) || dfs(board,word,i,j+1,k+1) || dfs(board,word,i,j-1,k+1);
        board[i][j] = word[k];
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        for(int i = 0;i < row;i++)
        {
            for(int j = 0;j < col;j++)
            {
                if(dfs(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
private:
    int row,col;
};