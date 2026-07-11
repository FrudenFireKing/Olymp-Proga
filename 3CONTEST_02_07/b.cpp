#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int l, r;
    cin >> l >> r;

    const int MOD = 1e9 + 7;
    vector<long long> dp(r + 1, 0);
    dp[1] = 1;

    for (int i = 1; i <= r; ++i) {
        if (dp[i] == 0) continue;

        for (int j = 2 * i; j <= r; j += i) {
            dp[j] = (dp[j] + dp[i]) % MOD;
        }
    }

    long long result = 0;
    for (int i = l; i <= r; ++i) {
        result = (result + dp[i]) % MOD;
    }

    cout << result << endl;
    return 0;
}
