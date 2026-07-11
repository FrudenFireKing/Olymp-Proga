#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> dp(max(112, n + 1));

    dp[1] = 1;
    if (n >= 2) dp[2] = 1;
    if (n >= 3) dp[3] = 2;

    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 3] + 1;
    }

    cout << dp[n] << '\n';

    return 0;
}
