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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int>ans;

        if(root==NULL)
        {
            return ans;
        }

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty())
        {
            int n = q.size(); 

            //level by level processing
            for (int i = 0; i < n; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                // If it's the last node at this level, add it to the result
                if (i == n - 1) {
                    ans.push_back(curr->val);
                }

                // Enqueue the left and right children (if they exist)
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
        }

        return ans;

    }
};