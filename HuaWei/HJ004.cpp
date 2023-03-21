#include <iostream>
#include <vector>

using namespace std;

int main() {

    string str;

    string str_8;
    vector<string> vector_str;

    cin >> str;

    int i = 0;
    for (auto& it : str) {
        if ((i + 1) % 8 != 0) {
            str_8.append(1, it);
        } else {
            str_8.append(1, it);
            vector_str.push_back(str_8);
            str_8.clear();
        }
        ++i;
    }

    if (str_8 == "") {
    } else if (str_8.length() < 8) {
        str_8.append(8 - str_8.length(), '0');
        vector_str.push_back(str_8);
    } else {
        vector_str.push_back(str_8);
    }

    for (auto& it : vector_str) {
        cout << it << endl;
    }

}
// 64 位输出请用 printf("%lld")