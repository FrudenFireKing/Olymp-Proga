#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
    }

    vector<vector<int>> dp(1 << n, vector<int>(n, INF));

    dp[1 << 0][0] = 0;

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int last = 0; last < n; ++last) {
            if (dp[mask][last] == INF) continue;
            for (int next = 0; next < n; ++next) {
                if (!(mask & (1 << next))) {
                    int next_mask = mask | (1 << next);
                    dp[next_mask][next] = min(dp[next_mask][next], dp[mask][last] + cost[last][next]);
                }
            }
        }
    }

    int ans = INF;
    int full_mask = (1 << n) - 1;
    for (int i = 1; i < n; ++i) {
        ans = min(ans, dp[full_mask][i] + cost[i][0]);
    }
    if (n == 1) ans = 0;

    cout << ans << endl;

    return 0;
}
