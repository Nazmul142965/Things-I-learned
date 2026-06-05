#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void stableMarriage() {
    // 0:A, 1:B, 2:C, 3:D | 0:X, 1:Y, 2:Z, 3:W
    int mPref[4][4] = {{1, 3, 0, 2}, {3, 0, 1, 2}, {1, 2, 3, 0}, {1, 2, 3, 0}};
    int wPref[4][4] = {{1, 2, 0, 3}, {2, 3, 1, 0}, {2, 1, 0, 3}, {2, 1, 3, 0}};

    int wPartner[4] = {-1, -1, -1, -1};
    bool mFree[4] = {true, true, true, true};
    int freeCount = 4;

    while (freeCount > 0) {
        int m;
        for (m = 0; m < 4; m++) if (mFree[m]) break;

        for (int i = 0; i < 4 && mFree[m]; i++) {
            int w = mPref[m][i];
            if (wPartner[w] == -1) {
                wPartner[w] = m;
                mFree[m] = false;
                freeCount--;
            } else {
                int m1 = wPartner[w];
                bool prefersMOverM1 = false;
                for(int k=0; k<4; k++) {
                    if(wPref[w][k] == m) { prefersMOverM1 = true; break; }
                    if(wPref[w][k] == m1) break;
                }
                if (prefersMOverM1) {
                    wPartner[w] = m;
                    mFree[m] = false;
                    mFree[m1] = true;
                }
            }
        }
    }
    char women[] = {'X', 'Y', 'Z', 'W'};
    char men[] = {'A', 'B', 'C', 'D'};
    for (int i = 0; i < 4; i++) cout << women[i] << " - " << men[wPartner[i]] << endl;
}

int main() {
    stableMarriage();
    return 0;
}