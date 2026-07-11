#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<ll> dp(n + 1);

    dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1];

        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2]);

        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3]);

        dp[i] += i;
    }

    cout << dp[n] << '\n';

    return 0;
}
