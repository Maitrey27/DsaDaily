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
    int n;

    //by reference so that i get the updated value after recursive calls
    TreeNode* solve(int &i, int depth, string &s)
    {
        if(i>=n)
        {
            return NULL;
        }

        //i will point on curr(digit)
        int j =i;
        //move j till we have (--)
        while(j<n && s[j]=='-')
        {
            j++;
        }

        //now j pointer is on some digit and the diff beween j-i is depth so check dash
        int dash = j-i;

        if(depth!=dash)
        {
            //invalid
            return NULL;
        }

        //valid dpeth==dash
        i+=dash;

        int num =0;

        while(i<n && isdigit(s[i]))
        {
            num = (num*10) + (s[i]-'0');
            i++;
        }

        TreeNode* root = new TreeNode(num);

        root->left  = solve(i,depth+1,s);
        root->right = solve(i,depth+1,s);

        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        n = traversal.length();

        int i =0;
        int depth =0;

        return solve(i,depth,traversal);
    }
};