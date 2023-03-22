#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string str;

    while (cin >> str)
    {
        // 1.长度检查
        if (str.size() <= 8)
        {
            cout << "NG" << endl;
            continue;
        }

        // 2.包含大小写字母、数字、其他符号四种字符中至少三种
        vector<int> condition(4, 0);
        for (auto ch : str)
        {
            if (ch >= '0' && ch <= '9')
            {
                condition[0] = 1;
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                condition[1] = 1;
            }
            else if (ch >= 'a' && ch <= 'z')
            {
                condition[2] = 1;
            }
            else
            {
                condition[3] = 1;
            }
        }

        int count = 0;
        int i = 0;
        for (auto n : condition)
        {
            cout << "[debug]: condition[" << i << "] = " << n << endl;
            count += n;
            i++;
        }
        if (count < 3)
        {
            cout << "NG" << endl;
            continue;
        }

        // 3.不能有长度大于 2 的包含公共元素的子串重复
        bool flag = true;
        for (int i = 0; i < str.size(); ++i)
        {
            // substr是从i截取子串，长度为n
            // 第一个参数是位置，第二个是长度
            // string substr (size_t pos = 0, size_t len = npos) const;
            string sub_str = str.substr(i, 3);

            // size_t find (const string& str, size_t pos = 0) const noexcept;
            size_t found = str.find(sub_str, i + 3); // 从当前子串之后开始查找

            /*
                size_t 是一些C/C++标准在stddef.h中定义的,
                size_t类型表示“C中任何对象所能达到的最大长度”
                它是 无符号整数
             */

            if (found != string::npos)
            {
                // 有重复
                cout << "NG" << endl;
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cout << "OK" << endl;
        }
    }

    return 0;
}
