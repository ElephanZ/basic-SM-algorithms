#include "default.h"

#include "bf.h"
#include "bm.h"
#include "hor.h"
#include "kmp.h"
#include "rk.h"

int main()
{
    uint (*searchFunction[])(string, size_t, string, size_t) {bruteForce, boyerMoore, horspool, knuthMorrisPratt, rabinKarp};
    string functionNames[] {"Naive o BruteForce", "Boyer-Moore", "Horspool", "Knuth-Morris-Pratt", "Rabin-Karp"};

    string t = "", p = "";
    size_t n = 0, m = 0;

    printStarLine(70);
    cout << endl << printText("DATA INPUT: ", 4);

    do
    {
        cout << endl << printText("Write the text T (without spaces): ", 7);
        cin >> t;
        cout << printText("Write the pattern P (without spaces): ", 7);
        cin >> p;
    }
    while ((n = t.length()) <= 1 || (m = p.length()) <= 1 || m > n);

    cout << endl << printText("NUMBER OF OCCURRENCES FOUND: ", 4) << endl;
    for (size_t _ = 0; _ < 5; _++)
        cout << printText(functionNames[_] + " Algorithm: " + to_string((*searchFunction[_])(t, n, p, m)) + " occurrences.", 7) << endl;

    printStarLine(70);
    cout << endl;

    return 0;
}

