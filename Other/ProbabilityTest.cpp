#include <iostream>
#include <random>

using namespace std;

int main(int argc, char const *argv[])
{
    int GuessList[3] = {0};
    int Awin = 0;
    int Bwin = 0;

    random_device seed;
    ranlux48 engine(seed());
    uniform_int_distribution<> distrib(0, 2);

    for (int i = 0; i < 10000; i++)
    {
        // for (int clear : GuessList)
        // {
        //     clear = 0;
        // }

        for (int j = 0; j < 3; j++)
            GuessList[j] = 0;

        // GuessList[0] = 0;
        // GuessList[1] = 0;
        // GuessList[2] = 0;

        GuessList[distrib(engine)] = 1;

        Awin += GuessList[0] + GuessList[1];
        Bwin += GuessList[2];
    }
    cout << "Awin: " << Awin << "\nBwin: " << Bwin << endl;

    system("pause");

    return 0;
}
