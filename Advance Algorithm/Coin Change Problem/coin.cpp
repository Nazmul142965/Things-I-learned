#include <iostream>
#include <vector>

using namespace std;

int countWays(int c[], int c_length, int amount) {
    int solution[c_length][amount + 1];

    for (int i = 0; i < c_length; i++) {
        for (int j = 0; j <= amount; j++) {
            if (i == 0 && j == 0) {
                solution[i][j] = 1;
            } else {
                if (c[i] > j) {
                    if (i == 0) solution[i][j] = 0;
                    else solution[i][j] = solution[i - 1][j];
                } else {
                    int exclude = (i > 0) ? solution[i - 1][j] : 0;
                    int include = solution[i][j - c[i]];
                    solution[i][j] = exclude + include;
                }
            }
        }
    }
    return solution[c_length - 1][amount];
}

int main() {
    int coins[] = {1, 3, 5};
    int amount = 8;
    cout << countWays(coins, 3, amount) << endl;
    return 0;
}