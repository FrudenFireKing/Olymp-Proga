#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    unordered_set<int> dangerous;
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        dangerous.insert(a);
    }

    const int MOD = 1e9 + 7;
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        if (dangerous.find(i) != dangerous.end()) {
            dp[i] = 0;
        } else {
            for (int j = 1; j <= k; ++j) {
                if (i - j >= 0) {
                    dp[i] = (dp[i] + dp[i - j]) % MOD;
                }
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}
