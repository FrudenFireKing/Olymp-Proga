#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> c(n, vector<int>(m + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> c[i][j];
        }
    }

    vector<int> dp(m + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int w = m; w >= 0; --w) {
            int max_profit = dp[w];
            
            for (int j = 1; j <= w; ++j) {
                max_profit = max(max_profit, dp[w - j] + c[i][j]);
            }
            dp[w] = max_profit;
        }
    }

    cout << dp[m] << "\n";
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
