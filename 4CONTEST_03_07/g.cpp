#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<vector<long long>> C(n + 1, vector<long long>(n + 1));

        for (int i = 0; i <= n; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        long long ans = 0;

        for (int y = 1; y <= n; y++) {
            long long cnt = 0;

            for (int c = 0; c <= (y - 1) / 2; c++) {
                int d = y - 1 - 2 * c;

                if (d <= n - y) {
                    cnt += C[y - 1][c] * C[n - y][d] % MOD;
                    if (cnt >= MOD)
                        cnt -= MOD;
                }
            }

            ans = (ans + cnt * y) % MOD;
        }

        for (int m = (n + 1) / 2; m <= n; m++) {
            ans = (ans + (2LL * m + 1) * C[n][m]) % MOD;
        }

        cout << ans << '\n';
    }

    return 0;
}
