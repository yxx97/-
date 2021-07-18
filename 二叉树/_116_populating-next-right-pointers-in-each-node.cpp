/*
    给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

    struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    }
    填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

    初始状态下，所有 next 指针都被设置为 NULL。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
};
class Solution1 {
public:
    Node* connect(Node* root) {
        if(!root||!root->left) return root;
        root->left->next = root->right;
        if(root->next){
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
        
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution2 {
public:
    Node* connect(Node* root) {
        if(root==nullptr) return nullptr;
        queue<Node*>q ;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            Node* pre = q.front();
            q.pop();
            if(pre->left) q.push(pre->left);
            if(pre->right) q.push(pre->right);
            for(int i=0;i<n-1;i++){
                pre->next = q.front();
                pre = pre->next;
                if(pre->left) q.push(pre->left);
                if(pre->right) q.push(pre->right);
                q.pop();
            }
        }
        return root;
        
    }
};