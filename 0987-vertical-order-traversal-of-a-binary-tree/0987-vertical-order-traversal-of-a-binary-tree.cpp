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
        map<int, map<int, multiset<int>>> mpp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0,0}});
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            TreeNode* curr = node.first;
            int x = node.second.first; int y = node.second.second;
            mpp[x][y].insert(curr -> val);
            if (curr -> left) {
                q.push({curr -> left, {x-1,y+1}});
            }
            if (curr -> right) {
                q.push({curr -> right, {x+1,y+1}});
            }
        }
        for (auto p : mpp) {
            vector<int> x;
            for (auto j : p.second) {
                x.insert(x.end(),j.second.begin(), j.second.end());
            } 
            res.push_back(x);
        }
        return res;
    }
};