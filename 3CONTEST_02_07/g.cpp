#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int getMask(int x) {
    int mask = 0;
    while (x > 0) {
        mask |= 1 << (x % 10);
        x /= 10;
    }
    return mask;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    const int M = 1 << 10;

    vector<long long> cnt(M);

    for (int i = 1; i <= k; i++) {
        cnt[getMask(i)]++;
    }

    vector<long long> dp = cnt;

    for (int len = 1; len < n; len++) {
        vector<long long> sum = dp;

        // SOS DP:
        // sum[m] = сумма dp[sub] для всех sub ⊆ m
        for (int bit = 0; bit < 10; bit++) {
            for (int mask = 0; mask < M; mask++) {
                if (mask & (1 << bit)) {
                    sum[mask] += sum[mask ^ (1 << bit)];
                    if (sum[mask] >= MOD)
                        sum[mask] -= MOD;
                }
            }
        }

        vector<long long> ndp(M);

        for (int mask = 0; mask < M; mask++) {
            // все предыдущие маски должны быть подмножествами дополнения mask
            ndp[mask] = cnt[mask] * sum[(M - 1) ^ mask] % MOD;
        }

        dp = ndp;
    }

    long long ans = 0;
    for (long long x : dp) {
        ans += x;
        if (ans >= MOD)
            ans -= MOD;
    }

    cout << ans << '\n';

    return 0;
}
