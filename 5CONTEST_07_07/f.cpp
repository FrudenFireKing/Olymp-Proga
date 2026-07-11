#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long modpow(long long a, long long b) {
    long long r = 1;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    int sum = 0;
    for (int &v : a) {
        cin >> v;
        sum += v;
    }

    int m = sum - x;

    // factorials for combinations
    int N = n + m + 5;
    vector<long long> fact(N), invfact(N);
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invfact[N - 1] = modpow(fact[N - 1], MOD - 2);
    for (int i = N - 1; i > 0; i--)
        invfact[i - 1] = invfact[i] * i % MOD;

    auto C = [&](int n, int k) -> long long {
        if (k < 0 || k > n) return 0;
        return fact[n] * invfact[k] % MOD * invfact[n-k] % MOD;
    };

    // numerator: product(1 - z^ai)
    vector<long long> dp(m + 1);
    dp[0] = 1;

    for (int v : a) {
        for (int i = m - v; i >= 0; i--) {
            dp[i + v] -= dp[i];
            if (dp[i + v] < 0)
                dp[i + v] += MOD;
        }
    }

    long long ans = 0;
    for (int j = 0; j <= m; j++) {
        // coefficient of z^(m-j) in (1-z)^(-(n+1))
        long long cur = C(n + m - j, n);
        ans += dp[j] * cur % MOD;
        if (ans >= MOD)
            ans -= MOD;
    }

    // divide by product(ai)
    long long den = 1;
    for (int v : a)
        den = den * v % MOD;

    ans = ans * modpow(den, MOD - 2) % MOD;

    cout << ans << '\n';

    return 0;
}
