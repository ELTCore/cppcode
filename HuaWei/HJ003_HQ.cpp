#include <iostream>
#include <set>

using namespace std;

int main() {

    int length = 0;

    cin >> length;

    set<int> hashSet;

    for (int i = 0; i < length; ++i) {
        int t = 0;
        cin >> t;
        hashSet.emplace(t);
    }

    for (auto it = hashSet.begin(); it != hashSet.end(); ++it) {
        cout << *it << endl;
    }

}
// 64 位输出请用 printf("%lld")