/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = buildTree(nums, 0, nums.size()-1);
        return root;
    }
    TreeNode* buildTree( vector<int>& nums, int startIndex, int endIndex)
    {
        if(startIndex > endIndex)
        {
            return NULL;
        }
        else
        {
            int mid = (startIndex+endIndex)/ 2.0; 
            TreeNode* newNode = new TreeNode(nums[mid]);
            newNode->left = buildTree (nums, startIndex, mid-1 ); 
            newNode->right = buildTree(nums, mid+1, endIndex );
            return newNode;
        }
    }
};