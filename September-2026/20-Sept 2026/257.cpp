class Solution {
public:
    void dfs(TreeNode* root, string path, vector<string>& ans) {
        if (root == nullptr)
            return;

        // Add current node to path
        if (!path.empty())
            path += "->";

        path += to_string(root->val);

        // If leaf node, store the path
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
            return;
        }

        // Explore left and right
        dfs(root->left, path, ans);
        dfs(root->right, path, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        dfs(root, "", ans);

        return ans;
    }
};
