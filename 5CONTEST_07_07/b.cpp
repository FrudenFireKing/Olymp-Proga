#include <iostream>
#include <vector>
 
using namespace std;
 
const long long MOD = 1e9 + 7;
 
int main() {
    int n, k;
    cin >> n >> k;
 
    vector<long long> dp(n + 1);
    dp[0] = 1;
 
    long long cur_sum = 1;
 
    for (int i = 1; i <= n; i++) {
        dp[i] = cur_sum % MOD;
 
        cur_sum = (cur_sum + dp[i]) % MOD;
 
        if (i - k >= 0) {
            cur_sum = (cur_sum - dp[i - k] + MOD) % MOD;
        }
    }
 
    cout << dp[n] << '\n';
}
