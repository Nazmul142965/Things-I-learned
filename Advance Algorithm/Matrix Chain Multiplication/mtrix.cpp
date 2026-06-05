#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void matrixChainOrder(int d[], int n) {
    int m[n][n];
    int s[n][n];

    for (int i = 1; i < n; i++) m[i][i] = 0;

    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << "Minimum Cost: " << m[1][n - 1] << endl;
}

int main() {
    int d[] = {4, 2, 3, 1, 3};
    matrixChainOrder(d, 5);
    return 0;
}