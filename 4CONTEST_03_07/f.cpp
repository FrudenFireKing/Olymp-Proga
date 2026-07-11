#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> divs;
        for (int i = 1; i * 1LL * i <= x; i++) {
            if (x % i == 0) {
                divs.push_back(i);
                if (i * i != x)
                    divs.push_back(x / i);
            }
        }

        sort(divs.begin(), divs.end());

        unordered_map<int, int> id;
        for (int i = 0; i < (int)divs.size(); i++)
            id[divs[i]] = i;

        vector<int> a(n);
        for (int &v : a)
            cin >> v;

        int ans = 0;
        vector<char> have(divs.size());

        auto add = [&](int val) {
            bool good = false;

            if (x % val == 0) {
                vector<int> cur;
                for (int i = 0; i < (int)divs.size(); i++) {
                    if (have[i])
                        cur.push_back(divs[i]);
                }

                for (int p : cur) {
                    if (p * 1LL * val == x)
                        good = true;
                }

                if (!good) {
                    for (int p : cur) {
                        long long np = 1LL * p * val;
                        if (np <= x && x % np == 0) {
                            have[id[(int)np]] = 1;
                        }
                    }
                    if (val <= x && x % val == 0)
                        have[id[val]] = 1;
                }
            }

            return good;
        };

        have[id[1]] = 1;

        for (int v : a) {
            if (add(v)) {
                ans++;
                fill(have.begin(), have.end(), 0);
                have[id[1]] = 1;
                add(v);
            }
        }

        ans++;

        cout << ans << '\n';
    }

    return 0;
}
