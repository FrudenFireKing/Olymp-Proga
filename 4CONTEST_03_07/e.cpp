#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<pair<int,int>> ans;

        int d = to_string(n).size();

        if (n == 1) {
            for (int a = 2; a <= 10000; a++) {
                ans.push_back({a, a - 1});
            }
        } else {
            int c = n - d;
            long long limit = 10000LL * c;

            string s = to_string(n);

            long long pref = 0;

            for (int L = 1; ; L++) {
                pref = pref * 10 + (s[(L - 1) % d] - '0');

                if (pref - L > limit)
                    break;

                long long diff = pref - L;

                if (diff > 0 && diff % c == 0) {
                    long long a = diff / c;

                    if (1 <= a && a <= 10000) {
                        long long b = a * d - L;

                        if (b >= 1 &&
                            b <= 10000 &&
                            b <= a * n) {
                            ans.push_back({(int)a, (int)b});
                        }
                    }
                }
            }
        }

        cout << ans.size() << '\n';
        for (auto [a, b] : ans) {
            cout << a << ' ' << b << '\n';
        }
    }

    return 0;
}
