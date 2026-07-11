#include <bits/stdc++.h>
using namespace std;
 
vector<int> z_function(const string &s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
 
    for (int i = 1; i < n; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
 
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
 
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
 
int main() {
    string s;
    cin >> s;
 
    int n = s.size();
 
    long long best = 0;
    string ans;
 
    for (int st = 0; st < n; st++) {
        string cur = s.substr(st);
        int m = cur.size();
 
        vector<int> z = z_function(cur);
 
        vector<int> cnt(m + 1, 0);
 
        for (int x : z)
            cnt[x]++;
 
        for (int i = m - 1; i >= 1; i--)
            cnt[i] += cnt[i + 1];
 
        for (int len = 1; len <= m; len++) {
            long long occ = cnt[len] + 1;
            long long val = occ * len;
 
            if (val > best) {
                best = val;
                ans = cur.substr(0, len);
            }
        }
    }
 
    cout << ans << '\n';
}
