#include <iostream>
#include <string>

using namespace std;

typedef unsigned int uint;
const uint SIGMA_SIZE = 256;
const uint SECTION = 4, SUBSECT = 8;

inline int max(int a, int b)
{
    return a > b ? a : b;
}

void printStarLine(uint occ = 70)
{
    cout << endl << endl;
    for (uint _ = 1; _ <= occ; _++) cout << '+';
    cout << endl;
    for (uint _ = 1; _ <= occ; _++) cout << '+';
    cout << endl << endl << endl;
}

string printText(string txt, uint num)
{
    string res = "";
    while (num--) res += ' ';
    return res + txt;
}
