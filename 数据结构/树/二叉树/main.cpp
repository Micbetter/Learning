#include<vector>
#include<stack>
#include<string>
#include<queue>
using namespace std;


/*
二叉树定义：任意节点最多包含2棵子树
*/
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val):val(val),left(nullptr),right(nullptr){};
};


/*********前序遍历********/
//前序遍历首先访问根节点，然后遍历左子树，最后遍历右子树

//递归法
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res(0);
    if(root == nullptr) return res;
    else
    {
        res.push_back(root->val);
        //遍历左子树
        vector<int>&& temp = preorderTraversal(root->left);
        //添加
        res.insert(res.end(),temp.begin(),temp.end());
        //遍历右子树
        temp = preorderTraversal(root->right);
        res.insert(res.end(),temp.begin(),temp.end());
    }
    
    return res;
}

//迭代法
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res(0);
    stack<TreeNode*> temp;
    TreeNode* node = root;
    while ( !temp.empty() || node != nullptr)
    {
        while (node != nullptr)  //遍历左子树
        {
            res.emplace_back(node->val);
            temp.emplace(node);  //将当前节点入栈
            node = node->left;   //迭代左子节点
        }
        node = temp.top();
        temp.pop();
        node = node->right; //迭代右子节点
    }
    return res;
}



/*********中序遍历********/
//中序遍历是先遍历左子树，然后访问根节点，然后遍历右子树。
//TIPS:通过中序遍历一个二叉搜索树，可以得到一个增序的序列

//递归法
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res(0);
    if(root == nullptr) return res;
    else
    {
        vector<int>&& temp = inorderTraversal(root->left);
        res.insert(res.end(),temp.begin(),temp.end());
        res.push_back(root->val);
        temp = inorderTraversal(root->right);
        res.insert(res.end(),temp.begin(),temp.end());
    }
    
    return res;
}

//迭代法
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res(0);
    stack<TreeNode*> temp;
    TreeNode* node = root;
    while (node != nullptr || !temp.empty())  //当右侧不为空，进入内部循环；当右侧为空，栈不为空，出栈
    {
        while (node != nullptr)
        {
            temp.emplace(node);
            node = node->left;
        }
        node = temp.top();
        temp.pop();
        //左子节点为空，加入当前节点值
        res.emplace_back(node->val);
        //迭代右节点
        node = node->right;
    }
    
}



/*********后序遍历********/
//后序遍历是先遍历左子树，然后遍历右子树，最后访问树的根节点。
//值得注意的是，当你删除树中的节点时，删除过程将按照后序遍历的顺序进行。 也就是说，当你删除一个节点时，你将首先删除它的左节点和它的右边的节点，然后再删除节点本身。
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res(0);
    if(root == nullptr) return res;
    else
    {
        vector<int>&& temp = postorderTraversal(root->left);
        res.insert(res.end(),temp.begin(),temp.end());
        temp = postorderTraversal(root->right);
        res.insert(res.end(),temp.begin(),temp.end());
        res.push_back(root->val);
    }
    return res;
}


//迭代法
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res(0);
    stack<TreeNode*> temp;
    TreeNode* node = root;
    TreeNode* prev = nullptr;
    while (node != nullptr || !temp.empty())
    {
        while (node != nullptr)
        {
            temp.push(node);
            node = node->left;
        }
        node = temp.top();
        temp.pop();
        if(node->right == nullptr || node->right == prev)  //后面一个条件，表示该节点已被访问过，可以直接添加当前节点值了，不必再进入
        {
            res.push_back(node->val);
            prev = node;
            node = nullptr;
        }
        else
        {
            temp.push(node);
            node = node->right;
        }
        
    }
    
}

//层序遍历
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size() > 0)
        {
            vector<int> temp(0);
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node != nullptr)     //这里要注意，别忘了!!!!!
                {
                    temp.emplace_back(node->val);   
                    if(node->left != nullptr || node->right != nullptr)  //只要不是两边都是空
                    {
                        q.push(node->left);
                        q.push(node->right);
                    }
                }
            }
            res.emplace_back(temp);
        }
        return res;
    }
};

//返回一个二叉树的最大深度
int maxDepth(TreeNode* root) {
    if(root == nullptr) return 0;
    return max(maxDepth(root->left),maxDepth(root->right)) + 1;
}


//判断是否为对称二叉树：两个指针，一个向左，一个向右，分别比较值是否相同
bool check(TreeNode* left, TreeNode* right)
{
    if(!left && !right) return true;    //两边同时为空
    if(!left || !right) return false;   //两边一个为空
    return left->val == right->val && check(left->left,right->right) && check(left->right,right->left);
}
bool isSymmetric(TreeNode* root) {
    return check(root,root);
}


//路径和：判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum
//每遍历一个节点，减去该节点的值
bool hasPathSum(TreeNode* root, int targetSum) {
    if(root == nullptr) return false;
    if(root->left == nullptr && root->right == nullptr)  //找到叶子节点
    {
        if(root->val == targetSum) return true;
    }
    return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);
}


//二叉树的序列化与反序列化
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
    }
};
