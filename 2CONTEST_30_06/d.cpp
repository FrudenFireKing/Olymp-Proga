#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> z_function(const string& s) {
    int n = s.length();
    vector<int> z(n);

    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    string s;
    cin >> s;

    long long n = s.length();

    long long total = n * (n + 1) / 2;
    long long duplicates = 0;

    for (int i = 0; i < n; ++i) {
        string suffix = s.substr(i);
        vector<int> z = z_function(suffix);

        int max_z = 0;
        for (int val : z) {
            max_z = max(max_z, val);
        }
        duplicates += max_z;
    }

    cout << total - duplicates << endl;
    return 0;
}