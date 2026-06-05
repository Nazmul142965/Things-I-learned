#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void bwt(string s) {
    int n = s.length();
    vector<string> rotations;
    for (int i = 0; i < n; i++) {
        rotations.push_back(s.substr(i) + s.substr(0, i));
    }
    sort(rotations.begin(), rotations.end());

    string res = "";
    for (int i = 0; i < n; i++) {
        res += rotations[i][n - 1];
    }
    cout << "Encoded sequence: " << res << endl;
}

int main() {
    bwt("hello@man");
    return 0;
}