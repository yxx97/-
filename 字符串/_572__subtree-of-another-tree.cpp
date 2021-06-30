#include<iostream>
#include<string>

using namespace std;
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return postSerialize(root).find(postSerialize(subRoot)) != string::npos;

    }
    string postSerialize(TreeNode* root) {
		string s;
		postSerialize(root, s);
		return s;
	}
	//这里采用的是后续遍历，如果是前序遍历 s初始化应该为！
	 void postSerialize(TreeNode* root, string& s) {
         if(root == nullptr){
             s+="#!";
             return ;
         }
		
        postSerialize(root->left,s);
        postSerialize(root->right,s);
        
        s+=to_string(root->val);
        s += '!';
	}
};
int main(){
    
}
