#include <iostream>

using namespace std;

int main()
{

    string s;

    getline(cin, s);

    cout << "s = " << s << endl;

    int len = s.length();
    int res = 0;

    cout << "s.length = " << len << endl;

    for (auto it = s.rbegin(); it < s.rend(); ++it)
    {
        if (*it == ' ')
        {
            break;
        }
        res++;
    }

    cout << res << endl;

    return 0;
}
// 64 位输出请用 printf("%lld")