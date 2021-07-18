#include<string>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        postSerialize(root,res);
        return res;
        
    }
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
    TreeNode * redeserialize(vector<string>& v){
        if(v.back() =="#" ){
            v.pop_back();

            return nullptr;
        }
        TreeNode * root = new TreeNode(stoi(v.back()));
        v.pop_back();
        root->right = redeserialize(v);
        root->left = redeserialize(v);
        return root;

    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v;
        string res;
        for(auto& c:data){
            if(c=='!'){
                v.push_back(res);
                res.clear();
            }else{
                res += c;
            }
        }
        if(!res.empty()){
            v.push_back(res);
        }
        return redeserialize(v);
        
    }
};