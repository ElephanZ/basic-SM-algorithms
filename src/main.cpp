#include "default.h"

#include "bf.h"
#include "bm.h"
#include "hor.h"
#include "kmp.h"
#include "rk.h"

int main()
{
    string functionNames[] { "Naive", "Boyer-Moore", "Horspool", "Knuth-Morris-Pratt", "Rabin-Karp" };
    uint(*searchFunction[])(string, uint, string, uint) { bruteForce, boyerMoore, horspool, knuthMorrisPratt, rabinKarp };

    string t = "", p = "";
    uint n = 0, m = 0;

    printStarLine();
    cout << printText(SECTION, "DATA INPUT: ");

    do
    {
        cout << endl << printText(SUBSECT, "Write the text T: ");
        getline(cin, t);
        cout << printText(SUBSECT, "Write the pattern P: ");
        getline(cin, p);

        n = t.length(), m = p.length();
    }
    while (n <= 1 || m <= 1 || m > n);

    cout << endl << printText(SECTION, "NUMBER OF OCCURRENCES FOUND: ") << endl;
    for (uint _ = 0; _ < 5; _++)
        cout << printText(SUBSECT, functionNames[_] + " algorithm: " + to_string((*searchFunction[_])(t, n, p, m))) << endl;

    printStarLine();

    return 0;
}
