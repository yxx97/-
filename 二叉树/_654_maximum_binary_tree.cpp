/*
    给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的 最大二叉树 定义如下：
        1.二叉树的根是数组 nums 中的最大元素。
        2.左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树。
        3.右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树。
    返回有给定数组 nums 构建的 最大二叉树 
    链接：https://leetcode-cn.com/problems/maximum-binary-tree

*/
#include<vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructree(nums,0,nums.size()-1);

    }
    TreeNode * constructree(vector<int>& nums,int left,int right){
        if(left>right) return nullptr;

        int maxindex = left;
        for(int i = left;i<=right;i++){
            if(nums[i]>nums[maxindex]){
                maxindex = i;
            }
        }
        TreeNode * root = new TreeNode(nums[maxindex]);
        root->left = constructree(nums,left,maxindex-1);
        root->right = constructree(nums,maxindex+1,right);
        return root;
    }
};