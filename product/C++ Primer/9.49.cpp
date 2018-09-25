#include <iostream>
#include <string>
using namespace std;
int main()
{
        string reserve("aceimnorsuvwxz");
        string temp;
        string ans;
        while(cin>>temp)
        {
                if(temp.find_first_not_of(reserve)==string::npos&&temp.size()>ans.size())
                        ans=temp;
        }
        cout<<ans<<endl;
        return 0;
}
