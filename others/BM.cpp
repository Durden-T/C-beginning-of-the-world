#include <string>
#include <iostream>
using namespace std;

int *getBc(const string &p)
{
    //256是字符表的规模大小(ACSII)
    int *bc = new int[256];

    for (int i = 0; i < 256; ++i)
        bc[i] = -1;

    for (int i = 0; i < p.length(); ++i)
        bc[p[i]] = i;
    return bc;
}

int *getGs(const string &p)
{
    const int len = p.length();
    const int lastIndex = len - 1;
    int suff[len];
    suff[len - 1] = len;
    for (int i = len - 2, num; i >= 0; --i)
    {
        for (num = 0; num <= i && p[i - num] == p[len - num - 1]; ++num)
            ;
        suff[i] = num;
    }

    int *gs = new int[len];
    //找不到对应的子串和前缀
    for (int i = 0; i < len; ++i)
        gs[i] = len;
    //找前缀
    for (int i = lastIndex; i >= 0; --i)
        //存在我们想要的前缀
        if (suff[i] == i + 1)
            for (int j = 0; j < lastIndex - i; ++j)
                if (gs[j] == len)
                    gs[j] = lastIndex - i;

    //找中间的匹配子串
    for (int i = 0; i < lastIndex; ++i)
        gs[lastIndex - suff[i]] = lastIndex - i;
    return gs;
}

int BM(const string &s, const string &p)
{
    int *bc = getBc(p);
    int *gs = getGs(p);
    //patAt指向了当前pat和text对齐的位置
    int start = 0;
    //cmp指向了当前比较的位置
    int cur;
    while (start + p.length() <= s.length())
    {
        //如果匹配成功，cmp就会来到-1的位置上
        //start + cur 指向了text上当前比较的字符
        for (cur = p.length() - 1; cur >= 0 && p[cur] == s[start + cur]; --cur)
            ;

        if (cur == -1)
            break;
        else
            start += max(gs[cur], cur - bc[s[start + cur]]);
        //start += max(gs[cur], (int)(bc[s[start + cur]]-(p.length()-1-cur)));
    }
    delete[] bc;
    delete[] gs;
    return start + p.length() <= s.length() ? start : -1;
}
int main()
{
    string a = "bacbababadababacambabacaddababacasdsd", b = "ababaca";
    cout << BM(a, b);
    system("pause");
    return 0;
}
