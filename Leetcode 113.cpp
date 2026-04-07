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
    void dfs(TreeNode* cu, int tt, int sum, vector<vector<int>>&ans, vector<int>&path){   
        if(!cu) return;
        sum += cu->val;
        path.push_back(cu->val);

        if(!cu->left && !cu->right && sum == tt){
            ans.push_back(path);
        }
        dfs(cu->left, tt, sum, ans, path);
        dfs(cu->right, tt, sum, ans, path);

        path.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>path;
        dfs(root, targetSum, 0, ans, path);
        return ans;
    }
};
