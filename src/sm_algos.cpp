#include "default.h"

#include "bf.h"
#include "bm.h"
#include "hor.h"
#include "kmp.h"
#include "rk.h"

int main()
{
    string functionNames[] { "Naive o BruteForce", "Boyer-Moore", "Horspool", "Knuth-Morris-Pratt", "Rabin-Karp" };
    uint(*searchFunction[])(string, uint, string, uint) { bruteForce, boyerMoore, horspool, knuthMorrisPratt, rabinKarp };

    string t = "", p = "";
    uint n = 0, m = 0;

    printStarLine();
    cout << printText("DATA INPUT: ", SECTION);

    do
    {
        cout << endl << printText("Write the text T: ", SUBSECT);
        getline(cin, t);
        cout << printText("Write the pattern P: ", SUBSECT);
        getline(cin, p);

        n = t.length(), m = p.length();
    }
    while (n <= 1 || m <= 1 || m > n);

    cout << endl << printText("NUMBER OF OCCURRENCES FOUND: ", SECTION) << endl;
    for (uint _ = 0; _ < 5; _++)
        cout << printText(functionNames[_] + " algorithm: " + to_string((*searchFunction[_])(t, n, p, m)), SUBSECT) << endl;

    printStarLine();

    return 0;
}
