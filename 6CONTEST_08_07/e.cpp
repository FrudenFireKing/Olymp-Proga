#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<long long> d(n);
    long long total = 0;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        total += d[i];
    }

    int N = 1 << n;
    vector<long long> deadSum(N, 0);
    for (int mask = 1; mask < N; mask++) {
        int b = __builtin_ctz(mask);
        deadSum[mask] = deadSum[mask ^ (1 << b)] + d[b];
    }

    vector<long long> alive(N);
    for (int mask = 0; mask < N; mask++)
        alive[mask] = total - deadSum[mask];

    vector<int> killMask(n);
    for (int i = 0; i < n; i++) {
        int m = 0;
        m |= 1 << i;
        m |= 1 << ((i + 2) % n);
        m |= 1 << ((i - 2 + n) % n);
        killMask[i] = m;
    }

    const long long INF = (1LL << 60);
    vector<long long> dp(N, INF);

    dp[N - 1] = 0;

    for (int mask = N - 2; mask >= 0; mask--) {
        for (int i = 0; i < n; i++) {
            int nxt = mask | killMask[i];
            dp[mask] = min(dp[mask], alive[nxt] + dp[nxt]);
        }
    }

    cout << dp[0] + 1 << '\n';
    return 0;
}
