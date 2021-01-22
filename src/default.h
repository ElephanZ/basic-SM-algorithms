#include <iostream>
#include <string>

using namespace std;

using uint = unsigned int;
const uint SIGMA_SIZE = 256;
const short int SECTION = 4, SUBSECT = 8;

inline int max(const int a, const int b)
{
    return a > b ? a : b;
}

void printStarLine(const uint occ = 70)
{
    cout << endl << endl;
    for (uint _ = 1; _ <= occ; _++) cout << '*';
    cout << endl;
    for (uint _ = 1; _ <= occ; _++) cout << '*';
    cout << endl << endl << endl;
}

string printText(uint num, const string txt)
{
    string res = "";
    while (num--) res += ' ';
    return res + txt;
}
