#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool achieve(int n, int k, string s) {
    int operations = 0;
    vector<int> flipped(n + 1, 0);

    for (int i = 0; i <= n - k; ++i) {
        int cur = (s[i] - '0');
        if ((cur + operations) % 2 == 0) {
            operations ++;
            flipped[i + k] = 1;
        }
        operations -= flipped[i + 1];
    }
    
    for (int i = n - k + 1; i < n; ++i) {
        if((s[i] - '0' + operations) % 2 == 0) return false;
        operations -= flipped[i + 1];
    }

    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        for (int k = n; k >= 1; --k) {
            if (achieve(n, k, s)) {
                cout << k << endl;
                break;
            }
        }
    }

    return 0;
}