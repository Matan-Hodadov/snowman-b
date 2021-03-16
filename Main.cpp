  
#include <iostream>
#include "snowman.hpp"
#include <chrono>
#include <thread>

using namespace ariel;
using namespace std;

void sleep(int milli_sec)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milli_sec));
}

int main()
{
    int time = 500;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 3; j-i+1 > 0; j--)
        {
            cout << "\n" << endl;
        }
        cout << snowman(11112211) << endl;
        sleep(time);
        system("clear");

        for (int j = 3; j-i > 0; j--)
        {
            cout << "\n" << endl;
        }
        cout << snowman(11113311) << endl;
        sleep(time);
        system("clear");
    }
}

// void jumping_snowman()
// {
//     int time = 500;
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 3; j-i+1 > 0; j--)
//         {
//             cout << "\n" << endl;
//         }
//         cout << snowman(11112211) << endl;
//         sleep(time);
//         system("clear");

//         for (int j = 3; j-i > 0; j--)
//         {
//             cout << "\n" << endl;
//         }
//         cout << snowman(11113311) << endl;
//         sleep(time);
//         system("clear");
//     }
// }