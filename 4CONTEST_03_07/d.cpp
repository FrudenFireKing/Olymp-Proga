#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;

        string a;
        cin >> a;

        // добавляем правый берег
        a = "L" + a + "L";

        const int INF = 1e9;

        vector<int> dp(n + 2, INF);
        dp[0] = 0;

        for (int i = 0; i <= n; i++) {
            if (dp[i] > k)
                continue;

            // прыжок с берега или бревна
            if (a[i] == 'L') {
                for (int j = 1; j <= m; j++) {
                    int to = i + j;
                    if (to <= n + 1 && a[to] != 'C') {
                        dp[to] = min(dp[to], dp[i]);
                    }
                }
            }

            // плавание из воды
            if (a[i] == 'W') {
                if (i + 1 <= n + 1) {
                    dp[i + 1] = min(dp[i + 1], dp[i] + 1);
                }
            }
        }

        cout << (dp[n + 1] <= k ? "YES" : "NO") << '\n';
    }

    return 0;
}
