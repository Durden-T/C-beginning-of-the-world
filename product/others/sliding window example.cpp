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

using namespace std; 


/*Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".*/

class Solution
{
  public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        if (p.empty() || s.size() < p.size())
            return ans;
        map<char, int> map;
        for (char c : p)
            ++map[c];
        int begin = 0, end = 0;
        int counter = map.size();
        while (end < s.size())
        {
            if (map.count(s[end]))
                if (!--map[s[end]])
                    --counter;
            ++end;
            while (!counter)
            {
                if (end - begin == p.size())
                    ans.emplace_back(begin);
                if (map.count(s[begin]))
                    if (++map[s[begin]] > 0)
                        ++counter;
                ++begin;
            }
        }
        return ans;
    }
};