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
    vector<int>A;
    void inorder(TreeNode *root)
    {
        if(root)
        {
            inorder(root->left);
            A.push_back(root->val);
            inorder(root->right);
        }
    }
    TreeNode * convert(int start,int end)
    {
        if(start<=end)
        {
            TreeNode *S;
            int mid= (start+end)/2;
            S=new TreeNode(A[mid]);
            S->left=convert(start,mid-1);
            S->right=convert(mid+1,end);
            return S;
        }
        return NULL;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        int start=0;
        int end=A.size()-1;
        TreeNode *Ans;
        Ans=convert(start,end);
        return Ans;
    }
};
