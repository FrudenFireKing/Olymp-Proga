#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 9;
const ll P = 31;

vector<ll> precompute_powers(int n) {
    vector<ll> pows(n + 1);
    pows[0] = 1;
    for (int i = 1; i <= n; i++) {
        pows[i] = (pows[i - 1] * P) % MOD;
    }
    return pows;
}

vector<ll> compute_hashes(const string& s, int n) {
    vector<ll> h(n + 1, 0);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] * P + (s[i] - 'a' + 1)) % MOD;
    }
    return h;
}

ll get_hash(const vector<ll>& h, const vector<ll>& pows, int L, int R) {
    ll res = (h[R + 1] - h[L] * pows[R - L + 1]) % MOD;
    if (res < 0) res += MOD;
    return res;
}

int main() {
    string s;
    if (!(cin >> s)) return 0;
    int n = s.length();

    string s_rev = s;
    reverse(s_rev.begin(), s_rev.end());

    vector<ll> pows = precompute_powers(n);
    vector<ll> h = compute_hashes(s, n);
    vector<ll> hr = compute_hashes(s_rev, n);

    int max_pal = 0;
    for (int i = 1; i <= n; i++) {
        if (get_hash(h, pows, 0, i - 1) == get_hash(hr, pows, n - i, n - 1)) {
            max_pal = i;
        }
    }

    cout << max_pal << endl;
    return 0;
}