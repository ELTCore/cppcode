#include <iostream>
#include <cctype>

using namespace std;

int main() {

    string str;
    char targetCh;
    int res = 0;

    getline(cin, str);
    cin >> targetCh;

    targetCh = tolower(targetCh);

    for (auto ch : str) {
        if (tolower(ch) == targetCh) {
            ++res;
        }
    }

    cout << res << endl;

    return 0;
}
// 64 位输出请用 printf("%lld")