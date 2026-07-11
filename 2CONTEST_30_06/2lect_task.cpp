#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;


void z_function(const string &s, vector<int> &z) {
    int n = s.size();
    z.resize(n, 0);
    z[0] = n;
    int l = -1, r = -1;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
}

int main() {
    string s;
    cin >> s;

    vector<int> z;
    z_function(s, z);

    for (auto i : z) {
        cout << i << " ";
    }
    cout << endl;   
    return 0;
}