#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    int t;
    cin >> t;

    vector<pair<int,int>> q(t);

    int maxN = 0, maxS = 0;

    for (auto &[N, S] : q) {
        cin >> N >> S;
        maxN = max(maxN, N);
        maxS = max(maxS, S);
    }

    vector<vector<long long>> dp(maxN + 1, vector<long long>(maxS + 1));

    dp[0][0] = 1;

    for (int i = 0; i < maxN; i++) {
        for (int sum = 0; sum <= maxS; sum++) {
            if (dp[i][sum] == 0)
                continue;

            for (int d = 0; d <= 9; d++) {
                if (sum + d <= maxS) {
                    dp[i+1][sum+d] += dp[i][sum];
                    if (dp[i+1][sum+d] >= MOD)
                        dp[i+1][sum+d] -= MOD;
                }
            }
        }
    }

    for (auto [N, S] : q) {
        if (S > maxS) {
            cout << 0 << '\n';
        } else {
            cout << dp[N][S] << '\n';
        }
    }

    return 0;
}
