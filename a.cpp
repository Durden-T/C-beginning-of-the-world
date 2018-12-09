#include <iostream>
#include <string>
#include <climits>
#include <set>
using namespace std;

int main()
{
    multiset<int> a;
    a.insert(3);
    a.insert(3);
    a.insert(3);
    a.erase(3);
    cout << a.size() << endl;
    for (int i : a)
        cout << i << endl;
    system("pause");
    return 0;
}
