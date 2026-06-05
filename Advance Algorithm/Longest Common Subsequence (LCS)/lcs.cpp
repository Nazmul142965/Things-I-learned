#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int lcs(string x, string y) {
    int m = x.length();
    int n = y.length();
    int c[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) c[i][j] = 0;
            else if (x[i - 1] == y[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = max(c[i][j - 1], c[i - 1][j]);
        }
    }
    return c[m][n];
}

int main() {
    cout << lcs("EABCD", "BACDE") << endl;
    return 0;
}