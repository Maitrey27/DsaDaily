/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    unordered_set<int>st;
    void dfs(TreeNode* root, int x)
    {
        if(root==NULL)
        {
            return;
        }

        if(root->left!=NULL && root->left->val==-1)
        {
            root->left->val = 2*x+1;
            st.insert(root->left->val);
            dfs(root->left,root->left->val);
        }

        if(root->right!=NULL && root->right->val==-1)
        {
            root->right->val = 2*x+2;
            st.insert(root->right->val);

            dfs(root->right,root->right->val);

        }
    }
    FindElements(TreeNode* root) {
        if(root!=NULL)
        {
            root->val = 0;
        }
        st.insert(root->val);
        dfs(root,0);
    }
    
    bool find(int target) {
        if(st.find(target)==st.end())
        {
            return false;
        }

        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */