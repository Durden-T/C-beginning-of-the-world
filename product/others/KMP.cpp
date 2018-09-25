#include <string>
#include <iostream>
using namespace std;
inline void getNext(string &p,int next[])
{
        next[0]=-1;//next[0]初始化为-1，-1表示不存在相同的最大前缀和最大后缀
        int i=-1;//i初始化为-1
        for (int j=1; j<p.size(); j++)
        {
                while (i>-1&&p[i+1]!=p[j]) //如果下一个不同，那么i就变成next[i]，注意next[i]是小于i的，无论i取任何值。
                        i=next[i]; //往前回溯
                if (p[i+1]==p[j]) //如果相同，i++
                        i++;
                next[j]=i;//这个是把算的i的值（就是相同的最大前缀和最大后缀长）赋给next[j]
        }
}
int KMP(string &s,string &p)
{
        if(!s.empty())
        {
                int next[s.size()];
                getNext(s,next);
                for (int i=0,j=-1; i<s.size(); i++)
                {
                        while (j>-1&& p[j+1]!=s[i]) //p和s不匹配，且k>-1（表示p和s有部分匹配）
                                j=next[j]; //往前回溯
                        if (p[j+1]==s[i])
                                j++;
                        if (j==p.size()-1)//说明j移动到p的最末端
                        {
                                //cout << "在位置" << i-p.size()+1<< endl;
                                //j = -1;//重新初始化，寻找下一个
                                //i = i-p.size()+1;//i定位到该位置，外层for循环i++可以继续找下一个（这里默认存在两个匹配字符串可以部分重叠），感谢评论中同学指出错误。
                                return i-p.size()+1;//返回相应的位置
                        }
                }
        }
        return -1;

}

int main()
{
        cout<<KMP("ababaca","ababaca");
        return 0;
}
