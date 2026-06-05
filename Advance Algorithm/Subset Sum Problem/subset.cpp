#include <iostream>
#include <vector>

using namespace std;

bool subsetSum(int w[], int n, int S) {
    bool dp[n + 1][S + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int j = 1; j <= S; j++)
        dp[0][j] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= S; j++) {
            if (w[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - w[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][S];
}

int main() {
    int W[] = {2, 1, 4, 3};
    int S = 5;
    if (subsetSum(W, 4, S)) cout << "True" << endl;
    else cout << "False" << endl;
    return 0;
}