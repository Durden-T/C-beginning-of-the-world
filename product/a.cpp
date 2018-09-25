#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <climits>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <iterator>
#include <numeric>

using namespace std;

static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();

class Solution
{
    int ans = 0;

  public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int choose = 0;
        if (choose == 0)
        {
            if (!root)
                return 0;
            helper(root);
            return ans;
        }
        else if (choose == 1)
        {
            ans = 1;
            depth(root);
            return ans - 1;
        }
    }

  private:
    void helper(TreeNode *root)
    {
        int sum = 0;
        if (!root->left && !root->right)
            root->val = 0;
        else if (root->left && root->right)
        {
            helper(root->left);
            helper(root->right);
            root->val = max(root->left->val, root->right->val) + 1;
            sum = root->left->val + root->right->val + 2;
        }
        else if (root->left)
        {
            helper(root->left);
            root->val = root->left->val + 1;
            sum = root->val;
        }
        else
        {
            helper(root->right);
            root->val = root->right->val + 1;
            sum = root->val;
        }
        ans = max(ans, sum);
    }

    int depth(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        ans = max(ans, l + r + 1);
        return max(l, r) + 1;
    }
};