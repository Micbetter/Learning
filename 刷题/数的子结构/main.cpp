/*

输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
B是A的子结构， 即 A中有出现和B相同的结构和节点值。

输入：A = [1,2,3], B = [3,1]
输出：false


*/

#include<vector>
#include<iostream>
#include<thread>
#include<stack>
#include<functional>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    //判断是否为子树
    bool recur(TreeNode* A, TreeNode* B)
    {
        if(B == nullptr) return true;   //B已经遍历完了
        if(A == nullptr) return false;  //A已经遍历完了
        if(A->val == B->val)    //当前遍历节点值相同
        {
            return recur(A->left,B->left) && recur(A->right,B->right);
        }
        return false;
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        //通过迭代，找到与B的值相同的节点
        if(B == nullptr) return false;
        TreeNode* node = A;
        stack<TreeNode*> stk;
        while (node != nullptr || !stk.empty())
        {
            //迭代左子节点
            while (node != nullptr)
            {
                stk.push(node);
                //判断顶点是否相同
                if(node->val == B->val)
                {
                    if(recur(node, B)) return true;
                }
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            node = node->right;
        }
        return false;
    }
};