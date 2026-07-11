#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    const long long NEG = -1e18;

    vector<vector<long long>> dp(n, vector<long long>(m, NEG));
    dp[0][0] = a[0][0];

    vector<pair<int,int>> moves = {
        {2, -1},
        {2, 1},
        {1, 2},
        {-1, 2}
    };

    long long ans = a[0][0];

    for (int s = 0; s <= n + m - 2; s++) {
        for (int i = 0; i < n; i++) {
            int j = s - i;
            if (j < 0 || j >= m)
                continue;

            if (dp[i][j] == NEG)
                continue;

            ans = max(ans, dp[i][j]);

            for (auto [di, dj] : moves) {
                int ni = i + di;
                int nj = j + dj;

                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    dp[ni][nj] = max(dp[ni][nj],
                                     dp[i][j] + a[ni][nj]);
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
