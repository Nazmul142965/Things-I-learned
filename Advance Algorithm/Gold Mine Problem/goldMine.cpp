#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getGold(vector<vector<int>> gold, int n, int m) {
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = m - 1; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            int right = (j == m - 1) ? 0 : dp[i][j + 1];
            int right_up = (i == 0 || j == m - 1) ? 0 : dp[i - 1][j + 1];
            int right_down = (i == n - 1 || j == m - 1) ? 0 : dp[i + 1][j + 1];

            dp[i][j] = gold[i][j] + max({right, right_up, right_down});
        }
    }

    int res = dp[0][0];
    for (int i = 1; i < n; i++) res = max(res, dp[i][0]);
    return res;
}

int main() {
    vector<vector<int>> gold = {{1, 5, 12}, {2, 4, 4}, {0, 6, 4}, {3, 0, 0}};
    cout << getGold(gold, 4, 3) << endl;
    return 0;
}