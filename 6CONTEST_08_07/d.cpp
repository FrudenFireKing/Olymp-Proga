#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c[i][j];
        }
    }

    vector<vector<ll>> dp(1 << n, vector<ll>(n, 0));

    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = 1;
    }

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int last = 0; last < n; ++last) {
            if (dp[mask][last] == 0) continue;
            for (int next = 0; next < n; ++next) {
                if (!(mask & (1 << next)) && c[last][next]) {
                    dp[mask | (1 << next)][next] += dp[mask][last];
                }
            }
        }
    }

    ll total_ways = 0;
    int full_mask = (1 << n) - 1;
    for (int i = 0; i < n; ++i) {
        total_ways += dp[full_mask][i];
    }

    cout << total_ways << endl;

    return 0;
}
