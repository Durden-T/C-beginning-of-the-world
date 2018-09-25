#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    return kSum(nums, target, 4);
}

vector<vector<int>> kSum(vector<int> &nums, int target, int k)
{
    vector<vector<int>> result;
    if (nums.empty() || k <= 0 || nums.size() < k)
        return result;
    sort(nums.begin(), nums.end());
    if (k == 1)
        if (binary_search(nums.begin(), nums.end(), target))
            return {{target}};
        else
            return result;
    vector<int> path;
    doKSum(nums, target, k, 0, result, path);
    return result;
}

void doKSum(vector<int> &a, int target, int k, vector<int>::size_type start, vector<vector<int>> &result, vector<int> &path)
{
    int max = a.back();
    if (a[start] * k > target || max * k < target)
        return;
    if (k == 2)
    {
        vector<int>::size_type left = start, right = a.size() - 1;
        while (left < right)
        {
            if (a[left] + a[right] < target)
                ++left;
            else if (a[left] + a[right] > target)
                --right;
            else
            {
                result.push_back(path);
                result.back().push_back(a[left++]);
                result.back().push_back(a[right--]);
                while (left < right && a[left] == a[left - 1])
                    ++left;
                while (left < right && a[right] == a[right + 1])
                    --right;
            }
        }
    }
    else
    {
        for (vector<int>::size_type i = start; i != a.size() - k + 1 && a[i] * k <= target; ++i)
        {
            while (i > start && a[i] == a[i - 1])
                ++i;
            if (a[i] + max * (k - 1) < target)
                continue;
            if (a[i] * k == target)
            {
                if (a[i] == a[i + k - 1])
                {
                    result.push_back(path);
                    result.back().insert(result.back().end(), k, a[i]);
                }
                return;
            }
            path.push_back(a[i]);
            doKSum(a, target - a[i], k - 1, i + 1, result, path);
            path.pop_back();
        }
    }
}
