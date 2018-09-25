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

using namespace std;

/*static int __initialSetup = [] {
    ios::sync_with_stdio(false); // toggle off cout & cin, instead, use printf & scanf
    cin.tie(nullptr);            // untie cin & cout
    return 0;
}();*/
void helper(string &line)
{
    for (int i = 0; i < line.size(); ++i)
    {
        if (line[i] == '_')
        {
            line[i] = '<';
            line.insert(++i, "em>");
            while (line[i] != '_')
                ++i;
            line[i] = '<';
            line.insert(i + 1, "/em>");
            i += 4;
        }
        if (line[i] == '[')
        {
            int start = i++;
            string text = "", link = "";
            while (line[i] != ']')
                text += line[i++];
            i += 2;
            while (line[i] != ')')
                link += line[i++];
            string t = "<a href=\"" + link + "\">" + text + "</a>";
            line.replace(start, i - start + 1, t);
            i = start + t.size();
        }
    }
}

int main()
{
    vector<string> ans;
    string line;
    string ss = "<p>", se = "</p>", ls = "<li>", le = "</li>";
    bool list = false, section = false;
    int level, i;
    while (getline(cin, line))
    {
        if (list && line.empty())
        {
            ans.emplace_back("</ul>");
            list = false;
        }
        if (section && line.empty())
        {
            ans.back() += se;
            section = false;
        }
        if (line.empty())
            continue;
        char c = line[0];
        switch (c)
        {
        case '#':
            level = 1;
            for (i = 1; i < line.size() && line[i] == '#'; ++i)
                ++level;
            while (line[i] == ' ')
                ++i;
            ans.emplace_back("<h" + to_string(level) + '>' + line.substr(i) + "</h" + to_string(level) + '>');
            break;

        case '*':
            if (!list)
            {
                ans.emplace_back("<ul>");
                list = true;
            }
            for (i = 1; i < line.size() && line[i] == ' '; ++i)
                ;
            ans.emplace_back(ls + line.substr(i) + le);
            break;

        default:
            if (!section)
            {
                ans.emplace_back(ss + line);
                section = true;
            }
            else
                ans.emplace_back(line);
        }
    }
    if (list)
        ans.emplace_back(le);
    if (section)
        ans.back() += se;
    for (auto &s : ans)
    {
        helper(s);
        cout << s << endl;
    }
    getchar();
    getchar();
    getchar();
    return 0;
}