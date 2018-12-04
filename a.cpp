#include <iostream>
#include <string>
#include <climits>
#include<priority_queue>
using namespace std;

int main()
{
    int a = INT_MIN;
    cout << sizeof(&a);
    system("pause");
    return 0;
}

void inOrder(TreeNode *root)
{
    stack<TreeNode *> S;
    S.push(root);
    while (!S.empty())
    {
        while (S.top()->left)
            S.push(S.top()->left);
        while (!S.empty())
        {
            auto cur = S.top();
            S.pop();
            helper(cur->val);
            if (cur->right)
            {
                S.push(cur->right);
                break;
            }
        }
    }
}