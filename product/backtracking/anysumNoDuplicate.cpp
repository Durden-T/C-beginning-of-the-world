//LeetCode 39
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        if (target <= 0 || candidates.empty())
            return ans;
        if (candidates.size() == 1)
            if (!(target % candidates[0]))
            {
                vector<int> tmp(target / candidates[0], candidates[0]);
                ans.push_back(tmp);
                return ans;
            }
            else
                return ans;
        sort(candidates.begin(), candidates.end());
        if (candidates[0] > target)
            return ans;
        vector<int> path;
        subSum(candidates, target, 0, ans, path);
        return ans;
    }

  private:
    void subSum(vector<int> &a, int target, vector<int>::size_type start, vector<vector<int>> &ans, vector<int> &path)
    {
        if (!target)
        {
            ans.push_back(path);
            return;
        }
        for (auto i = start; i != a.size() && a[i] <= target; ++i)
        {
            path.push_back(a[i]);
            subSum(a, target - a[i], i, ans, path);
            path.pop_back();
        }
    }
};
