#include <iostream>
#include <vector>

using namespace std;

static void checkStringAndMove(vector<char> vector_string, int &x, int &y)
{
    if (vector_string.size() < 2 || vector_string.size() > 3)
    {
        return;
    }

    // for (auto it : vector_string)
    // {
    //     cout << it;
    // }
    // cout << endl;

    if (vector_string.size() == 2)
    {
        if (vector_string[1] < '0' || vector_string[1] > '9')
        {
            return;
        }

        switch (vector_string[0])
        {
        case 'A':
            x -= (vector_string[1] - '0');
            break;

        case 'D':
            x += (vector_string[1] - '0');
            break;

        case 'W':
            y += (vector_string[1] - '0');
            break;

        case 'S':
            y -= (vector_string[1] - '0');
            break;

        default:
            // cout << "[debug]: error in 'if(vector_string.size() == 2)' " << endl;
            break;
        }
    }
    else
    {
        if (vector_string[1] < '0' || vector_string[1] > '9' || vector_string[2] < '0' || vector_string[2] > '9')
        {
            return;
        }

        switch (vector_string[0])
        {
        case 'A':
            x -= (vector_string[1] - '0') * 10 + (vector_string[2] - '0');
            break;

        case 'D':
            x += (vector_string[1] - '0') * 10 + (vector_string[2] - '0');
            break;

        case 'W':
            y += (vector_string[1] - '0') * 10 + (vector_string[2] - '0');
            break;

        case 'S':
            y -= (vector_string[1] - '0') * 10 + (vector_string[2] - '0');
            break;

        default:
            // cout << "[debug]: error in 'if(vector_string.size() == 3)' " << endl;
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    int x = 0, y = 0;

    vector<char> vector_string;
    char ch;

    while (cin >> ch)
    {
        if (ch != ';')
        {
            vector_string.push_back(ch);
        }
        else
        {
            checkStringAndMove(vector_string, x, y);
            vector_string.clear();
        }
    }

    cout << x << "," << y << endl;

    return 0;
}
