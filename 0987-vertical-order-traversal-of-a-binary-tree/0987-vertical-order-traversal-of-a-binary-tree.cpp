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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mpp;
        q.push({root, {0,0}});
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            mpp[x][y].insert(node -> val);
            if (node -> left) q.push({node -> left, {x - 1, y + 1}});
            if (node -> right) q.push({node -> right, {x + 1, y + 1}});
        }
        for (auto p : mpp) {
            vector<int> ans;
            for (auto x : p.second) {
                for (auto j : x.second) {
                    ans.push_back(j);
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};