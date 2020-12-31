#include <bits/stdc++.h>
using namespace std;

const size_t SIGMA_SIZE = 256;

inline int max(int a, int b)
{
    return a > b ? a : b;
}

void printStarLine(uint occ)
{
    cout << endl << endl;
    for (size_t _ = 1; _ <= occ; _++) cout << '+';
    cout << endl;
    for (size_t _ = 1; _ <= occ; _++) cout << '+';
    cout << endl << endl;
}

string printText(string txt, uint num)
{
    string res = "";
    while (num--) res += ' ';
    return res + txt;
}

